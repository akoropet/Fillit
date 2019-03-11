/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:10:50 by akoropet          #+#    #+#             */
/*   Updated: 2018/07/23 20:11:12 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "./libft/libft.h"

# define BUF_SIZE 1

int		ft_valid(char *buf);
int		ft_valid_strok(char *buf);
int		ft_valid_stroki(char *buf);
int		ft_valid_simvolov(char *buf);

int		ft_valid_figury(char *buf);
int		ft_valid_check(char *buf);
int		ft_block(char *buf, int i, int n);
int		ft_valid_last(char *buf);

int		ft_karta_size(char **str);
char	**ft_karta(char *buf, int size);
char	**ft_karta_create(int n);
void	ft_karta_point(char *s, int n);
void	ft_karta_print(char **map);
int		ft_add_square(char **map, char **fig, int k, int count);

void	ft_move_figure(char **str);
int		ft_move_vertikal(char **str, int q, int w, int k);
int		ft_first_string_h(char **str, int j);

int		ft_first_string_v(char **str, int j);
void	ft_move_horizontal(char **str, int q, int e, int k);
int		ft_move_horizontal_check(char **str, int j, int a, int k);

int		ft_check_place(char **dst, char **src, int j, int i);
void	ft_enter_fig(char **map, char **fig, int j, int i);
void	ft_delete_fig(char **map, char k);
int		ft_find_symbol(char *s, int a);

#endif
