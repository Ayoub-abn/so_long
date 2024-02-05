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


#include "so_long.h"

void	up(t_data *data)
{
	if (data->map[data->p_h - 1][data->p_w] == 'M')
	{
		ft_putstr("KHESERTI :)");
		exit(1);
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
		ft_putstr("KHESERTI :)");
		exit(1);
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
		ft_putstr("KHESERTI :)");
		exit(1);
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
		ft_putstr("KHESERTI :)");
		exit(1);
	}
	else
	{
		data->zero_right = 2;
		data->zero_lfet = 0;
		data->map[data->p_h][data->p_w] = '0';
		data->map[data->p_h][data->p_w + 1] = 'P';
	}
}

int	move(int keycode, t_data *data)
{
	char *nb;
	// static int	move = 0;
	if (keycode == 86 && (data->map[data->p_h][data->p_w - 1] == 'M'
			|| data->map[data->p_h][data->p_w - 1] == '0'))
	{
		data->map[data->p_h][data->p_w - 1] = '0';
		data->zero_lfet = 1;
		data->zero_right = 0;
		data->i = 1;
		data->frame_p = 0;
		data->attack_lfet = 86;
		data->attack_right = 0;
	}
	else if (keycode == 88 && (data->map[data->p_h][data->p_w + 1] == 'M'
			|| data->map[data->p_h][data->p_w + 1] == '0'))
	{
		data->map[data->p_h][data->p_w + 1] = '0';
		data->zero_right = 1;
		data->zero_lfet = 0;
		data->i = 1;
		data->frame_p = 0;
		data->attack_right = 88;
		data->attack_lfet = 0;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	else if (keycode == 13)
	{
		if (data->map[data->p_h - 1][data->p_w] == 'C')
			data->co++;
		if (data->map[data->p_h - 1][data->p_w] != '1' && data->map[data->p_h
			- 1][data->p_w] != 'E')
		{
			up(data);
			data->move++;
			ft_putstr("move: ");
			nb = ft_itoa(data->move);
			ft_putstr(nb);
			free(nb);
			ft_putstr("\n");
		}
		
		else if (all_collected(data) && data->map[data->p_h
			- 1][data->p_w] == 'E')
		{
			ft_putstr("REBAHTI :)");
			exit(1);
		}
	}
	else if (keycode == 0)
	{
		if (data->map[data->p_h][data->p_w - 1] == 'C')
			data->co++;
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
		else if (all_collected(data) && data->map[data->p_h][data->p_w
			- 1] == 'E')
		{
			ft_putstr("REBAHTI :)");
			exit(1);
		}
	}
	else if (keycode == 1)
	{
		if (data->map[data->p_h + 1][data->p_w] == 'C')
			data->co++;
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
		else if (all_collected(data) && data->map[data->p_h
			+ 1][data->p_w] == 'E')
		{
			ft_putstr("REBAHTI :)");
			exit(1);
		}
	}
	else if (keycode == 2)
	{
		if (data->map[data->p_h][data->p_w - 1] == 'C')
			data->co++;
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
		else if (all_collected(data) && data->map[data->p_h][data->p_w
			+ 1] == 'E')
		{
			ft_putstr("REBAHTI :)");
			exit(1);
		}
	}
	else if (keycode == 53)
	{
		system("leaks so_long");
		// while (data->map[i])
		// {
		// 	printf("freeing  %s \n", data->map[i]);
		// 	free(data->map[i]);
		// 	i++;
		// }
		// free(map);
		exit(1);
	}
	return (0);
}
