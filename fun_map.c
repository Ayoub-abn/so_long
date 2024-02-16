/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:22:40 by aabdenou          #+#    #+#             */
/*   Updated: 2024/01/29 17:22:43 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		(ft_putstr("MAP KHAWYA"), close(fd));
		exit(1);
	}
	while (line)
	{
		i++;
		free(line);
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
		free(line);
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
	data->map = malloc(data->h * sizeof(char *));
	if (data->map == NULL)
		return ;
	while (i < data->h)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	map_arr2(char *path, t_data *data)
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
	data->map2 = malloc(data->h * sizeof(char *));
	if (data->map2 == NULL)
		return ;
	while (i < data->h)
	{
		data->map2[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	map_border(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if ((data->map[0][j] != '1' || data->map[data->h - 1][j] != '1'))
			{
				ft_putstr("MAP MAM9ADACH");
				exit(1);
			}
			if (data->map[i][0] != '1' || data->map[i][data->w - 1] != '1')
			{
				ft_putstr("MAP MAM9ADACH KAYNA CHI HAJA F JENAB ");
				exit(1);
			}
			j++;
		}
		i++;
	}
}
