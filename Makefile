#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := fractol
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      math_utils.c \
                          render.c \
                          init.c \
                          main.c \
                          events.c \
                          str_utils.c \
                          minilibx-linux/mlx_clear_window.c \
                          minilibx-linux/mlx_destroy_display.c \
                          minilibx-linux/mlx_destroy_image.c \
                          minilibx-linux/mlx_destroy_window.c \
                          minilibx-linux/mlx_expose_hook.c \
                          minilibx-linux/mlx_ext_randr.c \
                          minilibx-linux/mlx_flush_event.c \
                          minilibx-linux/mlx_get_color_value.c \
                          minilibx-linux/mlx_get_data_addr.c \
                          minilibx-linux/mlx_hook.c \
                          minilibx-linux/mlx_init.c \
                          minilibx-linux/mlx_int_anti_resize_win.c \
                          minilibx-linux/mlx_int_do_nothing.c \
                          minilibx-linux/mlx_int_get_visual.c \
                          minilibx-linux/mlx_int_param_event.c \
                          minilibx-linux/mlx_int_set_win_event_mask.c \
                          minilibx-linux/mlx_int_str_to_wordtab.c \
                          minilibx-linux/mlx_int_wait_first_expose.c \
                          minilibx-linux/mlx_key_hook.c \
                          minilibx-linux/mlx_lib_xpm.c \
                          minilibx-linux/mlx_loop.c \
                          minilibx-linux/mlx_loop_hook.c \
                          minilibx-linux/mlx_mouse.c \
                          minilibx-linux/mlx_mouse_hook.c \
                          minilibx-linux/mlx_new_image.c \
                          minilibx-linux/mlx_new_window.c \
                          minilibx-linux/mlx_pixel_put.c \
                          minilibx-linux/mlx_put_image_to_window.c \
                          minilibx-linux/mlx_rgb.c \
                          minilibx-linux/mlx_screen_size.c \
                          minilibx-linux/mlx_set_font.c \
                          minilibx-linux/mlx_string_put.c \
                          minilibx-linux/mlx_xpm.c \
                          minilibx-linux/test/main.c \
                          minilibx-linux/test/new_win.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME): ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

ifeq ($(UNAME), Linux)
$(NAME): ${OBJS}
			@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

all:		${NAME}

ifeq ($(UNAME), Darwin)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif

ifeq ($(UNAME), Linux)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif


ifeq ($(UNAME), Linux)
fclean:		clean
			@ ${RM} ${NAME}
			@ $(MAKE) -C mlx_linux clean 
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

re:			fclean all

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      math_utils.c \
                          render.c \
                          init.c \
                          main.c \
                          events.c \
                          str_utils.c \
                          minilibx-linux/mlx_clear_window.c \
                          minilibx-linux/mlx_destroy_display.c \
                          minilibx-linux/mlx_destroy_image.c \
                          minilibx-linux/mlx_destroy_window.c \
                          minilibx-linux/mlx_expose_hook.c \
                          minilibx-linux/mlx_ext_randr.c \
                          minilibx-linux/mlx_flush_event.c \
                          minilibx-linux/mlx_get_color_value.c \
                          minilibx-linux/mlx_get_data_addr.c \
                          minilibx-linux/mlx_hook.c \
                          minilibx-linux/mlx_init.c \
                          minilibx-linux/mlx_int_anti_resize_win.c \
                          minilibx-linux/mlx_int_do_nothing.c \
                          minilibx-linux/mlx_int_get_visual.c \
                          minilibx-linux/mlx_int_param_event.c \
                          minilibx-linux/mlx_int_set_win_event_mask.c \
                          minilibx-linux/mlx_int_str_to_wordtab.c \
                          minilibx-linux/mlx_int_wait_first_expose.c \
                          minilibx-linux/mlx_key_hook.c \
                          minilibx-linux/mlx_lib_xpm.c \
                          minilibx-linux/mlx_loop.c \
                          minilibx-linux/mlx_loop_hook.c \
                          minilibx-linux/mlx_mouse.c \
                          minilibx-linux/mlx_mouse_hook.c \
                          minilibx-linux/mlx_new_image.c \
                          minilibx-linux/mlx_new_window.c \
                          minilibx-linux/mlx_pixel_put.c \
                          minilibx-linux/mlx_put_image_to_window.c \
                          minilibx-linux/mlx_rgb.c \
                          minilibx-linux/mlx_screen_size.c \
                          minilibx-linux/mlx_set_font.c \
                          minilibx-linux/mlx_string_put.c \
                          minilibx-linux/mlx_xpm.c \
                          minilibx-linux/test/main.c \
                          minilibx-linux/test/new_win.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME): ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

ifeq ($(UNAME), Linux)
$(NAME): ${OBJS}
			@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

all:		${NAME}

ifeq ($(UNAME), Darwin)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif

ifeq ($(UNAME), Linux)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif


ifeq ($(UNAME), Linux)
fclean:		clean
			@ ${RM} ${NAME}
			@ $(MAKE) -C mlx_linux clean 
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

re:			fclean all

.PHONY:		all clean fclean re
