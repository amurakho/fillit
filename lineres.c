/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:35:49 by amurakho          #+#    #+#             */
/*   Updated: 2018/05/15 15:38:46 by amurakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ifnline(int *coord, int *vertical, int *hor_f, int *hor_b)
{
	*vertical = -1;
	coord[0] = -1;
	if (*hor_f == 0)
		*hor_b += 1;
	*hor_f = 0;
	return (coord);
}

int		*ifline_1(int *coord, int horizontal_b, int line_res)
{
	if (coord[0] == -1)
	{
		coord[1] = line_res;
		coord[0] = horizontal_b;
	}
	return (coord);
}

int		*if_line_2(int *horizontal_f, int *horizontal_b, int *coord)
{
	*horizontal_f = 0;
	*horizontal_b = coord[0];
	coord[0] = -1;
	return (coord);
}

void	if_line_3(int *horizontal_b, int *horizontal_f)
{
	*horizontal_b += 1;
	*horizontal_f += 1;
}

int		*ifnotbox(int *coord)
{
	coord[0] = 105;
	return (coord);
}
