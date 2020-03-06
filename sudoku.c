/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:28:54 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/18 15:17:49 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sudoku.h"

int		popgrid(int grid[9][9], char **in)
{
	int	i;
	int	k;

	i = 0;
	while (i <= 8)
	{
		k = -1;
		while (++k <= 8)
			grid[i][k] = (ft_isdigit(in[i][k])) ? in[i][k] - '0' : 0;
		i++;
	}
	i = 0;
	while (i <= 8)
	{
		k = -1;
		while (++k <= 8)
			if (grid[i][k] && !check(grid, i, k))
				return (0);
		i++;
	}
	return (1);
}

int		validin(int argc, char **argv)
{
	int i;
	int j;

	if (argc != 10)
		return (0);
	i = 0;
	while (i <= 8)
	{
		j = 0;
		while(argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !(argv[i][j] == '.'))
				return (0);
			j++;
		}
		if (j != 9)
			return (0);
		i++;
	}
	return (1);
}

int		putgrid(int grid[9][9])
{
	int	i;
	int	k;

	i = 0;
	while (i <= 8)
	{
		k = 0;
		while (k <= 8)
		{
			ft_putnbr(grid[i][k]);
			ft_putchar(' ');
			k++;
		}
		ft_putchar('\n');
		i++;
	}
	return (1);
}

int		brute(int grid[9][9], int x, int y)
{
	if (grid[x][y])
		return ((x == 8) ? ((y == 8) ? 1 : brute(grid, 0, y + 1)) : \
		brute(grid, x + 1, y));
	while ((++(grid[x][y])) <= 9)
		if(check(grid, x, y) && (((x == 8) && (y == 8)) || \
		(brute(grid, x + ((x == 8) ? -x : 1), y + ((x == 8) ? 1 : 0)))))
			return (1);
	return (grid[x][y] = 0);
}

int		main(int argc, char **argv)
{
	int	grid[9][9];

	if (!validin(argc, ++argv))
		erexit("error invalid input");
	if (!popgrid(grid, argv) || !brute(grid, 0, 0))
		ft_putendl("invalid grid");
	return (putgrid(grid));
}
