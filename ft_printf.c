/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:59:42 by aaghla            #+#    #+#             */
/*   Updated: 2023/11/28 14:00:32 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_find_type(char c, va_list args, int	*count)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (c == 'x' || c == 'X')
		ft_tohex(va_arg(args, unsigned int), c, count);
	else if (c == 'p')
		ft_ptohex(va_arg(args, void *), count);
	else if (c == 'u')
		ft_unsignednbr(va_arg(args, unsigned int), count);
}

static int	ft_isthere(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'x' || c == 'X'
		|| c == 'p' || c == 'u')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str);
	count = 0;
	i = -1;
	if (write(1, "", 0) < 0)
		return (-1);
	while (str[++i])
	{
		if (str[i] != '%')
			ft_putchar(str[i], &count);
		else if (str[i] == '%' && str[i +1] == '%')
			ft_putchar(str[i++], &count);
		else if (str[i] == '%' && ft_isthere(str[i +1]))
			ft_find_type(str[++i], args, &count);
	}
	va_end(args);
	return (count);
}
