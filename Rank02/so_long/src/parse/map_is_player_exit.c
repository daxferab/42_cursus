/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_player_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:27:50 by daxferna          #+#    #+#             */
/*   Updated: 2025/07/24 17:39:51 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_player(int row, int col, t_map *game)
{
	if (game->map[row][col] == PLAYER)
	{
		game->pla_x = col;
		game->pla_y = row;
		return (true);
	}
	return (false);
}

bool	is_exit(int row, int col, t_map *game)
{
	if (game->map[row][col] == EXIT)
	{
		game->exit_x = col;
		game->exit_y = row;
		return (true);
	}
	return (false);
}
