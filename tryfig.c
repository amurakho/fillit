/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tryfig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 12:59:58 by amurakho          #+#    #+#             */
/*   Updated: 2018/05/15 15:40:41 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	editcoord(int *vertical_b, int *vertical_f, int *pos, int flag)
{
	if (flag)
	{
		*vertical_b += 1;
		*vertical_f += 1;
		if (*pos == -1)
			*pos += 1;
	}
	else
	{
		*pos += 1;
		*vertical_b = *pos;
		*vertical_f = 0;
	}
}

int		tryline(char *box_line, char *figure_line, int pos)
{
	int vertical_f;
	int vertical_b;

	vertical_b = pos;
	if (pos == -1)
		vertical_b = 0;
	vertical_f = 0;
	while (figure_line[vertical_f])
	{
		if (figure_line[vertical_f] != '.')
		{
			if (!box_line[vertical_b])
				return (-1);
			if (box_line[vertical_b] == '.')
				editcoord(&vertical_b, &vertical_f, &pos, 1);
			else
				editcoord(&vertical_b, &vertical_f, &pos, 0);
		}
		else
			editcoord(&vertical_b, &vertical_f, &pos, 1);
	}
	return (pos);
}

int		*tryfigure(char **box, char **figure, int horizontal_b, int vertical)
{
	int horizontal_f;
	int *coord;
	int line_res;

	coord = (int*)malloc(sizeof(int) * 2);
	coord[0] = -1;
	horizontal_f = 0;
	while (figure[horizontal_f])
	{
		if (!box[horizontal_b])
			return (ifnotbox(coord));
		line_res = tryline(box[horizontal_b], figure[horizontal_f], vertical);
		if (line_res == -1)
			coord = ifnline(coord, &vertical, &horizontal_f, &horizontal_b);
		if (line_res != -1)
		{
			coord = ifline_1(coord, horizontal_b, line_res);
			if (line_res > vertical && vertical != -1)
				if_line_2(&horizontal_f, &horizontal_b, coord);
			else
				if_line_3(&horizontal_b, &horizontal_f);
			vertical = line_res;
		}
	}
	return (coord);
}
