/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:03:52 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/18 17:17:58 by bedos-sa         ###   ########.fr       */
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
	data->win_ptr = mlx_new_window(data->mlx_ptr, (map->m_rows * 64),
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
		map->m_rows = ft_strlen(str);
		free(str);
	}
	close(fd);
	map->m_str = ft_calloc(sizeof(char *), map->m_lines);
	fd = open(map->file, O_RDONLY);
	while (j < map->m_lines)
		map->m_str[j++] = get_next_line(fd);
	str = get_next_line(fd);
	free(str);
	close(fd);
}

int	get_images(t_map *map, t_data *data)
{
	map->img1 = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &map->x, &map->y);
	map->img2 = mlx_xpm_file_to_image(data->mlx_ptr, JAMES, &map->x, &map->y);
	map->img3 = mlx_xpm_file_to_image(data->mlx_ptr, PIKACHU, &map->x, &map->y);
	map->img4 = mlx_xpm_file_to_image(data->mlx_ptr, POKEBALL, &map->x,
			&map->y);
	map->img5 = mlx_xpm_file_to_image(data->mlx_ptr, STAIR, &map->x, &map->y);
	map->img6 = mlx_xpm_file_to_image(data->mlx_ptr, STONE, &map->x, &map->y);
	if (map->img1 == NULL || map->img2 == NULL || map->img3 == NULL
		|| map->img4 == NULL || map->img5 == NULL || map->img6 == NULL)
		free_for_finish(data);
	put_images(map, data);
	return (1);
}

void	put_images(t_map *map, t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < map->m_lines)
	{
		j = 0;
		while (j < map->m_rows)
		{
			if (map->m_str[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map->img1,
					(64 * j), (64 * i));
			else if (map->m_str[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map->img6,
					(64 * j), (64 * i));
			else if (map->m_str[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map->img4,
					(64 * j), (64 * i));
			else if (map->m_str[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map->img5,
					(64 * j), (64 * i));
			else if (map->m_str[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map->img3,
					(64 * j), (64 * i));
			else if (map->m_str[i][j] == 'X')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map->img2,
					(64 * j), (64 * i));
			j++;
		}
		i++;
	}
}

void	hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, &handle_x_press, data);
	mlx_loop(data->mlx_ptr);
}
