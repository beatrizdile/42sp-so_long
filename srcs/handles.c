/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:05:57 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/24 10:27:32 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("Game closed.\n");
		free_for_finish(data);
	}
	else if (keysym == 119 || keysym == 97 || keysym == 115 || keysym == 100)
		movement_check(keysym, data, data->map);
	return (1);
}

int	handle_x_press(t_data *data)
{
	ft_printf("Game closed.\n");
	free_for_finish(data);
	return (1);
}

void	free_maps(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->m_lines)
	{
		free(map->m_chrs[i]);
		i++;
	}
	free(map->m_chrs);
}

void	free_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->img1);
	mlx_destroy_image(data->mlx_ptr, data->img->img2);
	mlx_destroy_image(data->mlx_ptr, data->img->img3);
	mlx_destroy_image(data->mlx_ptr, data->img->img4);
	mlx_destroy_image(data->mlx_ptr, data->img->img5);
	mlx_destroy_image(data->mlx_ptr, data->img->img6);
}
