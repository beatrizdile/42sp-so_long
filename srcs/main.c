/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:10:20 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/21 14:59:24 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;
	t_img	img;

	if (argc != 2)
		exit(1);
	data.map = &map;
	data.img = &img;
	map.file = argv[1];
	get_map(&map);
	valid_map(&map);
	init_libx(&data, &map);
	get_images(&map, &data);
	hooks(&data);
	return (0);
}

// add pause/help button
// death animation
// game over on screen
// menu