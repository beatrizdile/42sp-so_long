/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:20:34 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/18 16:20:47 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	name_check(t_map *map)
{
	int	len;
	int	flag;

	flag = 0;
	len = ft_strlen(map->file);
	if (len >= 5)
	{
		if (map->file[len - 1] == 'r' && map->file[len - 2] == 'e'
			&& map->file[len - 3] == 'b' && map->file[len - 4] == '.'
			&& map->file[len - 5] != '.')
			flag = 1;
	}
	if (flag != 1)
	{
		ft_printf("Error in map validation: invalid map name.\n");
		free_maps(map);
		exit(1);
	}
}

void	no_file(int	fd)
{
	if (fd == -1)
	{
		ft_printf("Error in map validation: invalid map file.\n");
		exit(1);
	}
}
