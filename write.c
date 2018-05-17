/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teee.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:56:37 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/05/08 13:52:07 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***ft_write(char ***mas, char *str)
{
	size_t	i;
	int		n;
	int		s;
	int		g;

	i = 0;
	g = 0;
	while (i < (ft_strlen(str) / 16))
	{
		n = 0;
		while (n < 4)
		{
			s = 0;
			while (s < 4)
			{
				mas[i][n][s] = str[g];
				s++;
				g++;
			}
			n++;
		}
		i++;
	}
	free(str);
	return (mas);
}

char	***ft_mas_alpha(char ***str)
{
	int		i;
	int		n;
	int		m;
	char	c;

	i = 0;
	c = 'A';
	while (str[i] && c <= 'Z')
	{
		n = 0;
		while (str[i][n])
		{
			m = 0;
			while (str[i][n][m] != '\0')
			{
				if (str[i][n][m] == '#')
					str[i][n][m] = c;
				m++;
			}
			n++;
		}
		i++;
		c++;
	}
	return (str);
}

char	***ft_mas(char *str)
{
	char	***mas;
	size_t	i;
	size_t	n;

	n = 0;
	mas = NULL;
	if (!(ft_strlen(str) % 16))
	{
		if (!(mas = (char***)malloc(sizeof(char**) * (((ft_strlen(str)) / 16)
							+ 1))))
			return (NULL);
		mas[(ft_strlen(str) / 16)] = NULL;
		while (n < ((ft_strlen(str)) / 16))
		{
			if (!(mas[n] = (char**)malloc(sizeof(char*) * 5)))
				return (NULL);
			mas[n][4] = NULL;
			i = 0;
			while (i < 4)
				mas[n][i++] = ft_strnew(4);
			n++;
		}
	}
	mas = ft_write(mas, str);
	return (mas);
}
