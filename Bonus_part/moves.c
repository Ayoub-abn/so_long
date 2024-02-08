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

void	up_1(t_data *data)
{
	char	*nb;

	if (data->map[data->p_h - 1][data->p_w] != '1' && data->map[data->p_h
		- 1][data->p_w] != 'E')
	{
		up(data);
		data->move++;
		ft_putstr("moves: ");
		nb = ft_itoa(data->move);
		ft_putstr(nb);
		free(nb);
		ft_putstr("\n");
	}
	else if (all_collected(data) && data->map[data->p_h - 1][data->p_w] == 'E')
	{
		ft_putstr("REBAHTI :)");
		system("leaks so_long");
		exit(1);
	}
}

void	left_1(t_data *data)
{
	char	*nb;

	if (data->map[data->p_h][data->p_w - 1] != '1'
		&& data->map[data->p_h][data->p_w - 1] != 'E')
	{
		left(data);
		data->move++;
		ft_putstr("move: ");
		nb = ft_itoa(data->move);
		ft_putstr(nb);
		free(nb);
		ft_putstr("\n");
	}
	else if (all_collected(data) && data->map[data->p_h][data->p_w - 1] == 'E')
	{
		ft_putstr("REBAHTI :)");
		system("leaks so_long");
		exit(1);
	}
}

void	down_1(t_data *data)
{
	char	*nb;

	if (data->map[data->p_h + 1][data->p_w] != '1' && data->map[data->p_h
		+ 1][data->p_w] != 'E')
	{
		down(data);
		data->move++;
		ft_putstr("move: ");
		nb = ft_itoa(data->move);
		ft_putstr(nb);
		free(nb);
		ft_putstr("\n");
	}
	else if (all_collected(data) && data->map[data->p_h + 1][data->p_w] == 'E')
	{
		ft_putstr("REBAHTI :)");
		system("leaks so_long");
		exit(1);
	}
}

void	right_1(t_data *data)
{
	char	*nb;

	if (data->map[data->p_h][data->p_w + 1] != '1'
		&& data->map[data->p_h][data->p_w + 1] != 'E')
	{
		right(data);
		data->move++;
		ft_putstr("move: ");
		nb = ft_itoa(data->move);
		ft_putstr(nb);
		free(nb);
		ft_putstr("\n");
	}
	else if (all_collected(data) && data->map[data->p_h][data->p_w + 1] == 'E')
	{
		ft_putstr("REBAHTI :)");
		system("leaks so_long");
		exit(1);
	}
}
