#include "mlx.h"

int main()
{
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "cub3d");
    int x = 100;
    int y = 100;
    while (x < 800 && y < 600)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x++, y++, 0xFF00FF);
    }
    mlx_loop(mlx_ptr);
    return (0);
}