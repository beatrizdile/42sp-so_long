/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:37:00 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/18 12:13:32 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(t_map	*map)
{
	valid_map_name(map);
	chrs_checks(map);
}

// If the name of the map is valid

// Your program has to take as parameter a map description file ending with the .ber
//extension.

//If the map contains a duplicates characters (exit/start), you should
//display an error message.

//The map must be rectangular.

//The map must be closed/surrounded by walls. If it’s not, the program must returns
//an error.

//You have to check if there’s a valid path in the map.

//You must be able to parse any kind of map, as long as it respects the above rules.

// um arquivo apenas .ber - n valido