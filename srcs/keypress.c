/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:27:33 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/20 19:02:12 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_check(int keysym, t_data *data, t_map *map)
{
	int	x;
	int	y;

	find_chr(map, 'P');
	x = map->p_x;
	y = map->p_y;
	if (keysym == 119)
		if (map->m_str[x - 1][y] != '1')
			new_frame(data, x, y, x - 1, y);
	if (keysym == 97)
		if (map->m_str[x][y - 1] != '1')
			new_frame(data, x, y, x, y - 1);
	if (keysym == 115)
		if (map->m_str[x + 1][y] != '1')
			new_frame(data, x, y, x + 1, y);
	if (keysym == 100)
		if (map->m_str[x][y + 1] != '1')
			new_frame(data, x, y, x, y + 1);
}

void	new_frame(t_data *data, int x, int y, int i, int j)
{
	if (data->map->m_str[i][j] == 'X')
		free_for_finish(data);
	if (data->map->m_str[i][j] == 'E')
		exit_check(data, data->map);
	data->map->m_str[x][y] = '0';
	data->map->m_str[i][j] = 'P';
	data->map->moves += 1;
	ft_printf("Moves: %d\n", data->map->moves);
	put_images(data->map, data);
}

void	exit_check(t_data *data, t_map *map)
{
	if (find_chr(map, 'C'))
		return ;
	else
		free_for_finish(data);
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
		while (j < map->m_rows)
		{
			if (map->m_str[i][j] == ch && ch == 'P')
			{
				map->p_x = i;
				map->p_y = j;
			}
			if (map->m_str[i][j] == ch)
				flag++;
			j++;
		}
		i++;
	}
	return (flag);
}
