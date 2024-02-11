/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_map_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:25:11 by aabdenou          #+#    #+#             */
/*   Updated: 2024/02/08 10:25:12 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_content_p1(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != 'E' && data->map[i][j] != 'P'
				&& data->map[i][j] != 'C' && data->map[i][j] != 'M')
			{
				ft_putstr("DAYER CHI HAJA MAKHASHACH T KON F LMAP");
				exit(1);
			}
			j++;
		}
		i++;
	}
	map_content_p2(data);
}

void	map_content_p2(t_data *data)
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
				data->co++;
			if (data->map[i][j] == 'P')
				data->c_p++;
			if (data->map[i][j] == 'E')
				data->c_e++;
			if (data->map[i][j] == 'M')
				data->c_m++;
			j++;
		}
		i++;
	}
	map_content_p3(data);
}

void	map_content_p3(t_data *data)
{
	if (data->co < 1 || data->c_m < 1 || data->c_p != 1 || data->c_e != 1)
	{
		ft_putstr("CHIHAJA (ZAYDA || NA9SA) F LMAP");
		exit(1);
	}
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
				|| data->map2[i][j] == 'M')
			{
				ft_putstr("L MAP MAYMKNCH LIHA TREBAH");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_data *data, int j, int i)
{
	if (data->p_h < 0 || data->p_w < 0 || data->p_h >= data->h
		|| data->p_w >= data->w)
		return ;
	if (data->map2[i][j] != '0' && data->map2[i][j] != 'C'
		&& data->map2[i][j] != 'E' && data->map2[i][j] != 'P'
		&& data->map2[i][j] != 'M')
		return ;
	else if (data->map2[i][j] == 'E')
	{
		data->map2[i][j] = '+';
		return ;
	}
	data->map2[i][j] = 'X';
	flood_fill(data, j + 1, i);
	flood_fill(data, j - 1, i);
	flood_fill(data, j, i + 1);
	flood_fill(data, j, i - 1);
}
