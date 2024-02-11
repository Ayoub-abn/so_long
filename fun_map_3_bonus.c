/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_map_3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:49:13 by aabdenou          #+#    #+#             */
/*   Updated: 2024/02/10 14:49:16 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_draw(t_data *data, int i, int j)
{
	put_str(data);
	mlx_put_image_to_window(data->mlx, data->win, data->zero, j * 60, i * 60);
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->one, j * 60, i
			* 60);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->zero, j * 60, i
			* 60);
	else if (data->map[i][j] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->e, j * 60, i * 60);
		if (all_collected(data))
			mlx_put_image_to_window(data->mlx, data->win, data->open, j * 60, i
				* 60);
	}
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->c, j * 60, i * 60);
	if (data->map[i][j] == 'M')
		draw_marines(data, i, j);
	else
	{
		p_w_h(data);
		draw_player(data, data->p_h, data->p_w);
	}
}
