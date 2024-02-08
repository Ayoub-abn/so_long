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
	void	*p;
	void	*p2;
	void	*a2;
	int		zero_lfet;
	int		zero_right;
	int		zero_up;
	int		zero_down;
	void	*open;
	int		c_m;
	void	*m;
	void	*m2;
	void	*m3;
	void	*m4;
	void	*m5;
	void	*m6;
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
	int		frame_m;
	int		attack;
	int		attack_lfet;
	int		attack_right;
	char	**map;
	char	**map2;
}			t_data;

void		ft_putstr(char *str);
void		imag_xpm(t_data *data);
void		imag_xpm_2(t_data *data);
void		xpm_check(void *ptr);
void		check_marines(t_data *data, int i, int j);
void		draw_marines_1(t_data *data, int i, int j);
void		draw_marines_2(t_data *data, int i, int j);
void		put_str(t_data *data);
void		draw_player(t_data *data, int i, int j);
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
void		map_content_p3(t_data *data, int p, int e);
void		marine_move(t_data *data);
void		up_1(t_data *data);
void		left_1(t_data *data);
void		down_1(t_data *data);
void		right_1(t_data *data);
void		up(t_data *data);
void		down(t_data *data);
void		left(t_data *data);
void		right(t_data *data);
void		attack_right(t_data *data);
void		attack_left(t_data *data);
#endif