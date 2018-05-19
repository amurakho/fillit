/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makebox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:09:22 by amurakho          #+#    #+#             */
/*   Updated: 2018/05/15 16:09:25 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**makebox(int i)
{
	int		vert_c;
	int		hort_c;
	char	**box;

	vert_c = 0;
	hort_c = 0;
	box = (char**)malloc(sizeof(char*) * (i + 1));
	while (hort_c != i)
	{
		box[hort_c] = (char*)malloc(sizeof(char) * (i + 1));
		while (vert_c != i)
		{
			box[hort_c][vert_c] = '.';
			vert_c++;
		}
		box[hort_c][vert_c] = '\0';
		vert_c = 0;
		hort_c++;
	}
	box[hort_c] = NULL;
	return (box);
}
