/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makefigure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 13:07:43 by amurakho          #+#    #+#             */
/*   Updated: 2018/05/15 16:05:32 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		findlines(char **figure)
{
	int		counter;
	int		horizontal;
	int		vertical;

	horizontal = 0;
	vertical = 0;
	counter = 0;
	while (!counter)
	{
		if (!figure[horizontal] || !figure[horizontal][vertical])
		{
			vertical = 0;
			horizontal++;
		}
		if (figure[horizontal][vertical] != '.' && figure[horizontal][vertical])
			counter++;
		vertical++;
	}
	return (horizontal);
}

int		findsymbols(char **figure)
{
	int		counter;
	int		horizontal;
	int		vertical;

	horizontal = 0;
	vertical = 0;
	counter = 0;
	while (!counter)
	{
		if (!figure[horizontal] || !figure[horizontal][vertical])
		{
			horizontal = 0;
			vertical++;
		}
		if (figure[horizontal][vertical] != '.' && figure[horizontal][vertical])
			counter++;
		horizontal++;
	}
	return (vertical);
}

int		*figuresize(char **figure, int horizontal, int vertical, int symbols)
{
	int		*size;

	size = (int*)malloc(sizeof(int) * 2);
	size[1] = 0;
	size[0] = 0;
	while (figure[horizontal])
	{
		while (figure[horizontal][vertical])
		{
			if (figure[horizontal][vertical] != '.')
				symbols++;
			vertical++;
		}
		if (symbols != 0)
			size[0]++;
		if (symbols > size[1])
			size[1] = symbols;
		symbols = 0;
		vertical = 0;
		horizontal++;
	}
	return (size);
}

char	**modifine_part(char **new_line, int *vetical, int *hor, int size)
{
	new_line[*hor][*vetical] = '\0';
	*vetical = 0;
	if (*hor < size)
		*hor += 1;
	return (new_line);
}

char	**modifine(char **fig, int *size, int hor, int vertical)
{
	char	**new;
	int		lines;
	int		sym;

	lines = findlines(fig);
	sym = findsymbols(fig);
	new = (char**)malloc(sizeof(char*) * (ft_strlen(fig[0]) - lines + 1));
	while (fig[lines])
	{
		new[hor] = (char*)malloc(sizeof(char) * (ft_strlen(fig[0]) - sym + 1));
		while (fig[lines][sym])
		{
			if (fig[lines][sym] != '.' && vertical >= size[1])
				size[1]++;
			if (vertical < size[1])
				new[hor][vertical] = fig[lines][sym];
			vertical++;
			sym++;
		}
		modifine_part(new, &vertical, &hor, size[0]);
		sym = findsymbols(fig);
		lines++;
	}
	new[hor] = NULL;
	return (new);
}
