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
		data->map[data->p_h][data->p_w] = '0';
		data->map[data->p_h][data->p_w + 1] = 'P';
	}
}

int	move(int keycode, t_data *data)
{

	//int i = 0;
	if (keycode == 40)
	{
		if (data->map[data->p_h][data->p_w - 1] == '0'
			|| data->map[data->p_h][data->p_w - 1] == 'M')
		{
			 data->map[data->p_h][data->p_w - 1] = '0';
			//i = 1;
			data->i = 1;
			data->z = 0;
		}
	}
	if (keycode == 37)
	{
		if (data->map[data->p_h][data->p_w + 1] == '0'
			|| data->map[data->p_h][data->p_w + 1] == 'M')
		{
			 data->map[data->p_h][data->p_w + 1] = '0';
			// i = 1;
			data->i = 1;
			data->z = 0;
		}
	}
	else if (keycode == 13)
	{
		if (data->map[data->p_h - 1][data->p_w] != '1' && data->map[data->p_h
			- 1][data->p_w] != 'E')
			up(data);
	}
	else if (keycode == 0)
	{
		if (data->map[data->p_h][data->p_w - 1] != '1'
			&& data->map[data->p_h][data->p_w - 1] != 'E')
			left(data);
	}
	else if (keycode == 1)
	{
		if (data->map[data->p_h + 1][data->p_w] != '1' && data->map[data->p_h
			+ 1][data->p_w] != 'E')
			down(data);
	}
	else if (keycode == 2)
	{
		if (data->map[data->p_h][data->p_w + 1] != '1'
			&& data->map[data->p_h][data->p_w + 1] != 'E')
			right(data);
	}
	else if (keycode == 53)
		exit(1);
	
	//map(data);
	// if (i == 1)
	// {
	// 	sleep(1);
	// 	printf("jf\n");
	// 	mlx_clear_window(data->mlx, data->win);
		//map2(data);
	// }
		
	return (0);
}
