# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 13:47:20 by mgodawat          #+#    #+#              #
#    Updated: 2025/08/05 13:37:12 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -Ilibft/includes -Iminilibx-linux -g

# --- Project Structure ---
NAME = cub3d
SRCS_DIR = src
OBJS_DIR = objs
SRCS =
SRCS = \
$(SRCS_DIR)/execution/arrowkeys.c \
$(SRCS_DIR)/execution/cleanup.c \
$(SRCS_DIR)/execution/draw_walls.c \
$(SRCS_DIR)/execution/draw.c \
$(SRCS_DIR)/execution/init_game.c \
$(SRCS_DIR)/execution/key_hook.c \
$(SRCS_DIR)/execution/mlx_utils.c \
$(SRCS_DIR)/execution/raycaster.c \
$(SRCS_DIR)/execution/render_frame.c \
$(SRCS_DIR)/execution/texture.c \
$(SRCS_DIR)/execution/wasd.c \
$(SRCS_DIR)/execution/process_map.c \
$(SRCS_DIR)/parsing/map_checks/check_map_error.c \
$(SRCS_DIR)/parsing/map_checks/get_map.c \
$(SRCS_DIR)/parsing/map_checks/get_max_width.c \
$(SRCS_DIR)/parsing/map_checks/maps_checks_utils.c \
$(SRCS_DIR)/parsing/map_checks/normalize_map.c \
$(SRCS_DIR)/parsing/other_elem_checks/check_color.c \
$(SRCS_DIR)/parsing/other_elem_checks/check_element_error.c \
$(SRCS_DIR)/parsing/other_elem_checks/check_element_position.c \
$(SRCS_DIR)/parsing/other_elem_checks/check_texture.c \
$(SRCS_DIR)/parsing/other_elem_checks/other_elem_utils.c \
$(SRCS_DIR)/parsing/check_error.c \
$(SRCS_DIR)/parsing/parsing.c \
$(SRCS_DIR)/parsing/utils.c \
$(SRCS_DIR)/main.c

OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

# --- Library Configurations ---
LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_A = $(MLX_DIR)/libmlx.a
MLX_LNK = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
MLX_GIT = https://github.com/42Paris/minilibx-linux.git

# --- Main Rules ---

all: $(NAME)

# The executable depends on object files AND the actual library files.
$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A)
	@echo "🔗 Linking executable '$(NAME)'..."
	@$(CC) $(OBJS) $(LIBFT_A) $(MLX_LNK) -o $(NAME)
	@echo "🚀 Done! Executable '$(NAME)' is ready to use."

# --- Library Rules ---

# Rule to build libft.a.
$(LIBFT_A):
	@echo "📚 Building libft..."
	@$(MAKE) -s -C $(LIBFT_DIR)

# Rule to build libmlx.a. It now depends on the directory existing.
$(MLX_A): $(MLX_DIR)
	@echo "🖼️  Building minilibx..."
	@$(MAKE) -s -C $(MLX_DIR)

# --- Compilation and Utility Rules ---

# Rule to compile .c files. It has an order-only dependency on the MLX directory.
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(MLX_DIR)
	@echo "⚙️  Compiling $<..."
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) -c $< -o $@

# NEW: Rule to clone MiniLibX if the directory doesn't exist.
$(MLX_DIR):
	@echo "🌐 MiniLibX not found. Cloning repository..."
	@git clone $(MLX_GIT) $(MLX_DIR)

# --- Cleaning Rules ---

clean:
	@echo "🧹 Cleaning object directory..."
	@rm -rf $(OBJS_DIR)
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -s -C $(LIBFT_DIR) fclean; fi
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -s -C $(MLX_DIR) clean; fi
	@echo "✅ Clean complete."

fclean:
	@echo "🗑️  Cleaning everything..."
	@rm -rf $(OBJS_DIR)
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -s -C $(LIBFT_DIR) fclean; fi
	@rm -f $(NAME)
	@rm -rf $(MLX_DIR)
	@echo "✨ Project fully cleaned."

re: fclean all

.PHONY: all clean fclean re
