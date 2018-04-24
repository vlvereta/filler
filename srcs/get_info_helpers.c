/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2018/04/18 10:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		map_whl(t_filler *f, char **line)
{
	if (!(f->m_width) || !(f->m_height) || !(f->m_length))
		get_size(&(f->m_width), &(f->m_height), &(f->m_length), line);
	else
		ft_strdel(line);
	if (!(f->map = ft_strnew(f->m_length)))
		return (0);
	ft_memset(f->map, '0', f->m_length);
	get_next_line(0, line);
	ft_strdel(line);
	return (1);
}

int		piece_expand(t_filler *f)
{
	f->p_length = f->p_height * f->m_width;
	if (!(f->piece = ft_strnew(f->p_length)))
		return (0);
	ft_memset(f->piece, '0', f->p_length);
	return (1);
}

int		trim_piece(t_filler *f)
{
	int		end;
	int		start;
	char	*temp;

	end = f->p_length - 1;
	while (end > 0 && (f->piece)[end] == '0')
		end--;
	f->p_length = ++end;
	start = find_index_deviation(f);
	// printf("piece before - |%s|\n", f->piece);
	if (!(temp = ft_strsub(f->piece, start, f->p_length)))
		return (0);
	ft_strdel(&(f->piece));
	f->piece = temp;
	// printf("piece after - |%s|\n", f->piece);
	return (1);
}

int		find_index_deviation(t_filler *f)
{
	int		i;
	int		temp;
	int		error;

	i = 0;
	error = 1;
	while (f->piece[i] == '0')
	{
		temp = i;
		while (1)
		{
			temp += f->m_width;
			if (!error || (temp < f->p_length && f->piece[temp] != '0'))
			{
				error = 0;
				break ;
			}
			if (temp > f->p_length)
			{
				(f->dev_y)++;
				break ;
			}
		}
		if (i && !(i % f->m_width))
			(f->dev_x)++;
		i++;
	}
	temp = (f->dev_x * f->m_width) + f->dev_y;
	f->p_width -= f->dev_y;
	f->p_length -= temp;
	// printf("dev_x - %d, dev_y - %d, start - %d, length - %d\n", f->dev_x, f->dev_y, temp, f->p_length);
	return (temp);
}

void	get_size(int *width, int *height, int *length, char **line)
{
	int 	i;
	int		hw[2];
	char	*temp;

	i = 0;
	temp = *line;
	ft_bzero(hw, sizeof(hw));
	while (*temp)
	{
		if (ft_isdigit(*temp))
		{
			hw[i++] = ft_atoi(temp);
			while (ft_isdigit(*temp))
				temp++;
			continue ;
		}
		temp++;
	}
	*height = hw[0];
	*width = hw[1];
	*length = hw[0] * hw[1];
	ft_strdel(line);
}
