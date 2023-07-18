/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:10:29 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/18 16:50:41 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chrs_checks(t_map *map)
{
	int		collect;
	int		exited;
	int		player;
	int		i;
	size_t	j;

	i = 0;
	collect = 0;
	exited = 0;
	player = 0;
	while (i < map->m_lines)
	{
		j = 0;
		while (j++ < map->m_rows)
		{
			if (map->m_str[i][j] == 'E')
				exited++;
			else if (map->m_str[i][j] == 'P')
				player++;
			else if (map->m_str[i][j] == 'C')
				collect++;
		}
		i++;
	}
	chr_error(exited, player, collect, map);
}

void	chr_error(int exited, int player, int collect, t_map *map)
{
	if (exited == 0)
	{
		ft_printf("Error in map validation: missing an exit.\n");
		free_maps(map);
		exit(1);
	}
	else if (exited > 1)
	{
		ft_printf("Error in map validation: more than one exit.\n");
		free_maps(map);
		exit(1);
	}
	else if (collect == 0)
	{
		ft_printf("Error in map validation: missing a collectible.\n");
		free_maps(map);
		exit(1);
	}
	chr_error_two(player, map);
}

void	chr_error_two(int player, t_map *map)
{
	if (player == 0)
	{
		ft_printf("Error in map validation: missing a player.\n");
		free_maps(map);
		exit(1);
	}
	else if (player > 1)
	{
		ft_printf("Error in map validation: more than one player.\n");
		free_maps(map);
		exit(1);
	}
}

void	wall_check(t_map *map)
{
	int	i;

	i = 0;
	while (i < (int)map->m_rows)
	{
		if (map->m_str[0][i] != '1')
			wall_error(map);
		if (map->m_str[map->m_lines - 1][i] != '1')
			wall_error(map);
		i++;
	}
	i = 0;
	while (i < map->m_lines)
	{
		if (map->m_str[i][0] != '1')
			wall_error(map);
		if (map->m_str[i][map->m_rows - 1] != '1')
			wall_error(map);
		i++;
	}
}

void	wall_error(t_map *map)
{
	ft_printf("Error in map validation: not surrounded by walls.\n");
	free_maps(map);
	exit(1);
}
