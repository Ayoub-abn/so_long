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
	data->player = mlx_xpm_file_to_image(data->mlx, "./imag/zorro.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->player);
	data->pp = mlx_xpm_file_to_image(data->mlx, "./imag/zorro2.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->pp);
	data->aaa = mlx_xpm_file_to_image(data->mlx, "./imag/zorro_attck3.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->aaa);
	data->aaaa = mlx_xpm_file_to_image(data->mlx, "./imag/zorro_attck4.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->aaaa);
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
	data->m = mlx_xpm_file_to_image(data->mlx, "./imag/Marine.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m);
	data->m_a = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_attck.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m_a);
	data->m_a2 = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_attck2.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m_a2);
	data->m_a3 = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_attck3.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m_a3);
	data->m_a4 = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_attck4.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m_a4);
	data->m_a5 = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_attck5.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m_a5);
	data->m_a6 = mlx_xpm_file_to_image(data->mlx, "./imag/Marine_attck6.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->m_a6);
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

int	map(t_data *data)
{
	int			i;
	int			j;
	static int	frame_m = 0;

	i = 0;
	frame_m++;
	data->frame_p++;
	data->frame_m_a++;
	mlx_clear_window(data->mlx, data->win);
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			//mlx_string_put(data->mlx, data->win, 50, 0, 0x619b8a, "moves: ");
			//mlx_string_put(data->mlx, data->win, 150, 0, 0x619b8a,
				//ft_itoa(data->move));
			//mlx_string_put(data->mlx, data->win, 50, 20, 0x619b8a,
			//	"collectible: ");
			//mlx_string_put(data->mlx, data->win, 170, 20, 0x619b8a,
				//ft_itoa(data->co));
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
					if (data->frame_p > 10)
					{
						data->i = 0;
						data->frame_p = 0;
					}
				}
				else if (data->i == 1 && data->zero_lfet == 1)
				{
					mlx_put_image_to_window(data->mlx, data->win, data->aa, j
						* 60, i * 60);
					if (data->frame_p > 10)
					{
						data->i = 0;
						data->frame_p = 0;
					}
				}
				else if (data->zero_lfet == 3)
				{
					mlx_put_image_to_window(data->mlx, data->win, data->pp, j
						* 60, i * 60);
				}
				else if (data->zero_right == 2)
				{
					mlx_put_image_to_window(data->mlx, data->win, data->player,
						j * 60, i * 60);
				}
				else
					mlx_put_image_to_window(data->mlx, data->win, data->player,
						j * 60, i * 60);
			}
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
			if (data->map[i][j] == 'M')
			{
				if (data->check == 0 && (data->map[i][j - 1] == '0' || data->map[i][j- 1] == 'P'))
				{
					if (data->frame_m_a < 20)
						mlx_put_image_to_window(data->mlx, data->win, data->m_a,
							j * 60, i * 60);
					else if (data->frame_m_a < 50)
						mlx_put_image_to_window(data->mlx, data->win,
							data->m_a2, j * 60, i * 60);
					else if (data->frame_m_a < 200)
					{
						mlx_put_image_to_window(data->mlx, data->win,
							data->m_a3, j * 60, i * 60);
						data->frame_m_a = 0;
					}
					if (frame_m > 80)
					{
						if (data->map[i][j - 1] == 'P')
						{
							ft_putstr("KHESRTI :(");
							exit(1);
						}
						else
						{
							data->map[i][j] = '0';
							data->map[i][j - 1] = 'M';
							frame_m = 0;
						}
					}
				}
				else if (data->map[i][j - 1] == '1')
					data->check = 1;
				if (data->check == 1 && (data->map[i][j + 1] == '0' || data->map[i][j+ 1] == 'P'))
				{
					if (data->frame_m_a < 20)
						mlx_put_image_to_window(data->mlx, data->win, data->m_a6,
							j * 60, i * 60);
					else if (data->frame_m_a < 50)
						mlx_put_image_to_window(data->mlx, data->win,
							data->m_a4, j * 60, i * 60);
					else if (data->frame_m_a < 200)
					{
						mlx_put_image_to_window(data->mlx, data->win,
							data->m_a5, j * 60, i * 60);
						data->frame_m_a = 0;
					}
					if (frame_m > 80)
					{
						if (data->map[i][j + 1] == 'P')
						{
							ft_putstr("KHESRTI :(");
							exit(1);
						}
						else
						{
							data->map[i][j] = '0';
							data->map[i][j + 1] = 'M';
							frame_m = 0;
						}
					}
				}
				else if ( data->map[i][j + 1] == '1')
					data->check = 0;
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
	//printf("jbcdskhhcgdjkcgds");
	// m_move(&data);
	mlx_loop_hook(data.mlx, map, &data);
	mlx_loop(data.mlx);
	
}
