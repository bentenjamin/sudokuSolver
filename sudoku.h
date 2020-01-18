/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:32:49 by bwebb             #+#    #+#             */
/*   Updated: 2020/01/18 14:41:55 by bwebb            ###   ########.fr       */
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
void	erexit(char *error);
void	popgrid(int grid[9][9], char **in);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
int		ft_abs(int i);
void	ft_putchar(char in);
int		check(int grid[9][9], int x, int y);
void	putgrid(int grid[9][9]);
int		validin(int argc, char **argv);
void	brute(int grid[9][9], int x, int y);

#endif