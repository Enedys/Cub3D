# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/29 15:50:09 by Kwillum           #+#    #+#              #
#    Updated: 2020/06/30 17:02:07 by Kwillum          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libcub3d.a
GAME_NAME	=	cub3d
FLAGS		=	-Wall -Werror -Wextra
CUB_HEADER	=	./include
SRC_GAME	=	./src_game
SRC_MAP		=	./src_map_processing
LIBFT_DIR	=	./libft
MLX_DIR		=	./minilibx-linux
OBJ_DIR		=	./objs

SRC_G			:=	calculation_part.c	collision_processing.c	create_structures.c		dda_algorithm.c\
					draw_floor.c		draw_sky_wall.c			draw_sprite.c			draw_weapon.c\
					events_processing.c	free_memory.c			ft_isspaces.c			ft_split_spaces.c\
					load_textures.c		short_func.c			map_proc_game.c			main.c\
					set_get_pixel.c		sort.c

SRC_M			:=	additional_processing.c		description_processing.c	load_map_from_lst.c\
					map_from_file_to_lst.c		map_validation.c			process_map.c\
					additional_validation.c

REG_S			:=	regime_standart.c
REG_B			:=	regime_bonus.c
REG_CB			:=	regime_creative_bonus.c
REGIMES			:=	$(REG_B)	$(REG_CB)	$(REG_S)

LIBS_PATH		:=	-L. -L$(LIBFT_DIR) -L$(MLX_DIR)

HEADERS			:=	./include/cub.h ./libft/libft.h

LIBS			:=	-lcub3d -lft -lmlx -lXext -lX11 -lm

ifndef WITH_BONUS
REGIME = $(REG_S)
RESID = $(REG_B) $(REG_CB)
endif

ifeq ($(WITH_BONUS), 1)
REGIME = $(REG_B)
RESID = $(REG_S) $(REG_CB)
endif

ifeq ($(WITH_BONUS), 2)
REGIME = $(REG_CB)
RESID = $(REG_S) $(REG_B)
endif

SRC_G	+= $(REGIME)

SRCS		:= 	$(addprefix $(SRC_GAME)/, $(SRC_G)) 			$(addprefix $(SRC_MAP)/, $(SRC_M))

OBJS		:=	$(addprefix $(OBJ_DIR)/, $(SRC_G:c=o))			$(addprefix $(OBJ_DIR)/, $(SRC_M:c=o))

.PHONY: all, re, clean, fclean, libcmpl, bonus, creative

all: $(GAME_NAME)

$(NAME): $(OBJS) | libcmpl
	@ar rc  $@ $?
	@ranlib $@
	@echo "Done!"

$(GAME_NAME): $(NAME)
	@/bin/rm  -f $(addprefix $(OBJ_DIR)/, $(RESID:.c=.o))
	@ar -d $(NAME) $(RESID:.c=.o)
	@gcc $(FLAGS) -O1 -o $(GAME_NAME) $(LIBS_PATH) $(LIBS)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_GAME)/%.c $(HEADERS) | $(OBJ_DIR) 
	@gcc $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_MAP)/%.c $(HEADERS)| $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@

bonus:
	@$(MAKE) 'WITH_BONUS = 1' all

creative:
	@$(MAKE) 'WITH_BONUS = 2' all

libcmpl:
	@echo ">>>LIBFT<<<"
	@cd $(LIBFT_DIR) && make bonus
	@echo ">>>MLX<<<"
	@cd $(MLX_DIR) && make
	@echo "MLX compiled!"

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -f $(addprefix $(OBJ_DIR)/, $(REGIMES:.c=.o))
	@cd $(LIBFT_DIR) && make clean

fclean: clean
	@cd $(LIBFT_DIR) && make fclean
	@cd $(MLX_DIR) && make clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(GAME_NAME)

re: fclean all
