/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:17:32 by aabdenou          #+#    #+#             */
/*   Updated: 2024/02/06 16:17:33 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	attack_left(t_data *data)
{
	data->map[data->p_h][data->p_w - 1] = '0';
	data->zero_lfet = 1;
	data->zero_right = 0;
	data->i = 1;
	data->frame_p = 0;
}

void	attack_right(t_data *data)
{
	data->map[data->p_h][data->p_w + 1] = '0';
	data->zero_right = 1;
	data->zero_lfet = 0;
	data->i = 1;
	data->frame_p = 0;
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
