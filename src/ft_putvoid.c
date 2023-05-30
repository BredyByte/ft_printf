/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:31:01 by dbredykh          #+#    #+#             */
/*   Updated: 2023/05/14 12:25:15 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvoid(void *p)
{
	int	c;

	c = 0;
	c += ft_putstr("0x");
	c += ft_puthexa((unsigned long long)p, 'x');
	return (c);
}
