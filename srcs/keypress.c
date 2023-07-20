/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:27:33 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/20 16:57:56 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_check(int keysym, t_data *data)
{
	int	x;
	int	y;

	find_player(data);
	x = data->map->p_x;
	y = data->map->p_y;
	if (keysym == 119)
		if (data->map->m_str[x - 1][y] != '1')
			new_frame(data, x, y, x - 1, y);
	if (keysym == 97)
		if (data->map->m_str[x][y - 1] != '1')
			new_frame(data, x, y, x, y - 1);
	if (keysym == 115)
		if (data->map->m_str[x + 1][y] != '1')
			new_frame(data, x, y, x + 1, y);
	if (keysym == 100)
		if (data->map->m_str[x][y + 1] != '1')
			new_frame(data, x, y, x, y + 1);
}

void	new_frame(t_data *data, int x, int y, int i, int j)
{
	data->map->m_str[x][y] = '0';
	data->map->m_str[i][j] = 'P';
	data->map->moves += 1;
	ft_printf("Moves: %d\n", data->map->moves);
	put_images(data->map, data);
}

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->m_lines)
	{
		j = 0;
		while (j < data->map->m_rows)
		{
			if (data->map->m_str[i][j] == 'P')
			{
				data->map->p_x = i;
				data->map->p_y = j;
			}
			j++;
		}
		i++;
	}
}
