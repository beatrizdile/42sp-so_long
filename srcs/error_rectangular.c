/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_rectangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:31:29 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/19 18:04:41 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_check(t_map *map)
{
	int	i;
	int	len;
	int	n_len;

	i = 0;
	len = (int)ft_strlen(map->m_str[0]);
	while (i < map->m_lines)
	{
		n_len = (int)ft_strlen(map->m_str[i]);
		if (i == map->m_lines - 1)
			n_len++;
		if (len != n_len)
		{
			ft_printf("Error in map validation: invalid map size.\n");
			free_maps(map);
			exit(1);
		}
		i++;
	}
}

void	invalid_chrs_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->m_lines)
	{
		j = 0;
		while (j < map->m_rows)
		{
			if (map->m_str[i][j] != '1' && map->m_str[i][j] != '0'
				&& map->m_str[i][j] != 'X' && map->m_str[i][j] != 'E'
				&& map->m_str[i][j] != 'C' && map->m_str[i][j] != 'P')
			{
				ft_printf("Error in map validation: invalid character in map.\n");
				free_maps(map);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
