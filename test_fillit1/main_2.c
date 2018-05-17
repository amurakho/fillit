/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 13:14:53 by amurakho          #+#    #+#             */
/*   Updated: 2018/05/17 14:57:52 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**biggerbox(char **old)
{
	char	**new;
	int		hor;
	int		vert;

	hor = 0;
	vert = 0;
	new = (char**)malloc(sizeof(char*) * (int)(ft_strlen(old[0]) + 2));
	while (hor != (int)ft_strlen(old[0]) + 1)
	{
		new[hor] = (char*)malloc(sizeof(char) * (int)(ft_strlen(old[0]) + 2));
		while (vert != (int)ft_strlen(old[0]) + 1)
		{
			if (old[hor] && old[hor][vert] && old[hor][vert] != '.')
				new[hor][vert] = old[hor][vert];
			else
				new[hor][vert] = '.';
			vert++;
		}
		new[hor][vert] = '\0';
		vert = 0;
		hor++;
	}
	new[hor] = NULL;
	return (new);
}

char	**delete_figure(char **box, char symbol)
{
	int horizontal;
	int vertical;

	vertical = 0;
	horizontal = 0;
	while (box[horizontal])
	{
		while (box[horizontal][vertical])
		{
			if (box[horizontal][vertical] == symbol)
				box[horizontal][vertical] = '.';
			vertical++;
		}
		vertical = 0;
		horizontal++;
	}
	return (box);
}

char	**backtrack(char ***fig, char **box, int fig_count)
{
	int c;
	int **coord_1;

	coord_1 = figurecoord(fig_count);
	c = 0;
	while (c != fig_count)
	{
		nullcoord(coord_1[c]);
		coord_1[c] = tryfigure(box, fig[c], coord_1[c][0], coord_1[c][1]);
		if (coord_1[c][0] == 105)
		{
			box = ifbiggerbox(&c, box);
			if (c >= 0)
			{
				box = delete_figure(box, find_symbol(fig[c][0]));
				coord_1[c] = ifdelete(coord_1[c], box);
			}
		}
		else
		{
			box = sendfigure(coord_1[c][0], coord_1[c][1], box, fig[c]);
			coord_1 = ifsend(&c, coord_1);
		}
	}
	return (box);
}

void	main_2(char ***fig, int figur_count)
{
	char	**new_box;
	int		coun;
	char	**box;
	int		i;

	coun = 0;
	while (coun != figur_count)
	{
		fig[coun] = modifine(fig[coun], figuresize(fig[coun], 0, 0, 0), 0, 0);
		coun++;
	}
	i = 2;
	while (i * i < figur_count * 4)
	{
		i++;
	}
	box = makebox(i);
	new_box = backtrack(fig, box, figur_count);
	ft_writebox(new_box);
}
