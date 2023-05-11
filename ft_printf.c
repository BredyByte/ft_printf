/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:03:46 by dbredykh          #+#    #+#             */
/*   Updated: 2023/05/11 17:51:46 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_types(const char *str, size_t i, va_list param)
{
	size_t	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_putchar(va_arg(param, int));
	else if (str[i] == 's')
		count += ft_putstr(va_arg(param, char *));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	count;
	va_list	param;

	va_start(param, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_putchar(str[i]);
		else
		{
			i++;
			count += ft_types(str, i, param);
		}
		i++;
	}
	va_end(param);
	return ((int)count);
}
