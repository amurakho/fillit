/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:41:05 by amurakho          #+#    #+#             */
/*   Updated: 2018/05/15 15:41:08 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_writebox(char **box)
{
	int		line_counter;
	int		sym_counter;
	char	symbol;

	line_counter = 0;
	sym_counter = 0;
	while (box[line_counter])
	{
		while (box[line_counter][sym_counter])
		{
			symbol = box[line_counter][sym_counter];
			write(1, &symbol, 1);
			sym_counter++;
		}
		symbol = '\n';
		write(1, &symbol, 1);
		sym_counter = 0;
		line_counter++;
	}
}
