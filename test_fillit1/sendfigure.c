/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendfigure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 10:58:49 by amurakho          #+#    #+#             */
/*   Updated: 2018/05/16 10:58:58 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	find_symbol(char *figure)
{
	int counter;

	counter = 0;
	while (figure[counter] == '.')
		counter++;
	return (figure[counter]);
}

char	**sendfigure(int hor_b, int vert_b, char **box, char **figure)
{
	int		horizontal_f;
	int		vertical_f;
	char	symbol;
	int		c_vert_b;

	c_vert_b = vert_b;
	horizontal_f = 0;
	vertical_f = 0;
	symbol = find_symbol(figure[0]);
	while (figure[horizontal_f] && box[hor_b])
	{
		while (figure[horizontal_f][vertical_f])
		{
			if (figure[horizontal_f][vertical_f] != '.')
				box[hor_b][vert_b] = symbol;
			vert_b++;
			vertical_f++;
		}
		hor_b++;
		vert_b = c_vert_b;
		vertical_f = 0;
		horizontal_f++;
	}
	return (box);
}
