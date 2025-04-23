################################################################################
#                                     COLORS                                   #
################################################################################

DEFAULT			= \033[0m
RED				= \033[1;31m
GREEN			= \033[1;32m
YELLOW			= \033[1;33m
BLUE			= \033[1;34m
MAGENTA			= \033[1;35m
CYAN			= \033[1;36m
LIGHT_CYAN		= \033[1;96m
WHITE			= \033[1;37m

################################################################################
#                                     HEADER                                   #
################################################################################

define HEADER

$(BLUE)   ______      __   _____ _____$(DEFAULT)
$(BLUE)  / ____/_  __/ /_ |__  // __  \ $(DEFAULT)
$(BLUE) / /   / / / / __ \ /_ </ / / /$(DEFAULT)
$(BLUE)/ /___/ /_/ / /_/ /__/ / /_/ /$(DEFAULT)
$(BLUE)\____/\__,_/_.___/____/\____/$(DEFAULT)

endef
export HEADER

################################################################################
#                                 PROGRESS BAR                                 #
################################################################################

define PROGRESS_BAR
	@TOTAL_STEPS=20; CURRENT_STEP=0; \
	while [ $$CURRENT_STEP -lt $$TOTAL_STEPS ]; do \
		CURRENT_STEP=$$(($$CURRENT_STEP + 1)); \
		echo -n "$(GREEN)▰$(DEFAULT)"; \
		sleep 0.01; \
	done; \
	echo " ✔️";
endef

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME			= cub3D
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

################################################################################
#                                PROGRAM'S SOURCES                             #
################################################################################

# Directory paths
SRC				= ./srcs/
PARSING			= $(SRC)01_parsing/
INIT			= $(SRC)02_initialization/
EXEC			= $(SRC)03_exec/
RAY				= $(EXEC)raycasting/
OBJ				= ./objs/
MLX_DIR			= ./minilibx-linux/
MYLIB_DIR		= ./my_lib/
MYLIB_A			= $(MYLIB_DIR)my_lib.a
MYLIB_INC		= $(MYLIB_DIR)includes/
INCLUDES		= ./includes/ $(MLX_DIR) $(MYLIB_INC)

# Libraries
MLX				= -L $(MLX_DIR) -lmlx -lXext -lX11 -lm
MYLIB			= -L $(MYLIB_DIR) -l:my_lib.a

# Source files
SRCS			= $(SRC)main.c \
				$(SRC)utils.c \
				$(INIT)initialization.c \
				$(PARSING)01_read_cub_file.c \
				$(PARSING)02_parse_elements.c \
				$(PARSING)03_parse_map.c \
				$(PARSING)04_parse_map_player.c \
				$(PARSING)parse_elements_utils.c \
				$(PARSING)parse_map_utils.c \
				$(EXEC)keyhook.c \
				$(EXEC)move.c \
				$(EXEC)rotation.c \
				$(RAY)raycasting.c \
				$(RAY)handle_color.c \
				$(RAY)init_ray.c \
				$(RAY)dda.c \
				$(RAY)draw_wall.c \

# Object files
OBJS			= $(patsubst $(SRC)%, $(OBJ)%, $(SRCS:.c=.o))

################################################################################
#                                     RULES                                    #
################################################################################

# Default rule
all: $(NAME)

# MLX configuration
mlx_config:
	@if [ ! -f "$(MLX_DIR)/Makefile.gen" ]; then \
		cd $(MLX_DIR) && ./configure; \
	fi

# MLX compilation
$(MLX_DIR)libmlx.a: mlx_config
	@make -C $(MLX_DIR)

# my_lib compilation
$(MYLIB_A):
	@make -C $(MYLIB_DIR)

# Object files compilation
$(OBJ)%.o: $(SRC)%.c
	@mkdir -p $(dir $@)
	@echo "$(CYAN)Compiling $< into $@$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(foreach dir,$(INCLUDES),-I$(dir))

# Main executable compilation
$(NAME): $(MLX_DIR)libmlx.a $(MYLIB_A) $(OBJS)
	@echo -n "\n🔗 $(WHITE)Linking $(CYAN)$(NAME)$(DEFAULT) executable\t\t\t"
	@$(CC) $(CFLAGS) $(OBJS) $(MYLIB) $(MLX) -o $(NAME)
	$(PROGRESS_BAR)
	@echo "\n$$HEADER"
	@echo "$(GREEN)$(NAME) compiled successfully$(DEFAULT)"

# Clean rule
clean:
	@if [ -f "$(MLX_DIR)Makefile.gen" ]; then \
		make clean -C $(MLX_DIR); \
	fi
	@make clean -C $(MYLIB_DIR)
	@echo -n "\n🧹 $(RED)Cleaning up$(DEFAULT) project object files\t\t"
	@$(RM) -r $(OBJ)
	$(PROGRESS_BAR)

# Full clean rule
fclean: clean
	@make fclean -C $(MYLIB_DIR)
	@echo -n "\n🗑️  $(RED)Deleting $(CYAN)$(NAME)$(DEFAULT) executable\t\t"
	@$(RM) $(NAME)
	$(PROGRESS_BAR)

# Rebuild rule
re: fclean all

# Debug rule
debug: $(MLX_DIR)libmlx.a $(MYLIB_A) $(OBJS)
	@echo -n "\n🔗 $(CYAN)Compiling in debug mode $(DEFAULT)\t\t\t"
	@$(CC) $(CFLAGS) $(OBJS) $(MYLIB) $(MLX) -o $(NAME) -g3 -fsanitize=address
	$(PROGRESS_BAR)

# Help target
help:
	@echo "$(CYAN)Available commands:$(DEFAULT)"
	@echo "  make all     : Build the $(NAME) executable"
	@echo "  make clean   : Remove object files"
	@echo "  make fclean  : Remove object files and executable"
	@echo "  make re      : Rebuild from scratch"
	@echo "  make debug   : Build with debug flags"
	@echo "  make help    : Display this help message"

.PHONY: all clean fclean re debug mlx_config help
