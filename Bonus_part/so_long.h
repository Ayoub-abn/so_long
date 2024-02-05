/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:52:02 by aabdenou          #+#    #+#             */
/*   Updated: 2024/01/27 23:52:03 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct data
{
	void	*mlx;
	void	*win;
	void	*one;
	void	*zero;
	void	*player;
	void	*pp;
	void	*aa;
	void	*aaa;
	void	*aaaa;
	int		zero_lfet;
	int		zero_right;
	int		zero_up;
	int		zero_down;
	void	*open;
	void	*m;
	void	*m_a;
	void	*m_a2;
	void	*m_a3;
	void	*m_a4;
	void	*m_a5;
	void	*m_a6;
	void	*zorro_move;
	void	*zorro_move2;
	void	*a;
	int		image_w;
	int		image_h;
	int		p_w;
	int		frame_p;
	int		frame_m_a;
	int		check;
	int		p_h;
	int		m_w;
	int		m_h;
	int		co;
	int		i;
	int		move;
	void	*e;
	void	*c;
	int		w;
	int		h;
	int		attack;
	int		attack_lfet;
	int		attack_right;
	char	**map;
	char	**map2;
}			t_data;

void		ft_putstr(char *str);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_itoa(int n);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *s1);
char		*get_next_line(int fd);
size_t		ft_strlen_2(const char *s);
int			move(int keycode, t_data *data);
void		path_check(char *path);
void		p_w_h(t_data *data);
void		win_con(t_data *data);
int			all_collected(t_data *data);
void		flood_fill(t_data *data, int x, int y);
int			map(t_data *data);
void		map_check(char *path, t_data *data);
void		map_w(char *path, t_data *data);
void		map_arr(char *path, t_data *data);
void		map_arr2(char *path, t_data *data);
void		map_border(t_data *data);
void		map_content_p1(t_data *data);
void		map_content_p2(t_data *data);
void		marine_move(t_data *data);
#endif