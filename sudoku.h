/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:32:49 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/18 15:19:53 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 32
# define BASE_VALS "0123456789ABCDEF"

void	ft_putstr(char const *str);
int		ft_isdigit(int c);
void	ft_putendl(char const *s);
void	ft_putchar(char in);
int		check(int grid[9][9], int x, int y);

#endif