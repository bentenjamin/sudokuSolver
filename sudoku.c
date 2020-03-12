/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:28:54 by bwebb             #+#    #+#             */
/*   Updated: 2020/03/12 08:51:31 by marvin           ###   ########.fr       */
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
			ft_putchar(grid[i][k] + '0');
			if (k != 8)
				ft_putchar(' ');
			k++;
		}
		ft_putstr("\n");
		i++;
	}
}

int		brute(int grid[9][9], int x, int y)
{
	y += (x == 9) ? 1 : 0;
	x = (x == 9) ? 0 : x;
	if (grid[x][y])
		return (((y == 8) && (x == 8)) ? 1 : brute(grid, x + 1, y + 1));
	while ((++(grid[x][y])) <= 9)
		if(check(grid, x, y) && (((x == 8) && (y == 8)) || (brute(grid, x + 1, y))))
			return (1);
	return (grid[x][y] = 0);
}

int		main(int argc, char **argv)
{
	int	grid[9][9];

	if (validin(argc, ++argv) && popgrid(grid, argv) && brute(grid, 0, 0))
		putgrid(grid);
	else
		ft_putendl("Error");
	return (1);
}
