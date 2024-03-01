# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vopekdas <vopekdas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 16:39:18 by vopekdas          #+#    #+#              #
#    Updated: 2024/03/01 18:40:59 by vopekdas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIGHT_RED=\033[1;31m
LIGHT_GREEN=\033[1;32m
LIGHT_YELLOW=\033[1;33m
LIGHT_BLUE=\033[1;34m
LIGHT_MAGENTA=\033[1;35m
LIGHT_CYAN=\033[1;36m
WHITE=\033[1;37m
LIGHT_GRAY=\033[0;37m
DARK_GRAY=\033[1;30m
LIGHT_PURPLE=\033[1;35m

NAME = so_long

CC=cc
CFLAGS=-Wall -Wextra -Werror -g3 -MMD -O2 -fno-builtin
RM = rm -f

LIBFT_PATH = Libft
FT_PRINTF_PATH = ft_printf
MINILIBX_PATH = minilibx-linux

SRCS = animation.c\
		background.c\
		bomb.c\
		bubble.c\
		collectibles.c\
		collectible_list.c\
		collision.c\
		colors.c\
		draw_sprite.c\
		enemy_box.c\
		enemy.c\
		exit_chest.c\
		free_utils.c\
		init_game.c\
		init_sprite.c\
		keys.c\
		main.c\
		map_errors.c\
		map.c\
		player.c\
		pathfinding.c\
		player_box.c\
		print_tile.c\
		rand.c\
		trail.c\
		update_game.c\
		vignette.c\

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)
	@echo "$(LIGHT_CYAN)"
	@printf "$(LIGHT_GREEN)Compilation completed successfully.\n"

-include $(SRCS:.c=.d)

$(NAME): libft ft_printf minilibx $(OBJS)
	@printf "$(LIGHT_BLUE)Starting compilation...\n\033[0m"
	@echo "$(LIGHT_CYAN)"
	$(CC) -g3 -o $(NAME) $(OBJS) -LLibft -lft -Lft_printf -lftprintf -Lminilibx-linux -lmlx_Linux -lmlx -lX11 -lXext -lm

bonus: CFLAGS+=-DBONUS=1
bonus: $(NAME)

libft: 
	@printf "$(LIGHT_BLUE)Starting compilation...\n\033[0m"
	@echo "$(LIGHT_CYAN)"
	@printf "$(LIGHT_CYAN)██╗     $(LIGHT_BLUE)██╗$(LIGHT_CYAN)██████╗ $(LIGHT_BLUE)███████╗$(LIGHT_CYAN)████████╗\n"
	@printf "$(LIGHT_CYAN)██║     $(LIGHT_BLUE)██║$(LIGHT_CYAN)██╔══██╗$(LIGHT_BLUE)██╔════╝$(LIGHT_CYAN)╚══██╔══╝\n"
	@printf "$(LIGHT_CYAN)██║     $(LIGHT_BLUE)██║$(LIGHT_CYAN)██████╔╝$(LIGHT_BLUE)█████╗  $(LIGHT_CYAN)   ██║   \n"
	@printf "$(LIGHT_CYAN)██║     $(LIGHT_BLUE)██║$(LIGHT_CYAN)██╔══██╗$(LIGHT_BLUE)██╔══╝  $(LIGHT_CYAN)   ██║   \n"
	@printf "$(LIGHT_CYAN)███████╗$(LIGHT_BLUE)██║$(LIGHT_CYAN)██████╔╝$(LIGHT_BLUE)██║     $(LIGHT_CYAN)   ██║   \n"
	@printf "$(LIGHT_CYAN)╚══════╝$(LIGHT_BLUE)╚═╝$(LIGHT_CYAN)╚═════╝ $(LIGHT_BLUE)╚═╝     $(LIGHT_CYAN)   ╚═╝   \n"
	$(MAKE) -C $(LIBFT_PATH)
	@printf "$(LIGHT_GREEN)Compilation completed successfully.\n\033[0m"

ft_printf: 
	@printf "$(LIGHT_BLUE)Starting compilation...\n\033[0m"
	@printf "$(LIGHT_BLUE)███████╗$(LIGHT_CYAN)████████╗$(LIGHT_BLUE)     $(LIGHT_CYAN)██████╗ $(LIGHT_BLUE)██████╗ $(LIGHT_CYAN)██╗$(LIGHT_BLUE)███╗   ██╗$(LIGHT_CYAN)████████╗$(LIGHT_BLUE)███████╗\n"
	@printf "$(LIGHT_BLUE)██╔════╝$(LIGHT_CYAN)╚══██╔══╝$(LIGHT_BLUE)     $(LIGHT_CYAN)██╔══██╗$(LIGHT_BLUE)██╔══██╗$(LIGHT_CYAN)██║$(LIGHT_BLUE)████╗  ██║$(LIGHT_CYAN)╚══██╔══╝$(LIGHT_BLUE)██╔════╝\n"
	@printf "$(LIGHT_BLUE)█████╗  $(LIGHT_CYAN)   ██║   $(LIGHT_BLUE)     $(LIGHT_CYAN)██████╔╝$(LIGHT_BLUE)██████╔╝$(LIGHT_CYAN)██║$(LIGHT_BLUE)██╔██╗ ██║$(LIGHT_CYAN)   ██║   $(LIGHT_BLUE)█████╗  \n"
	@printf "$(LIGHT_BLUE)██╔══╝  $(LIGHT_CYAN)   ██║   $(LIGHT_BLUE)     $(LIGHT_CYAN)██╔═══╝ $(LIGHT_BLUE)██╔══██╗$(LIGHT_CYAN)██║$(LIGHT_BLUE)██║╚██╗██║$(LIGHT_CYAN)   ██║   $(LIGHT_BLUE)██╔══╝  \n"
	@printf "$(LIGHT_BLUE)██║     $(LIGHT_CYAN)   ██║███$(LIGHT_BLUE)████╗$(LIGHT_CYAN)██║     $(LIGHT_BLUE)██║  ██║$(LIGHT_CYAN)██║$(LIGHT_BLUE)██║ ╚████║$(LIGHT_CYAN)   ██║   $(LIGHT_BLUE)██║     \n"
	@printf "$(LIGHT_BLUE)╚═╝     $(LIGHT_CYAN)   ╚═╝╚══$(LIGHT_BLUE)════╝$(LIGHT_CYAN)╚═╝     $(LIGHT_BLUE)╚═╝  ╚═╝$(LIGHT_CYAN)╚═╝$(LIGHT_BLUE)╚═╝  ╚═══╝$(LIGHT_CYAN)   ╚═╝   $(LIGHT_BLUE)╚═╝     \n"
	@echo "$(LIGHT_CYAN)"
	$(MAKE) -C $(FT_PRINTF_PATH)
	@printf "$(LIGHT_GREEN)Compilation completed successfully.\n\033[0m"

minilibx:
	@printf "$(LIGHT_BLUE)Starting compilation...\n\033[0m"
	@printf "$(LIGHT_BLUE)███╗   ███╗$(LIGHT_CYAN)██╗$(LIGHT_BLUE)███╗   ██╗$(LIGHT_CYAN)██╗$(LIGHT_BLUE)██╗     $(LIGHT_CYAN)██╗$(LIGHT_BLUE)██████╗ $(LIGHT_CYAN)██╗  ██╗\n"
	@printf "$(LIGHT_BLUE)████╗ ████║$(LIGHT_CYAN)██║$(LIGHT_BLUE)████╗  ██║$(LIGHT_CYAN)██║$(LIGHT_BLUE)██║     $(LIGHT_CYAN)██║$(LIGHT_BLUE)██╔══██╗$(LIGHT_CYAN)╚██╗██╔╝\n"
	@printf "$(LIGHT_BLUE)██╔████╔██║$(LIGHT_CYAN)██║$(LIGHT_BLUE)██╔██╗ ██║$(LIGHT_CYAN)██║$(LIGHT_BLUE)██║     $(LIGHT_CYAN)██║$(LIGHT_BLUE)██████╔╝$(LIGHT_CYAN) ╚███╔╝ \n"
	@printf "$(LIGHT_BLUE)██║╚██╔╝██║$(LIGHT_CYAN)██║$(LIGHT_BLUE)██║╚██╗██║$(LIGHT_CYAN)██║$(LIGHT_BLUE)██║     $(LIGHT_CYAN)██║$(LIGHT_BLUE)██╔══██╗$(LIGHT_CYAN) ██╔██╗ \n"
	@printf "$(LIGHT_BLUE)██║ ╚═╝ ██║$(LIGHT_CYAN)██║$(LIGHT_BLUE)██║ ╚████║$(LIGHT_CYAN)██║$(LIGHT_BLUE)███████╗$(LIGHT_CYAN)██║$(LIGHT_BLUE)██████╔╝$(LIGHT_CYAN)██╔╝ ██╗\n"
	@printf "$(LIGHT_BLUE)╚═╝     ╚═╝$(LIGHT_CYAN)╚═╝$(LIGHT_BLUE)╚═╝  ╚═══╝$(LIGHT_CYAN)╚═╝$(LIGHT_BLUE)╚══════╝$(LIGHT_CYAN)╚═╝$(LIGHT_BLUE)╚═════╝ $(LIGHT_CYAN)╚═╝  ╚═╝\n"
	@echo "$(LIGHT_CYAN)"
	$(MAKE) -C $(MINILIBX_PATH)  
	@printf "$(LIGHT_GREEN)Compilation completed successfully.\n\033[0m"

clean:
	@echo "$(LIGHT_PURPLE)"
	$(RM) $(OBJS) $(BONUS_OBJS) *.d
	cd $(LIBFT_PATH) && make clean
	cd $(FT_PRINTF_PATH) && make clean
	cd $(MINILIBX_PATH) && make clean
	@printf "$(LIGHT_RED)Cleaned all object files.\n"

fclean: clean
	@echo "$(LIGHT_PURPLE)"
	$(RM) $(NAME)
	cd $(LIBFT_PATH) && make fclean
	cd $(FT_PRINTF_PATH) && make fclean
	@printf "$(LIGHT_RED)Cleaned all object files.\n"

re: fclean all

.PHONY: all clean fclean re libft ft_printf