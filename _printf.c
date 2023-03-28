#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...) {
    int i, x, printed_chars = 0;
    va_list list;
    char *s;

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
		va_arg(list, int);
            } else if (format[i] == 's' || format[i] == '%' ) {
                s = va_arg(list, char*);

                while (*(s) != '\0') {
                    printed_chars += 1;
                    s++;
                }
            }else if (format[i] == 'd'){
	    	x = va_arg(list, int);
		while (x > 0){
			x /= 10;
			printed_chars++;
	    	}
	    }
	    else {
                printed_chars += 2;
            }
        }
    }

    va_end(list);

    return (printed_chars);
}
