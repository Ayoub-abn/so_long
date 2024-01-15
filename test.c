#include <mlx.h>

typedef struct t_mlx
{
    void *con;
    void *win;
    void *imag;
} out_mlx;

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int main()
{
    out_mlx var;
    t_data img;

    var.con = mlx_init();
    var.win = mlx_new_window(var.con, 1080, 500, "ABN");
    var.imag = mlx_new_image(var.con, 1920, 1080);
    
    img.img = mlx_get_data_addr(var.imag, &img.bits_per_pixel, &img.line_length, &img.endian);
    img.addr = mlx_get_data_addr(var.imag, &img.bits_per_pixel, &img.line_length, &img.endian);

    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(var.con, var.win, var.imag, 0, 0);
    mlx_loop(var.con);
}
