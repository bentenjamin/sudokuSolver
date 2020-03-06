/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:00:53 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/18 14:09:21 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sudoku.h"

int		cx(int grid[9][9], int x, int y)
{
	int	i;

	i = 0;
	while (i <= 8)
	{
		if ((grid[i][y] == grid[x][y]) && (i != x))
			return (0);
		i++;
	}
	return (1);
}

int		cy(int grid[9][9], int x, int y)
{
	int k;

	k = 0;
	while (k <= 8)
	{
		if ((grid[x][k] == grid[x][y]) && (k != y))
			return (0);
		k++;
	}
	return (1);
}

int		cblock(int grid[9][9], int x, int y)
{
	int ix;
	int	iy;
	int	kx;
	int	ky;

	ix = x / 3 * 3;
	iy = y / 3 * 3;
	kx = 0;
	while (kx <= 2)
	{
		ky = 0;
		while (ky <= 2)
		{
			if ((grid[ix + kx][iy + ky] == grid[x][y]) \
			&& ((x != (ix + kx)) && (y != (iy + ky))))
				return (0);
			ky++;
		}
		kx++;
	}
	return (1);
}

int		check(int grid[9][9], int x, int y)
{
	return (cx(grid, x, y) && cy(grid, x, y) && cblock(grid, x, y));
}