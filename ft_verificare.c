/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verificare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:54:14 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/05/19 12:00:41 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_verificare(char *s, int i, int hash, int dot)
{
	int count;
	int nl;

	nl = 0;
	count = count_tetriminos(s);
	if ((int)ft_strlen(s) != (count * 20 + count - 1))
		return (0);
	while (s[i])
	{
		if (s[i] == '.')
			dot++;
		else if (s[i] == '#')
			hash++;
		else if (s[i] == '\n')
			nl++;
		else
			return (0);
		i++;
	}
	if (dot != (count * 12) || hash != (count * 4) ||
			nl != (count * 4 + count - 1))
		return (0);
	return (1);
}

int			ft_verificare_2(char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		if (i % 21 == 0 && i == 21)
			if (*str-- != '\n' && *str != '\n')
				return (0);
		str++;
		i++;
	}
	return (1);
}

void		ft_check_2_2_2(char *s[], char *str, int i)
{
	if (i == 0)
		s[0] = str;
	if (i == 1)
		s[1] = str;
	if (i == 2)
		s[2] = str;
	if (i == 3)
		s[3] = str;
}

char		*ft_verificare_3(char *str)
{
	if (ft_test_nl(ft_mas_1(ft_slash_nl(str))) == 1)
		error();
	return (str);
}

int			ft_display(char ***mas)
{
	int i;
	int n;

	i = 0;
	while (mas[i])
	{
		n = 0;
		while (mas[i][n])
		{
			n++;
		}
		i++;
	}
	return (i);
}
