# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 13:08:20 by obouhour          #+#    #+#              #
#    Updated: 2025/03/14 03:34:52 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de la bibliothèque
NAME = libft.a

# Compilateur et options
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Fichiers source pour libft
FILES = ft_atoi \
		ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_putchar_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_split \
		ft_strchr \
		ft_strdup \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strmapi \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_strtrim \
		ft_substr \
		ft_tolower \
		ft_toupper \
		free_dbl_tab \
		ft_strcmp \
		handle_error \
		handle_error_free \
		handle_error_close \
		handle_error_close_free \

# Fichiers source pour printf
PRINTF_DIR = ./ft_printf/
PRINTF_FILES = ft_printf ft_print_ptr ft_putchar ft_putnbr_base ft_putnbr_unsigned ft_putnbr ft_putstr ft_strlen_printf

# Fichiers source pour get_next_line
GNL_DIR = ./get_next_line/
GNL_FILES = get_next_line get_next_line_utils

# Chemins des sources et objets
SRCS_DIR = ./
SRCS_BONUS_DIR = ./bonus_a_ajouter/
SRCS_BONUS_FILES = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstclear ft_lstdelone ft_lstiter ft_lstmap

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR), $(addsuffix .c, $(SRCS_BONUS_FILES)))
PRINTF_SRCS = $(addprefix $(PRINTF_DIR), $(addsuffix .c, $(PRINTF_FILES)))
GNL_SRCS = $(addprefix $(GNL_DIR), $(addsuffix .c, $(GNL_FILES)))

ALL_SRCS = $(SRCS) $(PRINTF_SRCS) $(GNL_SRCS) $(SRCS_BONUS)

# Objets
OBJS = $(ALL_SRCS:.c=.o)

# Cibles
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

# Règle pour compiler les fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cible de nettoyage
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

