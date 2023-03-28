#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...) {
    int i, printed_chars = 0;
    va_list list;

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            printed_chars++;
        } else {
            ++i;
            if (format[i] == 'c') {
                printed_chars += 1;
                char c = va_arg(list, int);
            } else if (format[i] == 's') {
                char *c = va_arg(list, char*);

                while (*(c) != '\0') {
                    printed_chars += 1;
                    c++;
                }
            } else {
                printed_chars++;
            }
        }
    }

    va_end(list);

    return (printed_chars);
}
