/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:31:46 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/18 14:24:22 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sudoku.h"

void	ft_putstr(char const *str)
{
	while (str[0] && write(1, str++, 1))
		;
}

int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}

void	erexit(char *error)
{
	ft_putendl(error);
	exit(1);
}