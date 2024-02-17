/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:26:24 by aabdenou          #+#    #+#             */
/*   Updated: 2024/02/06 16:26:25 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_data *data)
{
	if (data->map[data->p_h - 1][data->p_w] == 'M')
	{
		ft_putstr("you lost :(");
		exit(0);
	}
	else
	{
		data->map[data->p_h][data->p_w] = '0';
		data->map[data->p_h - 1][data->p_w] = 'P';
	}
}

void	down(t_data *data)
{
	if (data->map[data->p_h + 1][data->p_w] == 'M')
	{
		ft_putstr("you lost :(");
		exit(0);
	}
	else
	{
		data->map[data->p_h][data->p_w] = '0';
		data->map[data->p_h + 1][data->p_w] = 'P';
	}
}

void	left(t_data *data)
{
	if (data->map[data->p_h][data->p_w - 1] == 'M')
	{
		ft_putstr("you lost :(");
		exit(0);
	}
	else
	{
		data->zero_lfet = 3;
		data->zero_right = 0;
		data->map[data->p_h][data->p_w] = '0';
		data->map[data->p_h][data->p_w - 1] = 'P';
	}
}

void	right(t_data *data)
{
	if (data->map[data->p_h][data->p_w + 1] == 'M')
	{
		ft_putstr("you lost :(");
		exit(0);
	}
	else
	{
		data->zero_right = 2;
		data->zero_lfet = 0;
		data->map[data->p_h][data->p_w] = '0';
		data->map[data->p_h][data->p_w + 1] = 'P';
	}
}
