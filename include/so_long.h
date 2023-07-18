/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:37:48 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/18 12:13:02 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FLOOR "sprites/floor_64.xpm"
# define JAMES "sprites/james_64.xpm"
# define PIKACHU "sprites/pikachu_d1_64.xpm"
# define POKEBALL "sprites/pokeball_64.xpm"
# define STAIR "sprites/stair_64.xpm"
# define STONE "sprites/stone_64.xpm"

typedef struct s_map
{
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	char	*file;
	char	**m_str;
	int		m_lines;
	size_t	m_rows;
	int		x;
	int		y;
}			t_map;

typedef struct s_data
{
	t_map	*map;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

void		init_libx(t_data *data, t_map *map);
void		get_map(t_map *map);
int			get_images(t_map *map, t_data *data);
void		put_images(t_map *map, t_data *data);
void		hooks(t_data *data);
void		free_for_finish(t_data *data);
int			handle_no_event(void *data);
int			handle_keypress(int keysym, t_data *data);
int			handle_x_press(t_data *data);
void		free_maps(t_map	*map);
void		free_images(t_data	*data);
void		valid_map(t_map	*map);
void		chrs_checks(t_map *map);
void		chr_error(int	exited, int	player, int	collect, t_map	*map);
void		chr_error_two(int	player, t_map	*map);
void		valid_map_name(t_map	*map);

#endif