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

	ft_putstr("\e[1;1H\e[2J╔═══════╦═══════╦═══════╗\n");
	i = 0;
	while (i <= 8)
	{
		k = 0;
		ft_putstr("║ ");
		while (k <= 8)
		{
			(grid[i][k]) ? ft_putchar(grid[i][k] + '0') : ft_putchar(' ');
			ft_putchar(' ');
			if ((k == 2) || (k == 5))
				ft_putstr("║ ");
			k++;
		}
		ft_putstr("║\n");
		if ((i == 2) || (i == 5))
			ft_putstr("╠═══════╬═══════╬═══════╣\n");
		i++;
	}
	ft_putstr("╚═══════╩═══════╩═══════╝\n");
	return (usleep(1000));
}

int 	algo(int grid[9][9], int x, int y);

int		next_cell(int grid[9][9], int x, int y) {
	if (x == 8) {
		if (y == 8)
			return (1);
		return (algo(grid, 0, y + 1));
	}
	return (algo(grid, x + 1, y));
}

int 	algo(int grid[9][9], int x, int y) {
	if (grid[x][y] != 0)
		return (next_cell(grid, x, y));

	while (grid[x][y] < 9) {
		grid[x][y]++;

		if (check(grid, x, y))
			if (next_cell(grid, x, y))
				return (1);
	}
	
	return (grid[x][y] = 0);
}

int		main(int argc, char **argv)
{
	int	grid[9][9];

	if (validin(argc, ++argv) && popgrid(grid, argv) && algo(grid, 0, 0))
		putgrid(grid);
	else
		ft_putendl("Error");
	return (1);
}
