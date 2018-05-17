/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:53:05 by amurakho          #+#    #+#             */
/*   Updated: 2018/05/17 14:57:17 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**figurecoord(int fig_count)
{
	int **coord_1;
	int counter;

	coord_1 = (int**)malloc(sizeof(int*) * fig_count + 1);
	counter = 0;
	while (counter != fig_count)
	{
		coord_1[counter] = (int*)malloc(sizeof(int) * 2);
		coord_1[counter][1] = 0;
		coord_1[counter][0] = 0;
		counter++;
	}
	coord_1[counter] = NULL;
	return (coord_1);
}

int		*ifdelete(int *coord, char **box)
{
	int coord_1;
	int coord_0;

	coord_0 = coord[0];
	coord_1 = coord[1];
	coord_1++;
	if (!box[coord_1 + 1])
	{
		coord_0++;
		coord_1 = 0;
	}
	coord[0] = coord_0;
	coord[1] = coord_1;
	return (coord);
}

int		**ifsend(int *counter, int **coord_1)
{
	*counter += 1;
	if (coord_1[*counter])
	{
		coord_1[*counter][0] = 0;
		coord_1[*counter][1] = 0;
	}
	return (coord_1);
}

int		*nullcoord(int *coord)
{
	int coord_1;
	int coord_0;

	coord_0 = coord[0];
	coord_1 = coord[1];
	if (coord_0 == 105)
	{
		coord_1 = 0;
		coord_0 = 0;
	}
	coord[0] = coord_0;
	coord[1] = coord_1;
	return (coord);
}

char	**ifbiggerbox(int *counter, char **box)
{
	*counter -= 1;
	if (*counter < 0)
	{
		box = biggerbox(box);
		*counter = 0;
	}
	return (box);
}
