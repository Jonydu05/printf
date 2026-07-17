*This project has been created as part of the 42 curriculum by jzampier*

## Description

`ft_printf` is a recreation of the standard C library function `printf`, implemented
as a small static library (`libftprintf.a`). The goal of the project is to understand,
from the inside out, how a variadic function works and how format strings are parsed
and converted into output written to `stdout`.

The library exposes a single public function, `ft_printf`, which mimics the behavior
of the original `printf` for the following conversions:

| Conversion | Meaning                          |
|------------|-----------------------------------|
| `%c`       | Single character                 |
| `%s`       | String                           |
| `%p`       | Pointer address (hexadecimal)    |
| `%d` / `%i`| Signed decimal integer           |
| `%u`       | Unsigned decimal integer         |
| `%x`       | Unsigned hexadecimal (lowercase) |
| `%X`       | Unsigned hexadecimal (uppercase) |
| `%%`       | A literal `%` character          |

Flags, width, and precision modifiers (e.g. `%10.2f`, `%-5d`) are **not** part of the
subject and are therefore not implemented. Any conversion character not listed above
is simply ignored (nothing is printed for it, and it does not count toward the return
value).

Like the original `printf`, `ft_printf` returns the total number of characters
written to `stdout`, or `-1` if the format string itself is `NULL`.

## Instructions

### Project structure

```
.
├── Makefile
├── README.md
└── src
    ├── do_check.c
    ├── ft_printf.c
    ├── ft_printf.h
    └── handle_put.c
```

### Compilation

The project is compiled into a static library using the provided `Makefile`:

```bash
make        # compiles the sources and creates libftprintf.a
make clean  # removes the object files
make fclean # removes the object files and the library
make re     # fclean + all
```

The library is compiled with `-Wall -Wextra -Werror`, so it builds without any
warnings or errors.

### Usage

To use `ft_printf` in your own project, compile the library and link it, then
include the header:

```bash
cc your_file.c -L. -lftprintf -o your_program
```

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello, %s! You are %d years old.\n", "42", 21);
    ft_printf("Characters written: %d\n", len);
    return (0);
}
```

## Technical choices

### Structure

The implementation is split into three files, following the 42 Norme constraints
(max 25 lines per function, max 5 functions per file, max 4 parameters per function):

- **`ft_printf.c`** — the entry point. It walks through the format string
  character by character. On a literal character it writes it directly; on a `%`
  it hands the next character off to `do_check`.
- **`do_check.c`** — a dispatcher. It looks at the conversion character and calls
  the matching `ft_put*` helper with the correctly-typed argument pulled from the
  `va_list`.
- **`handle_put.c`** — the actual "printing" primitives: `ft_putchar`, `ft_putstr`,
  `ft_putnbr`, `ft_puthex`, and `ft_putptr`.

### Why `va_list`

`ft_printf` needs to accept an arbitrary, unknown-at-compile-time number of
arguments of different types, exactly like the original `printf`. C's variadic
mechanism (`<stdarg.h>`) is the only standard tool for this: `va_start` opens the
list right after the last named parameter (`str`), `va_arg` reads one argument at
a time with an explicit type, and `va_end` closes it. The `va_list` itself is
passed by pointer (`va_list *args`) from `ft_printf` to `do_check`, so that
`va_arg` calls made deeper in the call chain still advance the *same* list instead
of a local copy — on some platforms `va_list` is an array type and behaves like a
pointer already, but passing it explicitly by address keeps the behavior portable
and predictable.

### Why recursion for `ft_putnbr` / `ft_puthex`

Numbers are naturally described "backwards": the last digit of `n` is
`n % base`, and the rest of the number is `n / base`. Recursion lets the digits be
computed in the natural top-to-bottom order simply by recursing on `n / base`
*before* printing `n % base` — the call stack does the job of reversing the digit
order for us, without needing a temporary buffer or array to build the string in
reverse and then flip it. This keeps the functions short (fits the Norme line
limit) and avoids manual buffer management, at the cost of a small, bounded amount
of stack usage (at most ~20 recursive calls for a 64-bit number in base 10, or ~16
in base 16).

`ft_puthex` reuses this same recursive pattern for both `%x` and `%X` by taking
the digit alphabet (`"0123456789abcdef"` or `"0123456789ABCDEF"`) as a parameter,
avoiding duplicated logic between the two conversions.

### Edge cases handled

- `ft_printf(NULL, ...)` returns `-1` immediately.
- `%s` with a `NULL` argument prints `(null)`, matching common `printf`
  implementations' behavior (the C standard itself leaves this undefined).
- `%p` with a `NULL` pointer prints `(nil)`.
- `INT_MIN` (`-2147483648`) is handled correctly in `ft_putnbr` by working with a
  `long` internally, so negating the value does not overflow.
- An unrecognized character after `%` is ignored, and no return-value count is
  added for it.

## Resources

- [The C Programming Language (K&R)](https://en.wikipedia.org/wiki/The_C_Programming_Language) — background on standard I/O and formatted output.
- [`man 3 printf`](https://man7.org/linux/man-pages/man3/printf.3.html) — reference for the original function's behavior and conversion specifiers.
- [`man 3 stdarg`](https://man7.org/linux/man-pages/man3/stdarg.3.html) — documentation of `va_start`, `va_arg`, `va_end` and variadic functions in C.
- [42 Norme](https://github.com/42School/norminette) — coding style rules the project must comply with.

### AI usage

An AI assistant (Claude) was used during this project in the following limited ways:

- To clarify conceptual doubts about how `va_list` and variadic functions work in C.
- To help debug a single specific bug: a missing address-of operator (`&`) when
  calling `ft_putptr`.
- To help write this README file.

No code was generated or written by AI; all functions in `src/` were written by
the author.