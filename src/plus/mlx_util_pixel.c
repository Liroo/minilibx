/*
** mlx_util_pixel.c for mlx in /home/mongep/rendu/MUL/MUL_2014_rtracer/source
**
** Made by Monge Pierre
** Login   <mongep@epitech.net>
**
** Started on  Sat May  9 19:22:55 2015 Monge Pierre
** Last update Sat Jun 13 03:56:35 2015 Pierre Monge
*/

#include "mlx_plus.h"

int	rgbt_cast(int to_cast)
{
  if (to_cast > 255)
    return (255);
  else if (to_cast < 0)
    return (0);
  return (to_cast);
}

t_color		rgbt(int r, int g, int b, int t)
{
  t_color	rgbt;

  rgbt.r = rgbt_cast(r);
  rgbt.g = rgbt_cast(g);
  rgbt.b = rgbt_cast(b);
  rgbt.t = rgbt_cast(t);
  return (rgbt);
}

void	mlx_put_pixel(t_img *img, int x, int y, t_color rgbt)
{
  int	begin;

  begin = img->size_line * y + (x * 4);
  if (x >= 0 && y >= 0)
    if (x < img->width && y < img->height)
      {
	img->data[begin] = rgbt.r;
	img->data[begin + 1] = rgbt.g;
	img->data[begin + 2] = rgbt.b;
 	img->data[begin + 3] = rgbt.t;
      }
  return ;
}
