#include "main.h"
/**
 * heyyyyyyy
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...) {
    int i, x, printed_chars = 0;
    unsigned int ui;
    va_list list;
    char *s, c;

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
	    if (format[i] == '\\'){
	    	++i;
		if (format[i] == 'n'){
			printed_chars++;
			printf("\n");
		}
	    	else{ 
			printed_chars += 2;		
			printf("\\%c", format[i]);
			    
		}
	    }
            else{
	        _putchar(format[i]);
                printed_chars++;
	}
	}
        else {
            ++i;
            if (format[i] == 'c') {
                printed_chars += 1;
		c = va_arg(list, int);
		_putchar(c);
            }else if (format[i] == '%'){
	    	printed_chars++;
		_putchar('%');
	    } 
	    else if (format[i] == 's') {
                s = va_arg(list, char*);
		printf("%s", s);
                while (*(s) != '\0') {
                    printed_chars += 1;
                    s++;
                }
            }else if (format[i] == 'b'){
	    	turn_to_bin(va_arg(list, int));
	    }
	    else if (format[i] == 'd' || format[i] == 'i'){
	    	x = va_arg(list, int);
		printf("%d", x);
		if (x == 0)
			printed_chars++;
		if (x < 0)
			printed_chars++;
		while (x != 0){
			x /= 10;
			printed_chars++;
	    	}
	    }
	    else if (format[i] == 'u'){
	    	ui = va_arg(list, unsigned int);
		printf("%u", ui);
		while (ui > 0){
			ui /= 10;
			printed_chars++;
		}
	    }
	    else if (format [i] == 'o'){
		    ui = va_arg(list, unsigned int);
		    printf("%o", ui);
		    while(ui > 0){
			    ui /= 10;
			    printed_chars++;
		    }
	    }
	    else {
		printf("%%");
		_putchar(format[i]);
                printed_chars += 2;
            }
        }
    }

    va_end(list);

    return (printed_chars);
}
