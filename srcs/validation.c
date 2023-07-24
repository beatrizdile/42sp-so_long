/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:37:00 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/21 16:45:00 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(t_map	*map)
{
	name_check(map);
	size_check(map);
	chrs_checks(map);
	wall_check(map);
	flood_fill(map);
}

void	free_for_finish(t_data *data)
{
	free_images(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_maps(data->map);
	free(data->mlx_ptr);
	exit(1);
}
