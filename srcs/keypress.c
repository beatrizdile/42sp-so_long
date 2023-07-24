/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:27:33 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/24 15:45:07 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_check(int keysym, t_data *data, t_map *map)
{
	t_frame	frame;

	find_chr(map, 'P');
	frame.x = map->player_x;
	frame.y = map->player_y;
	frame.i = map->player_x;
	frame.j = map->player_y;
	if (keysym == 119 && map->m_chrs[frame.x - 1][frame.y] != '1')
		frame.i -= 1;
	else if (keysym == 97 && map->m_chrs[frame.x][frame.y - 1] != '1')
		frame.j -= 1;
	else if (keysym == 115 && map->m_chrs[frame.x + 1][frame.y] != '1')
		frame.i += 1;
	else if (keysym == 100 && map->m_chrs[frame.x][frame.y + 1] != '1')
		frame.j += 1;
	if (frame.i != map->player_x || frame.j != map->player_y)
		new_frame(data, &frame);
}

void	new_frame(t_data *data, t_frame *frame)
{
	data->map->moves += 1;
	ft_printf("Moves: %d\n", data->map->moves);
	if (data->map->m_chrs[frame->i][frame->j] == 'X'
		|| data->map->m_chrs[frame->i][frame->j] == 'E')
	{
		if (data->map->m_chrs[frame->i][frame->j] == 'X')
			ft_printf("Game Over.\n");
		else
			ft_printf("You Win.\n");
		free_for_finish(data);
	}
	data->map->m_chrs[frame->x][frame->y] = '0';
	data->map->m_chrs[frame->i][frame->j] = 'P';
	put_images(data->map, data);
}

int	find_chr(t_map *map, char ch)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < map->m_lines)
	{
		j = 0;
		while (j < map->m_columns)
		{
			if (map->m_chrs[i][j] == ch && ch == 'P')
			{
				map->player_x = i;
				map->player_y = j;
			}
			if (map->m_chrs[i][j] == ch)
				flag++;
			j++;
		}
		i++;
	}
	return (flag);
}
