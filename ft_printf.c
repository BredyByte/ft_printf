/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:03:46 by dbredykh          #+#    #+#             */
/*   Updated: 2023/05/10 21:23:22 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_types(const char *str, va_list param)
{
	int	count;

	if (*str == 'c')
		count += ft_putchar(va_arg(param, int));
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	param;
	int		count;

	count = 0;
	va_start(param, str);
	while (*str)
	{
		if (*str != '%')
			count += ft_putchar(*str);
		else
		{
			str++;
			count += ft_types(str, param);
		}
		str++;
	}
	va_end(param);
	return (count);
}

int	main(void)
{
	ft_printf("hello %c", '?');
	return (0);
}
