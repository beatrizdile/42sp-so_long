/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:04:18 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/19 18:40:22 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	map_dup(map);
	while (x < map->m_lines)
	{
		y = 0;
		while (y < map->m_rows)
		{
			if (map->c_str[x][y] == 'P')
				fill(map, x, y);
			y++;
		}
		x++;
	}
	path_check(map);
}

void	path_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->m_lines)
	{
		j = 0;
		while (j < map->m_rows)
		{
			if (map->c_str[i][j] == 'E' || map->c_str[i][j] == 'C')
				path_error(map, 1);
			j++;
		}
		i++;
	}
	path_error(map, 0);
}

void	path_error(t_map *map, int flag)
{
	int	i;

	if (flag == 1)
	{
		i = 0;
		ft_printf("Error in map validation: invalid path.\n");
		while (i < map->m_lines)
		{
			free(map->c_str[i]);
			i++;
		}
		free(map->c_str);
		free_maps(map);
		exit(1);
	}
	else
	{
		i = 0;
		while (i < map->m_lines)
		{
			free(map->c_str[i]);
			i++;
		}
		free(map->c_str);
	}
}

void	fill(t_map *map, int x, int y)
{
	if (y < 0 || y > map->m_rows || x < 0 || x >= map->m_lines
		|| (map->c_str[x][y] != '0' && map->c_str[x][y] != 'P'
			&& map->c_str[x][y] != 'C' && map->c_str[x][y] != 'E'))
		return ;
	map->c_str[x][y] = '1';
	fill(map, x - 1, y);
	fill(map, x, y - 1);
	fill(map, x + 1, y);
	fill(map, x, y + 1);
}

void	map_dup(t_map *map)
{
	int i;

	i = 0;
	map->c_str = ft_calloc(sizeof(char *), map->m_lines);
	while (i < map->m_lines)
	{
		map->c_str[i] = ft_strdup(map->m_str[i]);
		i++;
	}
}