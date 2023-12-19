/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:08:44 by aaghla            #+#    #+#             */
/*   Updated: 2023/11/27 14:43:27 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_puthex(size_t n, int *count)
{
	char	*set;

	set = "0123456789abcdef";
	if (n < 16)
		ft_putchar(set[n], count);
	else
	{
		ft_puthex(n / 16, count);
		ft_puthex(n % 16, count);
	}
}

void	ft_ptohex(void *p, int *count)
{
	size_t	n;

	if (!p)
	{
		ft_putstr("0x0", count);
		return ;
	}
	n = (size_t)p;
	ft_putstr("0x", count);
	ft_puthex(n, count);
}
