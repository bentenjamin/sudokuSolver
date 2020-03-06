/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:51:54 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/18 14:38:01 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sudoku.h"

static void	ft_ptnr(int n)
{
	(n > 9) ? ft_ptnr(n / 10) : 0;
	ft_putchar((n % 10) + '0');
}

void		ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	(n < 0) ? ft_putchar('-') : 0;
	ft_ptnr(ft_abs(n));
}

int	ft_abs(int i)
{
	if ((i < 0) && (i != -2147483648))
		return (i * -1);
	return (i);
}

void	ft_putchar(char in)
{
	write(1, &in, 1);
}