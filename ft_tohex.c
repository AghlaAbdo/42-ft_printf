/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:19:57 by aaghla            #+#    #+#             */
/*   Updated: 2023/11/26 17:24:44 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_tohex(unsigned int n, char c, int *count)
{
	char	*set;

	if (c == 'X')
		set = "0123456789ABCDEF";
	else if (c == 'x')
		set = "0123456789abcdef";
	if (n < 16)
		ft_putchar(set[n], count);
	else
	{
		ft_tohex(n / 16, c, count);
		ft_tohex(n % 16, c, count);
	}
}
