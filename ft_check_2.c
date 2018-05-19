/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:51:35 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/05/08 13:55:29 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_2_1_2(char *ptr[])
{
	if (ptr[3] - ptr[0] != 1 && ptr[3] - ptr[0] != 5)
		return (0);
	return (1);
}

int		ft_check_2_1_1(char *ptr[])
{
	if (ptr[2] - ptr[0] != 1 && ptr[2] - ptr[0] != 5)
	{
		if (ft_check_2_1_2(ptr) == 0)
			return (0);
	}
	return (1);
}

int		ft_check_2_1_4(char *ptr[])
{
	if (ptr[2] - ptr[1] != 1 && ptr[2] - ptr[1] != 5)
	{
		return (0);
	}
	return (1);
}

int		ft_check_2_1_3(char *ptr[])
{
	if (ptr[3] - ptr[1] != 1 && ptr[3] - ptr[1] != 5)
	{
		if (ft_check_2_1_4(ptr) == 0)
			return (0);
	}
	return (1);
}

char	*ft_slash(char *str)
{
	char	*s1;
	char	*s2;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
			count++;
		i++;
	}
	s1 = ft_strnew(count);
	s2 = s1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i])
			*s1++ = str[i];
		i++;
	}
	free(str);
	return (s2);
}
