#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stddef.h>
#include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct data
{
    void *mlx;
    void *win;
    void *one;
    void *zero;
    void *p;
    void *e;
    void *c;
    int w;
    int h;
} t_data;

void    ft_putstr(char *str);
int ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
void map_check(char *path,t_data *data);

#endif
