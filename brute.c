/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:56:39 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/18 14:40:41 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sudoku.h"

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
		brute(grid, (x == 8) ? 0 : x + 1, (x == 8) ? y + 1 : y);
	return ;
}