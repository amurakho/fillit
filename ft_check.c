/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:52:33 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/05/19 12:05:14 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_pieces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] != '#' && str[i - 1] != '#' && str[i + 5] != '#'
					&& str[i - 5] != '#')
				return (0);
		}
		i++;
	}
	return (1);
}

int			ft_check_2_1(char *ptr[])
{
	if (ptr[1] - ptr[0] != 1 && ptr[1] - ptr[0] != 5)
	{
		if (ft_check_2_1_1(ptr) == 0)
			return (0);
	}
	if (ptr[2] - ptr[1] != 1 && ptr[2] - ptr[1] != 5)
	{
		if (ft_check_2_1_1(ptr) == 0)
		{
			if (ft_check_2_1_3(ptr) == 0)
				return (0);
		}
	}
	if (ptr[3] - ptr[2] != 1 && ptr[3] - ptr[2] != 5)
	{
		if (ft_check_2_1_1(ptr) == 0)
		{
			if (ft_check_2_1_4(ptr) == 0)
				return (0);
		}
	}
	return (1);
}

int			ft_check_2(char *str)
{
	char	*s[5];
	int		i;

	s[4] = NULL;
	i = 0;
	while (*str != '\0')
	{
		if (i == 4)
			i = 0;
		if (*str == '#')
		{
			ft_check_2_2_2(s, str, i);
			i++;
		}
		if (i == 4)
			if (ft_check_2_1(s) == 0)
				return (0);
		str++;
	}
	return (1);
}

char		*ft_slash_nl(char *str)
{
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = ft_strnew(ft_strlen(str));
	s2 = s1;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i] != '\0')
			i++;
		*s1 = str[i];
		s1++;
		i++;
	}
	return (s2);
}

char		***ft_mas_1(char *str)
{
	char	***mas;
	size_t	i;
	size_t	n;

	n = 0;
	mas = NULL;
	if (!(ft_strlen(str) % 20))
	{
		if (!(mas = (char***)malloc(sizeof(char**) * (((ft_strlen(str)) / 20)
							+ 1))))
			return (NULL);
		mas[(ft_strlen(str) / 20)] = NULL;
		while (n < ((ft_strlen(str)) / 20))
		{
			if (!(mas[n] = (char**)malloc(sizeof(char*) * 5)))
				return (NULL);
			mas[n][4] = NULL;
			i = 0;
			while (i < 4)
				mas[n][i++] = ft_strnew(5);
			n++;
		}
	}
	mas = ft_write_1(mas, str);
	return (mas);
}
