/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2018/04/18 10:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/filler.h"

int		main(void)
{
	int			index;
	t_filler	*f;

	if ((f = (t_filler *)ft_memalloc(sizeof(t_filler))))
	{
		while (1)
		{
			if (!get_info(f))
				break ;
			index = find_position(f);
			if (index == ERROR)
				break ;
			print_answer(index, f->m_width);
			ft_strdel(&(f->map));
			ft_strdel(&(f->piece));
		}
		print_answer(0, 0);
		clean_structure(&f);
	}
	return (0);
}

void	print_answer(int index, int width)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (index && width)
	{
		x = index / width;
		y = index % width;
	}
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

void	clean_structure(t_filler **f)
{
	t_filler	*temp;

	temp = *f;
	if (temp->map)
		ft_strdel(&(temp->map));
	if (temp->piece)
		ft_strdel(&(temp->piece));
	ft_memdel((void **)f);
}
