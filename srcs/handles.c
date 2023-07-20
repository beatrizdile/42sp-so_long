/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:05:57 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/20 18:39:50 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *data)
{
	/* This is where we will refresh the images */
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
	ft_printf("Keypress: %d\n", keysym);
	return (1);
}

int	handle_x_press(t_data *data)
{
	ft_printf("Game closed.\n");
	free_for_finish(data);
	return (1);
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

void	free_maps(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->m_lines)
	{
		free(map->m_str[i]);
		i++;
	}
	free(map->m_str);
}

void	free_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->map->img1);
	mlx_destroy_image(data->mlx_ptr, data->map->img2);
	mlx_destroy_image(data->mlx_ptr, data->map->img3);
	mlx_destroy_image(data->mlx_ptr, data->map->img4);
	mlx_destroy_image(data->mlx_ptr, data->map->img5);
	mlx_destroy_image(data->mlx_ptr, data->map->img6);
}
