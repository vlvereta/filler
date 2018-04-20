/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:47:06 by vlvereta          #+#    #+#             */
/*   Updated: 2018/04/20 15:47:08 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/filler.h"

t_pp	*new_node(int index)
{
	t_pp	*node;

	if (!(node = (t_pp *)ft_memalloc(sizeof(t_pp))))
		return (NULL);
	node->index = index;
	return (node);
}

t_pp	*add_front(t_pp **head, t_pp *node)
{
	if (node)
	{
		node->next = *head;
		*head = node;
	}
	return (*head);
}

void	clean_list(t_pp **head)
{
	t_pp	*temp;

	temp = *head;
	if (temp && temp->next)
		clean_list(&(temp->next));
	if (temp)
		ft_memdel((void **)&temp);
}
