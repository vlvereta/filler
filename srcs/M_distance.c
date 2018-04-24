/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_distace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2018/04/18 10:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_min_distance_1(int index, t_filler *f)
{
	int		i;
	int		temp;
	int		result;

	i = 0;
	temp = 0;
	result = 0;
	while (f->piece[i])
	{
		if (f->piece[i] == f->player)
		{
			temp = find_min_distance_2(index + i, f);
			if (!result)
				result = temp;
			else
				result = temp < result ? temp : result;
		}
		i++;
	}
	return (result);
}

int		find_min_distance_2(int player, t_filler *f)
{
	int		i;
	int		temp;
	int		result;

	i = 0;
	temp = 0;
	result = 0;
	while (f->map[i])
	{
		if (f->map[i] == f->enemy)
		{
			temp = find_distance(player, i, f->m_width);
			if (!result)
				result = temp;
			else
				result = temp < result ? temp : result;
		}
		i++;
	}
	return (result);
}

int		find_distance(int player, int enemy, int width)
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		result;

	x1 = player /width;
	y1 = player % width;
	x2 = enemy / width;
	y2 = enemy % width;
	result = abs(x1 - x2) + abs(y1 - y2);
	return (result);
}
