/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:03:52 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/24 10:26:20 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_libx(t_data *data, t_map *map)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_printf("Error in max_init function.\n");
		exit(1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, (map->m_columns * 64),
			(map->m_lines * 64), "so_long");
	if (data->win_ptr == NULL)
	{
		ft_printf("Error in max_new_window function.\n");
		free(data->win_ptr);
		exit(1);
	}
}

void	get_map(t_map *map)
{
	int		j;
	int		fd;
	char	*str;

	j = 0;
	map->m_lines = 0;
	fd = open(map->file, O_RDONLY);
	no_file(fd);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		map->m_lines++;
		free(str);
	}
	close(fd);
	map->m_chrs = ft_calloc(sizeof(char *), map->m_lines);
	fd = open(map->file, O_RDONLY);
	while (j < map->m_lines)
		map->m_chrs[j++] = get_next_line(fd);
	str = get_next_line(fd);
	free(str);
	close(fd);
	map->m_columns = (int)ft_strlen(map->m_chrs[0]) - 1;
}

int	get_images(t_map *map, t_data *data)
{
	map->moves = 0;
	data->img->img1 = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &data->img->x,
			&data->img->y);
	data->img->img2 = mlx_xpm_file_to_image(data->mlx_ptr, JAMES, &data->img->x,
			&data->img->y);
	data->img->img3 = mlx_xpm_file_to_image(data->mlx_ptr, PIKACHU,
			&data->img->x, &data->img->y);
	data->img->img4 = mlx_xpm_file_to_image(data->mlx_ptr, POKEBALL,
			&data->img->x, &data->img->y);
	data->img->img5 = mlx_xpm_file_to_image(data->mlx_ptr, STAIR, &data->img->x,
			&data->img->y);
	data->img->img6 = mlx_xpm_file_to_image(data->mlx_ptr, STONE, &data->img->x,
			&data->img->y);
	if (data->img->img1 == NULL || data->img->img2 == NULL
		|| data->img->img3 == NULL || data->img->img4 == NULL
		|| data->img->img5 == NULL || data->img->img6 == NULL)
		free_for_finish(data);
	put_images(map, data);
	return (1);
}

void	put_images(t_map *map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	find_chr(map, 'P');
	exit_check(map);
	while (i < map->m_lines)
	{
		j = 0;
		while (j < map->m_columns)
		{
			if (map->m_chrs[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img->img1, (64 * j), (64 * i));
			else if (map->m_chrs[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img->img6, (64 * j), (64 * i));
			else if (map->m_chrs[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img->img4, (64 * j), (64 * i));
			else if (map->m_chrs[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img->img5, (64 * j), (64 * i));
			else if (map->m_chrs[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img->img3, (64 * j), (64 * i));
			else if (map->m_chrs[i][j] == 'X')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img->img2, (64 * j), (64 * i));
			j++;
		}
		i++;
	}
}

void	exit_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->m_lines)
	{
		j = 0;
		while (j < map->m_columns)
		{
			if (map->m_chrs[i][j] == 'E')
			{
				map->exit_x = i;
				map->exit_y = j;
			}
			j++;
		}
		i++;
	}
	if (find_chr(map, 'C') && map->player_x != map->exit_x
		&& map->player_y != map->exit_y)
		map->m_chrs[map->exit_x][map->exit_y] = '0';
	else if (!find_chr(map, 'C'))
		map->m_chrs[map->exit_x][map->exit_y] = 'E';
}

void	hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, &handle_x_press, data);
	mlx_loop(data->mlx_ptr);
}
