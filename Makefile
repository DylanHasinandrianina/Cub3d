# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 13:47:20 by mgodawat          #+#    #+#              #
#    Updated: 2025/07/08 15:05:59 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -Ilibft/includes -Iminilibx-linux -g

# --- Project Structure ---
NAME = cub3d
SRCS_DIR = src
OBJS_DIR = objs

# UPDATED: Recursively find all .c files in SRCS_DIR and its subdirectories
SRCS = $(shell find $(SRCS_DIR) -name '*.c')

# Generate object file paths in OBJS_DIR, maintaining the subdirectory structure
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

# --- Library Configurations ---
# libft configuration
LIBFT = ./libft/libft.a

# minilibx configuration
MLX_REPO = https://github.com/42Paris/minilibx-linux.git
MLX_DIR = minilibx-linux
MLX_CHECK = $(MLX_DIR)/.git
MLX = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# --- Rules ---

all: $(NAME)

# Main executable target depends on the object files and the minilibx library
$(NAME): $(OBJS) $(MLX_CHECK)
	@echo "📚 Building libft..."
	@$(MAKE) -s -C ./libft
	@echo "🖼️  Building minilibx..."
	@$(MAKE) -s -C $(MLX_DIR)
	@echo "🔗 Linking executable '$(NAME)'..."
	@$(CC) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "🚀 Done! Executable '$(NAME)' is ready to use."

# UPDATED: Rule to compile source files into object files, creating subdirectories as needed
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "⚙️  Compiling $<..."
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to clone minilibx if not present
$(MLX_CHECK):
	@echo "🌐 MiniLibX not found. Cloning repository..."
	@git clone --quiet $(MLX_REPO) $(MLX_DIR)
	@echo "✅ MiniLibX cloned successfully."

clean:
	@echo "🧹 Cleaning libft..."
	@$(MAKE) -s -C ./libft fclean
	@echo "🧹 Cleaning object directory..."
	@rm -rf $(OBJS_DIR)
	@if [ -d "$(MLX_DIR)" ]; then \
		echo "🧹 Cleaning minilibx..."; \
		$(MAKE) -s -C $(MLX_DIR) clean; \
	fi
	@echo "✅ Clean complete."

fclean: clean
	@echo "🗑️  Removing executable '$(NAME)'..."
	@rm -f $(NAME)
	@echo "🗑️  Removing minilibx directory..."
	@rm -rf $(MLX_DIR)
	@echo "✨ Project fully cleaned."

re: fclean all

.PHONY: all clean fclean re
