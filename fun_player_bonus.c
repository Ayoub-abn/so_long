/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:22:32 by aabdenou          #+#    #+#             */
/*   Updated: 2024/01/29 17:22:33 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_1(t_data *data)
{
	// char	*nb;

	if (data->map[data->p_h - 1][data->p_w] != '1' && data->map[data->p_h
		- 1][data->p_w] != 'E')
	{
		up(data);
		data->move++;
		// ft_putstr("moves: ");
		// nb = ft_itoa(data->move);
		// ft_putstr(nb);
		// free(nb);
		// ft_putstr("\n");
	}
	else if (all_collected(data) && data->map[data->p_h - 1][data->p_w] == 'E')
	{
		ft_putstr("REBAHTI :)");
		exit(1);
	}
}

void	left_1(t_data *data)
{
	// char	*nb;

	if (data->map[data->p_h][data->p_w - 1] != '1'
		&& data->map[data->p_h][data->p_w - 1] != 'E')
	{
		left(data);
		data->move++;
		// ft_putstr("move: ");
		// nb = ft_itoa(data->move);
		// ft_putstr(nb);
		// free(nb);
		// ft_putstr("\n");
	}
	else if (all_collected(data) && data->map[data->p_h][data->p_w - 1] == 'E')
	{
		ft_putstr("REBAHTI :)");
		exit(1);
	}
}

void	down_1(t_data *data)
{
	// char	*nb;

	if (data->map[data->p_h + 1][data->p_w] != '1' && data->map[data->p_h
		+ 1][data->p_w] != 'E')
	{
		down(data);
		data->move++;
		// ft_putstr("move: ");
		// nb = ft_itoa(data->move);
		// ft_putstr(nb);
		// free(nb);
		// ft_putstr("\n");
	}
	else if (all_collected(data) && data->map[data->p_h + 1][data->p_w] == 'E')
	{
		ft_putstr("REBAHTI :)");
		exit(1);
	}
}

void	right_1(t_data *data)
{
	// char	*nb;

	if (data->map[data->p_h][data->p_w + 1] != '1'
		&& data->map[data->p_h][data->p_w + 1] != 'E')
	{
		right(data);
		data->move++;
		// ft_putstr("move: ");
		// nb = ft_itoa(data->move);
		// ft_putstr(nb);
		// free(nb);
		// ft_putstr("\n");
	}
	else if (all_collected(data) && data->map[data->p_h][data->p_w + 1] == 'E')
	{
		ft_putstr("REBAHTI :)");
		exit(1);
	}
}

int	move(int keycode, t_data *data)
{
	if (keycode == 86 && (data->map[data->p_h][data->p_w - 1] == 'M'
		|| data->map[data->p_h][data->p_w - 1] == '0'))
		attack_left(data);
	else if (keycode == 88 && (data->map[data->p_h][data->p_w + 1] == 'M'
		|| data->map[data->p_h][data->p_w + 1] == '0'))
		attack_right(data);
	else if (keycode == 13)
		up_1(data);
	else if (keycode == 0)
		left_1(data);
	else if (keycode == 1)
		down_1(data);
	else if (keycode == 2)
		right_1(data);
	else if (keycode == 53)
	{
		exit(1);
	}
	return (0);
}
