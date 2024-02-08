/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:47:06 by aabdenou          #+#    #+#             */
/*   Updated: 2024/01/27 23:47:08 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	path_check(char *path)
{
	if (ft_strcmp(&path[ft_strlen(path) - 4], ".ber") != 0)
	{
		ft_putstr("MAP PATH IMVALIDE");
		exit(1);
	}
}

void	p_w_h(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->map[i][j] == 'P')
			{
				data->p_h = i;
				data->p_w = j;
			}
			j++;
		}
		i++;
	}
}

void	xpm_check(void *ptr)
{
	if (ptr == NULL)
	{
		ft_putstr("TSWIRA MAKAYNACH");
		exit(1);
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
	imag_xpm_2(data);
	imag_xpm(data);
}

void	flood_fill(t_data *data, int x, int y)
{
	if (data->p_h < 0 || data->p_w < 0 || data->p_h >= data->h
		|| data->p_w >= data->w)
		return ;
	if (data->map2[y][x] != '0' && data->map2[y][x] != 'C'
		&& data->map2[y][x] != 'E' && data->map2[y][x] != 'P')
		return ;
	data->map2[y][x] = 'X';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}

void	flood_fill_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->map2[i][j] == 'E' || data->map2[i][j] == 'C'
				|| data->map2[i][j] == 'P')
			{
				ft_putstr("L MAP MAYMKNCH LIHA TREBAH");
				exit(1);
			}
			j++;
		}
		i++;
	}
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
// void	all_marines(t_data *data)
// {
// 	int	i;
// 	int	j;
// 	int m;

// 	i = 0;
// 	m = 0;
// 	while (i < data->h)
// 	 {
// 	 	j = 0;
// 	 	while (j < data->w)
// 	 	{
// 			if (data->map[i][j] == 'M')
// 	 		{
// 				// printf("i=>%d\n",i);
// 				// printf("j=>%d\n",j);
// 				check_marines(data, i, j);
// 	 		}
// 	 		j++;
// 			m++;
// 	 	}
// 	 	i++;
// 	}
// }

int	map(t_data *data)
{
	int	i;
	int	j;
	int	m;

	m = 0;
	i = 0;
	data->frame_m++;
	data->frame_p++;
	data->frame_m_a++;
	mlx_clear_window(data->mlx, data->win);
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			put_str(data);
			mlx_put_image_to_window(data->mlx, data->win, data->zero, j * 60, i
				* 60);
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->one, j * 60,
					i * 60);
			else if (data->map[i][j] == 'P')
				draw_player(data, i, j);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->zero, j
					* 60, i * 60);
			else if (data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->e, j * 60, i
					* 60);
				if (all_collected(data))
					mlx_put_image_to_window(data->mlx, data->win, data->open, j
						* 60, i * 60);
			}
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->c, j * 60, i
					* 60);
			
			if (data->map[i][j] == 'M' )
				//all_marines(data);
					check_marines(data, i, j);
					//m++;
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.move = 0;
	data.i = 0;
	data.frame_p = 0;
	data.frame_m_a = 0;
	data.check = 0;
	data.zero_lfet = 0;
	data.zero_right = 0;
	data.attack_lfet = 0;
	data.attack_right = 0;
	data.zero_up = 0;
	data.zero_down = 0;
	data.co = 0;
	data.frame_m = 0;
	if (argc != 2)
	{
		ft_putstr("NUMBER OF PARAMS PROBLEM");
		return (1);
	}
	path_check(argv[1]);
	map_check(argv[1], &data);
	map_w(argv[1], &data);
	map_arr(argv[1], &data);
	map_arr2(argv[1], &data);
	win_con(&data);
	map_border(&data);
	map_content_p1(&data);
	p_w_h(&data);
	flood_fill(&data, data.p_w, data.p_h);
	flood_fill_check(&data);
	mlx_key_hook(data.win, move, &data);
	mlx_loop_hook(data.mlx, map, &data);
	mlx_loop(data.mlx);
}
