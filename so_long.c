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

void	map_check(char *path, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("PATH MAKAYNCH");
		exit(1);
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_putstr("MAP KHAWYA");
		close(fd);
		exit(1);
	}
	while (line)
	{
		i++;
		line = get_next_line(fd);
	}
	data->h = i;
	close(fd);
}

void	map_w(char *path, t_data *data)
{
	int		fd;
	size_t	s;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("PATH MAKAYNCH");
		exit(1);
	}
	line = get_next_line(fd);
	s = ft_strlen_2(line);
	while (line)
	{
		if (s != ft_strlen_2(line))
		{
			ft_putstr("MAP MAM9ADACH");
			exit(1);
		}
		line = get_next_line(fd);
	}
	data->w = s;
	close(fd);
}

void	map_arr(char *path, t_data *data)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("PATH MAKAYNCH");
		exit(1);
	}
	data->map = malloc(data->h * sizeof(char **));
	if (data->map == NULL)
		return ;
	data->map2 = malloc(data->h * sizeof(char **));
	if (data->map2 == NULL)
		return ;
	while (i < data->h)
	{
		data->map[i] = get_next_line(fd);
		data->map2[i] = data->map[i];
		i++;
	}
	close(fd);
}

void	map_border(t_data *data)
{
	int	i;
	int	j;
	int	c;
	int	p;
	int	e;

	i = 0;
	j = 0;
	c = 0;
	p = 0;
	e = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->map[0][j] != '1' || data->map[data->h - 1][j] != '1')
			{
				ft_putstr("MAP MAM9ADACH");
				exit(1);
			}
			if (data->map[i][0] != '1' || data->map[i][data->w - 1] != '1')
			{
				ft_putstr("MAP MAM9ADACH for vertical");
				exit(1);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != 'E' && data->map[i][j] != 'P'
				&& data->map[i][j] != 'C')
			{
				ft_putstr("RAk ZAYD CHI HAJA F MAP");
				exit(1);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->map[i][j] == 'C')
				c += 1;
			if (data->map[i][j] == 'P')
				p += 1;
			if (data->map[i][j] == 'E')
				e += 1;
			j++;
		}
		i++;
	}
	if (c < 1 || p != 1 || e != 1)
	{
		ft_putstr("CHIHAJA MAHIYACH F MAP");
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
int	move(int keycode, t_data *data)
{
	if (keycode == 13)
	{
		if (data->map[data->p_h - 1][data->p_w] != '1' && data->map[data->p_h
			- 1][data->p_w] != 'E')
		{
			data->map[data->p_h][data->p_w] = '0';
			data->map[data->p_h - 1][data->p_w] = 'P';
		}
	}
	else if (keycode == 0)
	{
		if (data->map[data->p_h][data->p_w - 1] != '1'
			&& data->map[data->p_h][data->p_w - 1] != 'E')
		{
			data->map[data->p_h][data->p_w] = '0';
			data->map[data->p_h][data->p_w - 1] = 'P';
		}
	}
	else if (keycode == 1)
	{
		if (data->map[data->p_h + 1][data->p_w] != '1' && data->map[data->p_h
			+ 1][data->p_w] != 'E')
		{
			data->map[data->p_h][data->p_w] = '0';
			data->map[data->p_h + 1][data->p_w] = 'P';
		}
	}
	else if (keycode == 2)
	{
		if (data->map[data->p_h][data->p_w + 1] != '1'
			&& data->map[data->p_h][data->p_w + 1] != 'E')
		{
			data->map[data->p_h][data->p_w] = '0';
			data->map[data->p_h][data->p_w + 1] = 'P';
		}
	}
	else if (keycode == 53)
		exit(1);
	mlx_clear_window(data->mlx, data->win);
	map(data);
	return (0);
}
void	win_con(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->w * 60, data->h * 60,
			"SO_LONG");
	data->one = mlx_xpm_file_to_image(data->mlx, "./imag/lhayet.xpm",
			&data->image_w, &data->image_h);
	data->l = mlx_xpm_file_to_image(data->mlx, "./imag/luffy.xpm",
			&data->image_w, &data->image_h);
	data->p = mlx_xpm_file_to_image(data->mlx, "./imag/zorro.xpm",
			&data->image_w, &data->image_h);
	data->zero = mlx_xpm_file_to_image(data->mlx, "./imag/lared.xpm",
			&data->image_w, &data->image_h);
	data->c = mlx_xpm_file_to_image(data->mlx, "./imag/bottle.xpm",
			&data->image_w, &data->image_h);
	data->e = mlx_xpm_file_to_image(data->mlx, "./imag/sanigo.xpm",
			&data->image_w, &data->image_h);
}

// void flood_fill(char **map,int p_h,int p_w,int w ,int h)
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
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->one, j * 60,
					i * 60);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->zero, j
					* 60, i * 60);
			else if (data->map[i][j] == 'P')
			{
				data->p_h = i;
				data->p_w = j;
				mlx_put_image_to_window(data->mlx, data->win, data->zero, j
					* 60, i * 60);
				mlx_put_image_to_window(data->mlx, data->win, data->p, j * 60, i
					* 60);
			}
			else if (data->map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->zero, j
					* 60, i * 60);
				mlx_put_image_to_window(data->mlx, data->win, data->c, j * 60, i
					* 60);
			}
			else if (data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->zero, j
					* 60, i * 60);
				mlx_put_image_to_window(data->mlx, data->win, data->e, j * 60, i
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
	win_con(&data);
	map_border(&data);
	p_w_h(&data);
	flood_fill(&data, data.p_w, data.p_h);
	map(&data);
}
