# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 16:57:55 by obouhour          #+#    #+#              #
#    Updated: 2025/04/15 17:04:42 by obouhour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D
CC := cc
CFLAGS := -Wall -Wextra -Werror

# Paths
MLX_PATH := ./mlx
MLX_LIB := $(MLX_PATH)/libmlx.a

LIBFT_PATH := ./libft
LIBFT := $(LIBFT_PATH)/libft.a

TEST_MLX_DIR := ./test_mlx
TEST_EXTRACT_DIR := ./test_extract_data
RAYCASTING_DIR := $(TEST_MLX_DIR)/raycasting

# Sources
SRCS := \
	$(TEST_MLX_DIR)/main.c \
	$(TEST_MLX_DIR)/img.c \
	$(TEST_MLX_DIR)/keyhook.c \
	$(TEST_MLX_DIR)/utils.c \
	$(TEST_MLX_DIR)/player.c \
	$(RAYCASTING_DIR)/raycasting.c \
	$(RAYCASTING_DIR)/init_struct.c \
	$(TEST_EXTRACT_DIR)/open_maps.c

OBJS := $(SRCS:.c=.o)

# Includes
INCLUDES := -I$(TEST_MLX_DIR) \
			-I$(TEST_EXTRACT_DIR) \
			-I$(RAYCASTING_DIR) \
			-I$(MLX_PATH) \
			-I$(LIBFT_PATH)

# Rules
all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft -L/usr/lib -lXext -lX11 -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_PATH) clean
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re