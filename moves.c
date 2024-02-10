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
	data->map[data->p_h - 1][data->p_w] = 'P';
	data->map[data->p_h][data->p_w] = '0';
}

void	down(t_data *data)
{
	data->map[data->p_h + 1][data->p_w] = 'P';
	data->map[data->p_h][data->p_w] = '0';
}

void	left(t_data *data)
{
	data->zero_lfet = 3;
	data->zero_right = 0;
	data->map[data->p_h][data->p_w - 1] = 'P';
	data->map[data->p_h][data->p_w] = '0';
}

void	right(t_data *data)
{
	data->zero_right = 2;
	data->zero_lfet = 0;
	data->map[data->p_h][data->p_w + 1] = 'P';
	data->map[data->p_h][data->p_w] = '0';
}
