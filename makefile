# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 16:57:55 by obouhour          #+#    #+#              #
#    Updated: 2025/04/11 14:31:11 by obouhour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Paths
MLX_PATH = ./mlx
MLX_LIB = $(MLX_PATH)/libmlx.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Source directories
TEST_MLX_DIR = ./test_mlx
TEST_EXTRACT_DIR = ./test_extract_data

# Source files
SRCS = $(TEST_MLX_DIR)/main.c \
		$(TEST_MLX_DIR)/img.c \
		$(TEST_MLX_DIR)/keyhook.c \
		$(TEST_MLX_DIR)/utils.c \
		$(TEST_MLX_DIR)/player.c \
		$(TEST_EXTRACT_DIR)/open_maps.c

# Include directories
INCLUDES = -I$(TEST_MLX_DIR) \
			-I$(TEST_EXTRACT_DIR) \
			-I$(MLX_PATH) \
			-I$(LIBFT_PATH)

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Main target
$(NAME): $(MLX_LIB) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) -L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft -L/usr/lib -lXext -lX11 -lm -o $(NAME)

# Object files compilation
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# MLX compilation
$(MLX_LIB):
	make -C $(MLX_PATH)

# Libft compilation
$(LIBFT):
	make -C $(LIBFT_PATH)

# Clean object files
clean:
	rm -f $(OBJS)
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean

# Clean everything
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re