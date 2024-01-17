#include "so_long.h"
#include <stdlib.h>
void path_check(char *path)
{
    if (ft_strcmp(&path[ft_strlen(path) - 4], ".ber") != 0)
	{
		ft_putstr("MAP PATH IMVALIDE");
		exit(1);
	}
}
void map_check(char *path,t_data *data)
{
	int fd;
	int i;
	char *line;
	i = 0;
	fd = open(path,O_RDONLY);
	if(fd < 0)
	{
		ft_putstr("PATH MAKAYNCH");
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		i++;
		line = get_next_line(fd);
	}
	data->h = i;
	printf("%d",i);
	close(fd);
}
int main(int argc, char *argv[])
 {
	t_data data;

    if (argc != 2)
	{
		ft_putstr("NUMBER OF PARAMS PROBLEM");
		return (1);
	}
    path_check(argv[1]);
	map_check(argv[1],&data);

    
//     char *str[5] = { "11111111111111111111111111111111",
//                      "100P0000001000000000000100000001",
//                      "100000C000000000010000C000000001",
//                      "100000000000010000C00000000E0001",
//                      "11111111111111111111111111111111"};
//     int		img_width ;
// 	int		img_height;
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx,32*60,5*60,"l7ariss");
//     void *one = mlx_xpm_file_to_image(mlx,"./imag/lhayet.xpm",&img_width,&img_height);
//     void *p = mlx_xpm_file_to_image(mlx,"./imag/zorro.xpm",&img_width,&img_height);
//     void *zero = mlx_xpm_file_to_image(mlx,"./imag/lared.xpm",&img_width,&img_height);
//     void *c = mlx_xpm_file_to_image(mlx,"./imag/bottle.xpm",&img_width,&img_height);
//     void *e =  mlx_xpm_file_to_image(mlx,"./imag/sanigo.xpm",&img_width,&img_height);
//     int i = 0;
//     int j;
//     while(i < 5)
//     {
//         j = 0;
//         while (j < 32)
//         {
//             if(str[i][j] =='1')
//                 mlx_put_image_to_window(mlx,win,one,j*60,i*60);
//             if(str[i][j] =='P')
// 			{
//                 mlx_put_image_to_window(mlx,win,zero,j*60,i*60);
//                 mlx_put_image_to_window(mlx,win,p,j*60,i*60);
// 			}
//             if(str[i][j] == '0')
//                 mlx_put_image_to_window(mlx,win,zero,j*60,i*60);
//             if(str[i][j] == 'C')
// 			{
//                 mlx_put_image_to_window(mlx,win,zero,j*60,i*60);
//                 mlx_put_image_to_window(mlx,win,c,j*60,i*60);
// 			}
//             if(str[i][j] == 'E')
// 			{
//                 mlx_put_image_to_window(mlx,win,zero,j*60,i*60);
//                 mlx_put_image_to_window(mlx,win,e,j*60,i*60);
// 			}
//             j++;
//         }
//         i++;
//     } 
    
// mlx_loop(mlx);
}
   