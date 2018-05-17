/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:01:00 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/05/08 14:07:20 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

int		count_tetriminos(char *str)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	return ((n + 1) / 5);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		bytes;
	char	***tetris;
	char	*buf;

	if (argc != 2)
	{
		ft_putendl("usage: fillit input_file");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error();
	buf = (char*)malloc(BUFF_SIZE + 1);
	bytes = read(fd, buf, (BUFF_SIZE + 1));
	if (bytes == -1)
		error();
	buf[bytes] = '\0';
	if (ft_verificare(buf, 0, 0, 0) == 0 || ft_check_pieces(buf) == 0
		|| ft_verificare_2(buf) == 0 || ft_check_2(buf) == 0)
		error();
	tetris = ft_mas_alpha(ft_mas(ft_slash(buf)));
	main_2(tetris, ft_display(tetris));
	return (0);
}
