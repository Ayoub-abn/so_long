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
	xpm_check(data->p);
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
	data->a = mlx_xpm_file_to_image(data->mlx, "./imag/attack.xpm",
			&data->image_w, &data->image_h);
	xpm_check(data->a);
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

int all_collected(t_data *data)
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
				return(0);
			j++;
		}
		i++;
	}
	return(1);
}

void	map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
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
				mlx_put_image_to_window(data->mlx, data->win, data->p, j * 60, i
					* 60);
			}
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->c, j * 60, i
					* 60);
			else if (data->map[i][j] == 'A')
				mlx_put_image_to_window(data->mlx, data->win, data->a, j * 60, i
					* 60);
			else if (data->map[i][j] == 'M')
				mlx_put_image_to_window(data->mlx, data->win, data->m, j * 60, i
					* 60);
			else if (data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->e, j * 60, i
					* 60);
				if(all_collected(data))
					mlx_put_image_to_window(data->mlx, data->win, data->open, j * 60, i
					* 60);
			}
			j++;
		}
		i++;
	}
	
	mlx_key_hook(data->win, move, data);
	mlx_loop(data->mlx);
}
int	main(int argc, char *argv[])
{
	t_data	data;

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
	//m_w_h(&data);
	flood_fill(&data, data.p_w, data.p_h);
	flood_fill_check(&data);
	map(&data);
}
