/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2018/04/18 10:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_info(t_filler *f)
{
	char	*cur_line;

	cur_line = NULL;
	while (get_next_line(0, &cur_line) > 0)
	{
		if (*cur_line == '$')
			get_player_number(f, &cur_line);
		else if (ft_strnequ("Plateau", cur_line, 7))
		{
			if (!get_map(f, &cur_line))
				break ;
		}
		else if (ft_strnequ("Piece", cur_line, 5))
			return (get_piece(f, &cur_line) ? 1 : 0);
		ft_strdel(&cur_line);
	}
	return (0);
}

void	get_player_number(t_filler *f, char **line)
{
	char	*str;

	str = *line;
	if (ft_strequ("$$$ exec p1 : [./vlvereta.filler]", str))
		f->player = '1';
	else if (ft_strequ("$$$ exec p2 : [./vlvereta.filler]", str))
		f->player = '2';
	f->enemy = f->player == '2' ? '1' : '2';
	ft_strdel(line);
}

int		get_map(t_filler *f, char **line)
{
	int		i;
	char	*temp;

	if (!map_whl(f, line))
		return (0);
	i = 0;
	while (i < f->m_length - 1)
	{
		if (get_next_line(0, line) <= 0)
			return (0);
		temp = *line + 4;
		while (*temp)
		{
			if (*temp == 'o' || *temp == 'O')
				f->map[i] = '1';
			else if (*temp == 'x' || *temp == 'X')
				f->map[i] = '2';
			i++;
			temp++;
		}
		ft_strdel(line);
	}
	return (1);
}

int		get_piece(t_filler *f, char **line)
{
	int		i;
	char	*temp;

	get_size(&(f->p_width), &(f->p_height), &(f->p_length), line);
	if (!piece_expand(f))
		return (0);
	i = 0;
	while (i < f->p_length - 1)
	{
		if (get_next_line(0, line) <= 0)
			return (0);
		temp = *line;
		while (*temp)
		{
			if (*temp == '*')
				f->piece[i] = f->player;
			i++;
			temp++;
		}
		while (i % f->m_width)
			i++;
		ft_strdel(line);
	}
	return (trim_piece(f) ? 1 : 0);
}
