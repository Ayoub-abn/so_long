/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:22:32 by aabdenou          #+#    #+#             */
/*   Updated: 2024/01/29 17:22:33 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_data *data)
{
	if (data->map[data->p_h - 1][data->p_w] == 'M')
	{
		ft_putstr("KHESERTI :)");
		exit(1);
	}
	else
	{
		data->map[data->p_h][data->p_w] = '0';
		data->map[data->p_h - 1][data->p_w] = 'P';
	}
}

void	down(t_data *data)
{
	if (data->map[data->p_h + 1][data->p_w] == 'M')
	{
		ft_putstr("KHESERTI :)");
		exit(1);
	}
	else
	{
		data->map[data->p_h][data->p_w] = '0';
		data->map[data->p_h + 1][data->p_w] = 'P';
	}
}

void	left(t_data *data)
{
	if (data->map[data->p_h][data->p_w - 1] == 'M')
	{
		ft_putstr("KHESERTI :)");
		exit(1);
	}
	else
	{
		data->zero_lfet = 3;
		data->zero_right = 0;
		data->map[data->p_h][data->p_w] = '0';
		data->map[data->p_h][data->p_w - 1] = 'P';
	}
}

void	right(t_data *data)
{
	if (data->map[data->p_h][data->p_w + 1] == 'M')
	{
		ft_putstr("KHESERTI :)");
		exit(1);
	}
	else
	{
		data->zero_right = 2;
		data->zero_lfet = 0;
		data->map[data->p_h][data->p_w] = '0';
		data->map[data->p_h][data->p_w + 1] = 'P';
	}
}

int	move(int keycode, t_data *data)
{
	if (keycode == 86 && (data->map[data->p_h][data->p_w - 1] == 'M'
		|| data->map[data->p_h][data->p_w - 1] == '0'))
		attack_left(data);
	else if (keycode == 88 && (data->map[data->p_h][data->p_w + 1] == 'M'
		|| data->map[data->p_h][data->p_w + 1] == '0'))
		attack_right(data);
	else if (keycode == 13)
		up_1(data);
	else if (keycode == 0)
		left_1(data);
	else if (keycode == 1)
		down_1(data);
	else if (keycode == 2)
		right_1(data);
	else if (keycode == 53)
	{
		system("leaks so_long");
		exit(1);
	}
	return (0);
}
