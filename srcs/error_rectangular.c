/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_rectangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:31:29 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/21 16:37:16 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_check(t_map *map)
{
	int	i;
	int	len;
	int	n_len;

	i = 0;
	len = (int)ft_strlen(map->m_chrs[0]);
	while (i < map->m_lines)
	{
		n_len = (int)ft_strlen(map->m_chrs[i]);
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
		while (j < map->m_columns)
		{
			if (map->m_chrs[i][j] != '1' && map->m_chrs[i][j] != '0'
				&& map->m_chrs[i][j] != 'X' && map->m_chrs[i][j] != 'E'
				&& map->m_chrs[i][j] != 'C' && map->m_chrs[i][j] != 'P')
			{
				ft_printf("Error in map validation: invalid character.\n");
				free_maps(map);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
