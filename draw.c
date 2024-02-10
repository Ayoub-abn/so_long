/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:30:32 by aabdenou          #+#    #+#             */
/*   Updated: 2024/02/07 20:30:34 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_data *data, int i, int j)
{
	p_w_h(data);
	if (data->zero_lfet == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->p2, j * 60, i * 60);
	else if (data->zero_right == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->p, j * 60, i * 60);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->p, j * 60, i * 60);
}

void	map_draw(t_data *data, int i, int j)
{
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
	else
	{
		p_w_h(data);
		draw_player(data, data->p_h, data->p_w);
	}
}

void	win_con(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->w * 60, data->h * 60,
			"SO_LONG");
	data->one = mlx_xpm_file_to_image(data->mlx, "./imag/lhayet.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->one);
	data->p = mlx_xpm_file_to_image(data->mlx, "./imag/zorro.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->p);
	data->open = mlx_xpm_file_to_image(data->mlx, "./imag/sanigo2.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->open);
	data->p2 = mlx_xpm_file_to_image(data->mlx, "./imag/zorro2.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->p2);
	data->zero = mlx_xpm_file_to_image(data->mlx, "./imag/lared.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->zero);
	data->c = mlx_xpm_file_to_image(data->mlx, "./imag/bottle.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->c);
	data->e = mlx_xpm_file_to_image(data->mlx, "./imag/sanigo1.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->e);
}

int	all_collected(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(1);
	return (0);
}
