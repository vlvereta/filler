/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2018/04/18 10:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <math.h>
# include <stdio.h>
# include "./../libft/includes/libft.h"

# define ERROR -2147483648

typedef struct	s_filler
{
	char		player;
	char		enemy;
	char		*map;
	int			m_width;
	int			m_height;
	int			m_length;
	char		*piece;
	int 		p_width;
	int 		p_height;
	int			p_length;
	int			dev_x;
	int			dev_y;
}				t_filler;

typedef struct	s_pp
{
	int			index;
	int			distance;
	struct s_pp	*next;
}				t_pp;

void			game_loop(t_filler *f);
int				get_info(t_filler *f);
void			get_player_number(t_filler *f, char **line);
int				get_map(t_filler *f, char **line);
int				map_whl(t_filler *f, char **line);
int				get_piece(t_filler *f, char **line);
int				piece_expand(t_filler *f);
int				trim_piece(t_filler *f);
void			get_size(int *width, int *height, int *length, char **line);
int				find_index_deviation(t_filler *f);
int				find_position(t_filler *f);
int				check_position(int j, t_filler *f);
t_pp			*new_node(int index);
int				find_min_distance_1(int index, t_filler *f);
int				find_min_distance_2(int player, t_filler *f);
int				find_distance(int player, int enemy, int width);
t_pp			*add_front(t_pp **head, t_pp *node);
int				find_best_position(t_pp **head);
void			clean_list(t_pp **head);
void			print_answer(int index, t_filler *f);
void			clean_structure(t_filler **f);

#endif
