##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Sat Jun 13 04:10:37 2015 Pierre Monge
##

SRC_DEF	=	mlx_init.c			\
		mlx_new_window.c		\
		mlx_pixel_put.c			\
		mlx_loop.c			\
		mlx_mouse_hook.c		\
		mlx_key_hook.c			\
		mlx_expose_hook.c		\
		mlx_loop_hook.c			\
		mlx_int_anti_resize_win.c	\
		mlx_int_do_nothing.c		\
		mlx_int_wait_first_expose.c	\
		mlx_int_get_visual.c		\
		mlx_flush_event.c		\
		mlx_string_put.c		\
		mlx_new_image.c			\
		mlx_get_data_addr.c		\
		mlx_put_image_to_window.c	\
		mlx_get_color_value.c		\
		mlx_clear_window.c		\
		mlx_xpm.c			\
		mlx_int_str_to_wordtab.c	\
		mlx_destroy_window.c		\
		mlx_int_param_event.c		\
		mlx_int_set_win_event_mask.c	\
		mlx_hook.c			\
		mlx_rgb.c			\
		strlcpy.c

SRC_PLS	=	mlx_util_init.c		\
		mlx_util_pixel.c

OBJ	=	$(addprefix src/default/, $(SRC_DEF:.c=.o))	\
		$(addprefix src/plus/, $(SRC_PLS:.c=.o))

NAME	=	libmlx_.a

INCLUDE	=	-I/usr/X11R6/include -I./include

CFLAGS	=	$(INCLUDE)

CCLIB	=	ar

RANLIB	=	ranlib

COLOR		= \x1b[32;01m

COLOR_OFF	= \x1b[0m

MX_OK		= $(COLOR)[Lib $(NAME) compiled !]$(COLOR_OFF)

MX_CLEAN	= $(COLOR)[Lib $(NAME) cleaned !]$(COLOR_OFF)

$(NAME): $(OBJ)
	 $(CCLIB) -r $(NAME) $(OBJ)
	 $(RANLIB) $(NAME)
	 @echo -e "$(MX_OK)"

all: $(NAME)

clean:
	 $(RM) $(OBJ)
	 @echo -e "$(MX_CLEAN)"

fclean:
	 $(RM) $(OBJ)
	 $(RM) $(NAME)
	 @echo -e "$(MX_CLEAN)"

re: fclean all

.PHONY: all clean fclean re
