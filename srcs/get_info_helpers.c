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

#include "./../includes/filler.h"

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
	char	*temp;

	end = f->p_length - 1;
	while (end > 0 && (f->piece)[end] == '0')
		end--;
	f->p_length = ++end;
	if (!(temp = ft_strsub(f->piece, 0, f->p_length)))
		return (0);
	ft_strdel(&(f->piece));
	f->piece = temp;
	return (1);
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
