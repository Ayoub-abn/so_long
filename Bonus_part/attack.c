/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:17:32 by aabdenou          #+#    #+#             */
/*   Updated: 2024/02/06 16:17:33 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	attack_left(t_data *data)
{
	data->map[data->p_h][data->p_w - 1] = '0';
	data->zero_lfet = 1;
	data->zero_right = 0;
	data->i = 1;
	data->frame_p = 0;
	data->attack_lfet = 86;
	data->attack_right = 0;
}

void	attack_right(t_data *data)
{
	data->map[data->p_h][data->p_w + 1] = '0';
	data->zero_right = 1;
	data->zero_lfet = 0;
	data->i = 1;
	data->frame_p = 0;
	data->attack_right = 88;
	data->attack_lfet = 0;
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
