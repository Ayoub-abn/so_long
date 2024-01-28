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
	void	*l;
	int		image_w;
	int		image_h;
	void	*p;
	int		p_w;
	int		p_h;
	void	*e;
	void	*c;
	int		w;
	int		h;
	char	**map;
	char	**map2;
}			t_data;

void		ft_putstr(char *str);
void		map(t_data *data);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *s1);
char		*get_next_line(int fd);
void		map_check(char *path, t_data *data);
size_t		ft_strlen_2(const char *s);

#endif
