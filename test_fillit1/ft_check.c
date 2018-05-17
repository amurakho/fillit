/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:52:33 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/05/08 13:56:43 by tvoronyu         ###   ########.fr       */
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
