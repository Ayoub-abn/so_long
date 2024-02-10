/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_con_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:00:17 by aabdenou          #+#    #+#             */
/*   Updated: 2024/02/10 15:00:19 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	imag_xpm(data);
	imag_xpm_2(data);
}

void	imag_xpm(t_data *data)
{
	data->m2 = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_attck2.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m2);
	data->m3 = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_attck3.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m3);
	data->m4 = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_attck4.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m4);
	data->m5 = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_attck5.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m5);
	data->m6 = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_attck6.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m6);
	data->a = mlx_xpm_file_to_image(data->mlx, "./imag/zorro_attck.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->a);
	data->a2 = mlx_xpm_file_to_image(data->mlx, "./imag/zorro_attck2.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->a2);
	data->open = mlx_xpm_file_to_image(data->mlx, "./imag/sanigo2.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->open);
}

void	imag_xpm_2(t_data *data)
{
	xpm_check(data->p);
	data->p2 = mlx_xpm_file_to_image(data->mlx, "./imag/zorro2.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->p2);
	data->zorro_move = mlx_xpm_file_to_image(data->mlx, "./imag/zorro_move.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->zorro_move);
	data->zorro_move2 = mlx_xpm_file_to_image(data->mlx,
			"./imag/zorro_move2.xpm", &data->image_w, &data->image_h);
	xpm_check(data->zorro_move2);
	data->zero = mlx_xpm_file_to_image(data->mlx, "./imag/lared.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->zorro_move2);
	data->c = mlx_xpm_file_to_image(data->mlx, "./imag/bottle.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->c);
	data->e = mlx_xpm_file_to_image(data->mlx, "./imag/sanigo1.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->e);
	data->m = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_attck.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m);
}

void	xpm_check(t_data *ptr)
{
	if (ptr == NULL)
	{
		ft_putstr("TSWIRA MAKAYNACH");
		exit(1);
	}
}
