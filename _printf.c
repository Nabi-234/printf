#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // To keep track of the number of characters printed
    char c;

    while (*format) {
        if (*format == '%') {
            format++; // Move past the '%'
            switch (*format) {
                case 'c':
                    c = va_arg(args, int); // Fetch a character argument
                    putchar(c);
                    count++;
                    break;
                case 's':
                    {
                        char *str = va_arg(args, char *); // Fetch a string argument
                        while (*str) {
                            putchar(*str);
                            str++;
                            count++;
                        }
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

int main() {
    _printf("Hello, %s! The character is %c and this is a percent sign: %%\n", "world", 'A');
    return 0;
}
