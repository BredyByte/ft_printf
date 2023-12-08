#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


void putstr(char *str, int *count)
{
	if (!str)
		str = "(null)";
	while (*str)
		*count += write(1, str++, 1);
}

void putbase(long long int n, int base, int *count)
{
	if (n < 0)
	{
		*count += write(1, "-", 1);
		n *= -1;
	}
	if (n >= base)
		putbase(n / base, base, count);
	*count += write(1, &"0123456789abcdef"[n % base], 1);
}

int	ft_printf(const char *str, ...)
{
	int		count = 0;
	va_list	param;

	va_start(param, str);
	while (*str)
	{
		if ((*str == '%') && ((*(str + 1) == 'd') || (*(str + 1) == 'x') || (*(str + 1) == 's')))
		{
			str++;
			if (*str == 'd')
				putbase((long long int)va_arg(param, int), 10, &count);
			else if (*str == 'x')
				putbase((long long int)va_arg(param, unsigned int), 16, &count);
			else if (*str == 's')
				putstr(va_arg(param, char *), &count);
		}
		else
			count += write(1, str, 1);
		str++;
	}
	return (va_end(param), count);
}

int	main()
{
	printf("%d\n", ft_printf("Hexadecimal for num: %d is hex: %x\n string: %s",
			42, 42, "String"));
	return (0);
}

