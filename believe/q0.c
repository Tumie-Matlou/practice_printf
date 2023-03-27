#include "main.h" /* Defines prototype for the printf_ function*/
#include <stdio.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format); /* initialize variable argument list */

    int num_chars = 0;/* Introducting variable num_char */
    char c;/* Introducting variable c */

    while ((c = *format++) != '\0') { /* iterate over format string */

        if (c == '%') { // handle conversion specifier
            char spec = *format++;

            if (spec == 'c') {
                putchar(va_arg(args, int));
                num_chars++;
            } else if (spec == 's') {
                num_chars += printf(va_arg(args, char*));
            } else if (spec == '%') {
                putchar('%');
                num_chars++;
            } else {
                // unrecognized conversion specifier, skip it
            }
        } else { // handle regular character
            putchar(c);
            num_chars++;
        }
    }

    va_end(args); // clean up variable argument list
    return num_chars;
}

