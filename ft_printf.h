/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:12:49 by dbredykh          #+#    #+#             */
/*   Updated: 2023/05/11 20:53:06 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
size_t	ft_putstr(char *str);
size_t	ft_putchar(int c);
size_t	ft_putdec(int n);
size_t	ft_putdeclong(unsigned int n);
char	*ft_itoalong(long n);
int	    ft_putvoid(void *p);
int		ft_puthexa(unsigned long long nb, char ch);

#endif