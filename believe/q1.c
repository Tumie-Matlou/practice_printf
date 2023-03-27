#include "main.h" /* Defines prototype for the printf_ function*/
#include <stdio.h>
#include <stdarg.h> /* Defines variable argument list macros */

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format); /* initialize variable argument list */

    int num_chars = 0; /* keep track of number of characters printed */
    char c; /* character currently being processed */

    while ((c = *format++) != '\0') { /* iterate over format string */

        if (c == '%') { // handle conversion specifier
            char spec = *format++; /* get specifier character */

            if (spec == 'c') { // handle %c specifier
                putchar(va_arg(args, int)); /* print character argument */
                num_chars++;
            } else if (spec == 's') { // handle %s specifier
                num_chars += printf(va_arg(args, char*)); /* print string argument */
            } else if (spec == '%') { // handle %% specifier
                putchar('%'); /* print literal % character */
                num_chars++;
            } else if (spec == 'd' || spec == 'i') { // handle %d or %i specifier
                int arg = va_arg(args, int); /* get integer argument */
                num_chars += printf("%d", arg); /* print integer argument */
            } else {
                // unrecognized conversion specifier, skip it
            }
        } else { // handle regular character
            putchar(c); /* print regular character */
            num_chars++;
        }
    }

    va_end(args); // clean up variable argument list
    return num_chars;
}

