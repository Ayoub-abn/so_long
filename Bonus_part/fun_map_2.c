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
	int	p;
	int	e;

	p = 0;
	e = 0;
	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->map[i][j] == 'C')
				data->co++;
			if (data->map[i][j] == 'P')
				p++;
			if (data->map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	map_content_p3(data, p, e);
}

void	map_content_p3(t_data *data, int p, int e)
{
	if (data->co < 1 || p != 1 || e != 1)
	{
		ft_putstr("CHIHAJA (ZAYDA || NA9SA) F LMAP");
		exit(1);
	}
}
