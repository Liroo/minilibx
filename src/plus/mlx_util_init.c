/*
** mlx_util_init.c for mlx in /home/mongep/rendu/MUL/MUL_2014_mlxracer/source
**
** Made by Monge Pierre
** Login   <mongep@epitech.net>
**
** Stamlxed on  Sat May  9 19:24:23 2015 Monge Pierre
** Last update Sat Jun 13 04:01:16 2015 Pierre Monge
*/

#include "mlx.h"
#include "mlx_plus.h"

void	mlx_exit(t_mlx *mlx)
{
  mlx_destroy_window(mlx->mlx, mlx->win);
  exit(0);
  return ;
}

int	mlx_create(t_mlx *mlx, char *name)
{
  if (mlx->winx > 1920 || mlx->winx < 100 || mlx->winy > 1080 || mlx->winy < 100)
    return (-1);
  if ((mlx->mlx = mlx_init()) == NULL)
    return (-1);
  if ((mlx->win = mlx_new_window(mlx->mlx, mlx->winx, mlx->winy, name)) == NULL)
    return (-1);
  if ((mlx->render = mlx_new_image(mlx->mlx, mlx->winx, mlx->winy)) == NULL)
    return (-1);
  return (0);
}

int	mlx_expose(t_mlx *mlx)
{
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->render, 0, 0);
  return (0);
}

int	mlx_key_catch(int keycode, t_mlx *mlx)
{
  if (keycode == ESC)
    mlx_exit_mlx(mlx);
  return (0);
}

void	mlx_gere(t_mlx *mlx)
{
  mlx_expose_hook(mlx->win, &mlx_expose, mlx);
  mlx_key_hook(mlx->win, &mlx_key_catch, mlx);
  mlx_loop(mlx->mlx);
  return ;
}
