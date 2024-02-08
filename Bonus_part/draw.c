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
	if (data->i == 1 && data->zero_right == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->a, j * 60, i * 60);
		if (data->frame_p > 10)
		{
			data->i = 0;
			data->frame_p = 0;
		}
	}
	else if (data->i == 1 && data->zero_lfet == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->a2, j * 60, i * 60);
		if (data->frame_p > 10)
		{
			data->i = 0;
			data->frame_p = 0;
		}
	}
	else if (data->zero_lfet == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->p2, j * 60, i * 60);
	else if (data->zero_right == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->p, j * 60, i * 60);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->p, j * 60, i * 60);
}

void	check_marines(t_data *data, int i, int j)
{
	if (data->check == 0 && (data->map[i][j - 1] == '0' || data->map[i][j
			- 1] == 'P'))
		draw_marines_1(data, i, j);
	if (data->map[i][j - 1] == '1')
		data->check = 1;
	if (data->check == 1 && (data->map[i][j + 1] == '0' || data->map[i][j
			+ 1] == 'P'))
		draw_marines_2(data, i, j);
	if (data->map[i][j + 1] == '1')
		data->check = 0;
}

void	draw_marines_1(t_data *data, int i, int j)
{
	if (data->frame_m_a < 20)
		mlx_put_image_to_window(data->mlx, data->win, data->m, j * 60, i * 60);
	else if (data->frame_m_a < 50)
		mlx_put_image_to_window(data->mlx, data->win, data->m2, j * 60, i * 60);
	else if (data->frame_m_a < 200)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->m3, j * 60, i * 60);
		data->frame_m_a = 0;
	}
	if (data->frame_m > 80)
	{
		// while (i < data->h)
		// {
		// 	j = 0;
		// 	while (j < data->w)
		// 	{
		// 		if (data->map[i][j] == 'M')
		// 		{
		// 			if (data->map[i][j - 1] == 'P')
		// 			{
		// 				ft_putstr("KHESRTI :(");
		// 				exit(1);
		// 			}
		// 			else
		// 			{
		// 				data->map[i][j] = '0';
		// 				data->map[i][j - 1] = 'M';
		// 				data->frame_m = 0;
		// 			}
		// 		}
		// 		j++;
		// 	}
		// 	i++;
		// }
			if (data->map[i][j - 1] == 'P')
		{
			ft_putstr("KHESRTI :(");
			exit(1);
		}
		else
		{
			data->map[i][j] = '0';
			data->map[i][j - 1] = 'M';
			data->frame_m = 0;
		}

		// i = 0;
	}
}
void	draw_marines_2(t_data *data, int i, int j)
{
	if (data->frame_m_a < 20)
		mlx_put_image_to_window(data->mlx, data->win, data->m6, j * 60, i * 60);
	else if (data->frame_m_a < 50)
		mlx_put_image_to_window(data->mlx, data->win, data->m4, j * 60, i * 60);
	else if (data->frame_m_a < 200)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->m5, j * 60, i * 60);
		data->frame_m_a = 0;
	}
	if (data->frame_m > 80)
	{
		// while (i < data->h)
		// {
		// 	j = 0;
		// 	while (j < data->w)
		// 	{
		// 		if (data->map[i][j] == 'M')
		// 		{
		// 			if (data->map[i][j + 1] == 'P')
		// 			{
		// 				ft_putstr("KHESRTI :(");
		// 				exit(1);
		// 			}
		// 			if(data->frame_m > 90)
		// 			//else
		// 			{
		// 				printf("i=>%d\n", i);
		// 				printf("j=>%d\n", j);
		// 				data->map[i][j] = '0';
		// 				data->map[i][j + 1] = 'M';
		// 				data->frame_m = 0;
		// 			}
		// 		}
		// 		j++;
		// 	}
		// 	i++;
		// }
		if (data->map[i][j + 1] == 'P')
		{
			ft_putstr("KHESRTI :(");
			exit(1);
		}
		else
		{
			data->map[i][j] = '0';
			data->map[i][j + 1] = 'M';
			data->frame_m = 0;
		}
	}
}

void	put_str(t_data *data)
{
	char	*str;

	mlx_string_put(data->mlx, data->win, 50, 0, 0x619b8a, "moves: ");
	str = ft_itoa(data->move);
	mlx_string_put(data->mlx, data->win, 150, 0, 0x619b8a, str);
	free(str);
}
