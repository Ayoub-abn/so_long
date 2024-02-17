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
	char	*extention;

	extention = ft_strrchr(path, '.');
	if (extention == NULL)
	{
		ft_putstr("do not have extention");
		exit(1);
	}
	if (ft_strcmp(extention, ".ber") != 0)
	{
		ft_putstr("extention False");
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

void	xpm_check(t_data *ptr)
{
	if (ptr == NULL)
	{
		ft_putstr("image error");
		exit(1);
	}
}

int	map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(data->mlx, data->win);
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			map_draw(data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	if (argc != 2)
	{
		ft_putstr("params error");
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
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop_hook(data.mlx, map, &data);
	mlx_loop(data.mlx);
}
