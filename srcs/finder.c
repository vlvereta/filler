/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2018/04/18 10:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/filler.h"

int		find_position(t_filler *f)
{
	int		last;
	int		index;
	t_pp	*head;
	t_pp	*node;

	head = NULL;
	index = 0;
	last = f->m_length - f->p_length;
	while (index < last)
	{
		node = NULL;
		if (check_position(index, f))
		{
			if ((node = new_node(index)))
			{
				node->distance = find_min_distance_1(index, f);
				add_front(&head, node);
			}
		}
		index++;
	}
	return (find_best_position(&head));
}

int		check_position(int j, t_filler *f)
{
	int		i;
	int		touch;

	i = 0;
	touch = 0;
	if (j % f->m_width + f->p_width > f->m_width)
		return (0);
	while (f->piece[i])
	{
		if (f->piece[i] == f->player && f->map[j] == f->player)
			touch++;
		if (f->piece[i] == f->player && f->map[j] == f->enemy)
			return (0);
		i++;
		j++;
	}
	return (touch == 1 ? 1 : 0);
}

int		find_best_position(t_pp **head)
{
	int		dis;
	int		index;
	t_pp	*temp;

	index = ERROR;
	if (head && *head)
	{
		temp = *head;
		dis = temp->distance;
		index = temp->index;
		temp = temp->next;
		while (temp)
		{
			if (temp->distance < dis)
			{
				dis = temp->distance;
				index = temp->index;
			}
			temp = temp->next;
		}
		clean_list(head);
	}
	return (index);
}
