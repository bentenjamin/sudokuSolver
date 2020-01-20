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

void	popgrid(int grid[9][9], char **in)
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

void	putgrid(int grid[9][9])
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
}

void	brute(int grid[9][9], int x, int y)
{
	if (grid[x][y] == 0)
	{
		while ((++(grid[x][y])) <= 9)
			if(check(grid, x, y))
			{
				if ((x == 8) && (y == 8))
				{
					putgrid(grid);
					exit(1);
				}
				else
					brute(grid, (x == 8) ? 0 : x + 1, (x == 8) ? y + 1 : y);
			}
		grid[x][y] = 0;
	}
	else
	{
		if ((x == 8) && (y == 8))
		{
			putgrid(grid);
			exit(1);
		}
		brute(grid, (x == 8) ? 0 : x + 1, (x == 8) ? y + 1 : y);
	}
	return ;
}

int		main(int argc, char **argv)
{
	int	grid[9][9];
	
	if (!validin(argc, ++argv))
		erexit("error invalid input");
	popgrid(grid, argv);
	brute(grid, 0, 0);
	erexit("invalid grid");
	return (0);
}
