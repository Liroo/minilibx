/*
** mlx_plus.h for plus in /home/monge_p/personnel/minilibx/include
**
** Made by Pierre Monge
** Login   <monge_p@epitech.net>
**
** Started on  Wed Jun 10 18:52:48 2015 Pierre Monge
** Last update Sat Jun 13 04:01:03 2015 Pierre Monge
*/

#ifndef		__MLX_PLUS_H_
# define	__MLX_PLUS_H_

# include <stdlib.h>
# include "mlx_int.h"

# define	ESC	65307

typedef	struct	s_color
{
  int		r;
  int		g;
  int		b;
  int		t;
}		t_color;

typedef	struct	s_mlx
{
  int		winx;
  int		winy;
  void		*mlx;
  void		*win;
  void		*render;
}		t_mlx;

/*
** Put a pixel on the image
*/
int	rgbt_cast(int);
t_color	rgbt(int r, int g, int b, int t);
void	mlx_put_pixel(t_img *, int x, int y, t_color);
/*
** Init mlx and gestion of expose and loop
*/
void	mlx_gere(t_mlx *);
int	mlx_key_catch(int keycode, t_mlx *);
int	mlx_exose(t_mlx *);
int	mlx_create(t_mlx *, char *name_of_the_window);
void	mlx_exit(t_mlx *);

#endif		/* !__MLX_PLUS_H_ */
