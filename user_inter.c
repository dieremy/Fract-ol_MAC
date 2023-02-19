#include "fractal.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

void    description(int ac, char **av)
{
    if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], "Douady") == 0)
    {
        write(1, "KEYBOARD SHORCUTS\n\n", 20);
        write(1, "CLOSE THE PROGRAM:\tX/ESC\n", 25);
        write(1, "CHANGE COLOR SHADE:\tSHIFT\n", 26);
        write(1, "MOVE FRACTAL:\t\tARROW-LEFT/ARROW-RIGHT/ARROW-UP/ARROW-DOWN\n", 58);
        write(1, "ZOOM/UNZOOM:\t\tPLUS/MINUS\n", 25);
        write(1, "CHANGE TO JULIA:\tJ\n", 19);
        write(1, "CHANGE TO MANDELBROT:\tM\n", 24);
        write(1, "CHANGE TO DOUADY:\tD\n", 20);
    }
}

void    str_put(t_fractal *d)
{
    mlx_string_put(d->mlx, d->win, 970, 450,
     RED, "KEYBOARD SHORCUTS:");
    mlx_string_put(d->mlx, d->win, 970, 500,
     RED, "      CLOSE THE WINDOW:      X/ESC");
    mlx_string_put(d->mlx, d->win, 970, 550,
     RED, "      CHANGE COLOR SHADE:    SHIFT");
    mlx_string_put(d->mlx, d->win, 970, 600,
     RED, "      MOVE FRACTAL:          ARROWS");
    mlx_string_put(d->mlx, d->win, 970, 650,
     RED, "      ZOOM/UNZOOM:           PLUS/MINUS");
    mlx_string_put(d->mlx, d->win, 970, 700,
     RED, "      CHANGE TO JULIA:       J");
    mlx_string_put(d->mlx, d->win, 970, 750,
     RED, "      CHANGE TO MANDELBROT:  M");
    mlx_string_put(d->mlx, d->win, 970, 800,
     RED, "      CHANGE TO DOUADY:      D");
    mlx_string_put(d->mlx, d->win, 970, 850,
     RED, "MOUSE INTERATION:");
    mlx_string_put(d->mlx, d->win, 970, 900,
     RED, "      ZOOM/UNZOOM:           MOUSE ROLL");
}

int ft_close(t_fractal *d)
{
    write(1, "\nWELCOME HOME SON.\n", 19);
    mlx_destroy_window(d->mlx, d->win);
    free(d);
    exit(0);
}