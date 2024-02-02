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
// void	e_w_h(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < data->h)
// 	{
// 		j = 0;
// 		while (j < data->w)
// 		{
// 			if (data->map[i][j] == 'E')
// 			{
// 				data->m_h = i;
// 				data->m_w = j;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
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
	xpm_check(data->p);
	data->pp = mlx_xpm_file_to_image(data->mlx, "./imag/zorro2.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->pp);
	data->aaa = mlx_xpm_file_to_image(data->mlx, "./imag/zorro_attck3.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->aaa);
	data->aaaa = mlx_xpm_file_to_image(data->mlx, "./imag/zorro_attck4.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->aaaa);
	data->zero = mlx_xpm_file_to_image(data->mlx, "./imag/lared.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->zero);
	data->c = mlx_xpm_file_to_image(data->mlx, "./imag/bottle.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->c);
	data->e = mlx_xpm_file_to_image(data->mlx, "./imag/sanigo1.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->e);
	data->m = mlx_xpm_file_to_image(data->mlx, "./imag/Marine.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m);
	data->m_d = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_die.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m_d);
	data->m_d2 = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_die2.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m_d2);
	data->m_d3 = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_die3.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m_d3);
	data->a = mlx_xpm_file_to_image(data->mlx, "./imag/zorro_attck.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->a);
	data->aa = mlx_xpm_file_to_image(data->mlx, "./imag/zorro_attck2.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->aa);
	data->open = mlx_xpm_file_to_image(data->mlx, "./imag/sanigo2.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->open);
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
// void	m_move(t_data *data)
// {
// 	int	i;

// 	i = 1;
// 	while (data->map[data->m_h - i][data->m_w] == '0')
// 	{
// 		data->m_h -= 1;
// 		mlx_key_hook(data->win, move, data);
// 		i++;
// 	}

// }
int	map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->z++;
	data->zz++;
	mlx_clear_window(data->mlx, data->win);
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->zero, j * 60, i
				* 60);
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->one, j * 60,
					i * 60);
			else if (data->map[i][j] == 'P')
			{
				data->p_h = i;
				data->p_w = j;
				if (data->i == 1 && data->zero_right == 1)
				{
					mlx_put_image_to_window(data->mlx, data->win, data->a, j
						* 60, i * 60);
					if (data->z > 10)
					{
						data->i = 0;
						data->z = 0;
					}
				}
				else if (data->i == 1 && data->zero_lfet == 1)
				{
					mlx_put_image_to_window(data->mlx, data->win, data->aa, j
						* 60, i * 60);
					if (data->z > 10)
					{
						data->i = 0;
						data->z = 0;
					}
				}
				else if (data->i == 1 && data->zero_up == 1)
				{
					mlx_put_image_to_window(data->mlx, data->win, data->aaaa, j
						* 60, i * 60);
					if (data->z > 10)
					{
						data->i = 0;
						data->z = 0;
					}
				}
				else if (data->i == 1 && data->zero_down == 1)
				{
					mlx_put_image_to_window(data->mlx, data->win, data->aaa, j
						* 60, i * 60);
					if (data->z > 10)
					{
						data->i = 0;
						data->z = 0;
					}
				}
				else if (data->zero_lfet == 3)
				{
					mlx_put_image_to_window(data->mlx, data->win, data->pp, j
						* 60, i * 60);
				}
				else if (data->zero_right == 2)
				{
					mlx_put_image_to_window(data->mlx, data->win, data->p, j
						* 60, i * 60);
				}
				else
					mlx_put_image_to_window(data->mlx, data->win, data->p, j
						* 60, i * 60);
			}
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->zero, j
					* 60, i * 60);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->c, j * 60, i
					* 60);
			else if (data->map[i][j] == 'M')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->m, j * 60, i
					* 60);
			}
			// if (data->attack_lfet == 86
				//&& data->map[data->p_h][data->p_w- 1] == 'M')
			// {
			// 	mlx_put_image_to_window(data->mlx, data->win, data->m_d, j * 60,
			// 		i * 60);
			// 	if (data->zz > 100)
			// 	{
			// 		mlx_put_image_to_window(data->mlx, data->win, data->m_d2, j
			// 			* 60, i * 60);
			// 	}
			// 	else if (data->zz > 200)
			// 	{
			// 		mlx_put_image_to_window(data->mlx, data->win, data->m_d3, j
			// 			* 60, i * 60);
			// 		data->zz = 0;
			// 		data->i = 0;
			// 		data->attack_lfet = 0;
			// 		data->map[data->p_h][data->p_w - 1] = '0';
			// 	}
			// }
			else if (data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->e, j * 60, i
					* 60);
				if (all_collected(data))
					mlx_put_image_to_window(data->mlx, data->win, data->open, j
						* 60, i * 60);
			}
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
	data.z = 0;
	data.zz = 0;
	data.zero_lfet = 0;
	data.zero_right = 0;
	data.attack_lfet = 0;
	data.attack_right = 0;
	data.zero_up = 0;
	data.zero_down = 0;
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
	map_content_p2(&data);
	p_w_h(&data);
	flood_fill(&data, data.p_w, data.p_h);
	flood_fill_check(&data);
	mlx_key_hook(data.win, move, &data);
	//m_move(&data);
	mlx_loop_hook(data.mlx, map, &data);
	mlx_loop(data.mlx);
}
