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

#include "filler.h"

int		main(void)
{
	t_filler	*f;

	if ((f = (t_filler *)ft_memalloc(sizeof(t_filler))))
	{
		game_loop(f);
		print_answer(0, f);
		clean_structure(&f);
	}
	return (0);
}

void	game_loop(t_filler *f)
{
	int		index;

	while (1)
	{
		if (!get_info(f))
			break ;
		index = find_position(f);
		if (index == ERROR)
			break ;
		print_answer(index, f);
		f->dev_x = 0;
		f->dev_y = 0;
		ft_strdel(&(f->map));
		ft_strdel(&(f->piece));
	}
}

void	print_answer(int index, t_filler *f)
{
	int		x;
	int		y;
	int		width;

	x = 0;
	y = 0;
	width = f->m_width;
	if (width)
	{
		x = index / width - f->dev_x;
		y = index % width - f->dev_y;
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
