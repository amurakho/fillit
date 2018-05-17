/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:12:13 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/05/04 13:02:09 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include "libft/libft.h"
# define BUFF_SIZE 546

char	**biggerbox(char **old);
int		**figurecoord(int fig_count);
char	**ifbiggerbox(int *counter, char **box);
int		*nullcoord(int *coord);
int		**ifsend(int *counter, int **coord_1);
int		*ifdelete(int *coord, char **box);
char	find_symbol(char *figure);
char	**sendfigure(int hor_b, int vert_b, char **box, char **figure);
char	**makebox(int i);
int		*ifnline(int *coord, int *vertical, int *horizontal_f, int *hor_b);
int		*ifline_1(int *coord, int horizontal_b, int line_res);
int		*if_line_2(int *horizontal_f, int *horizontal_b, int *coord);
void	if_line_3(int *horizontal_b, int *horizontal_f);
int		*ifnotbox(int *coord);
char	**makebox(int i);
void	ft_writebox(char **box);
int		*tryfigure(char **box, char **figure, int horizontal_b, int vertical);
int		tryline(char *box_line, char *figure_line, int pos);
int		findlines(char **figure);
int		findsymbols(char **figure);
int		*figuresize(char **figure, int horizontal, int vertical, int symbols);
char	**modifine(char **figure, int *size, int horizontal, int vertical);
void	error(void);
int		count_tetriminos(char *str);
int		ft_verificare(char *s, int i, int hash, int dot);
int		ft_check_pieces(char *str);
int		ft_check_2_1_2(char *ptr[]);
int		ft_check_2_1(char *ptr[]);
int		ft_check_2_1_1(char *ptr[]);
int		ft_check_2(char *str);
int		ft_verificare_2(char *str);
char	*ft_slash(char *str);
char	***ft_write(char ***mas, char *str);
char	***ft_mas(char *str);
void	ft_check_2_2_2(char *s[], char *str, int i);
int		ft_check_2_1_4(char *ptr[]);
int		ft_check_2_1_3(char *ptr[]);
char	***ft_mas_alpha(char ***str);
int		ft_display(char ***mas);
void	main_2(char ***figures, int count_figur);

#endif
