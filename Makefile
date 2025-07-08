# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 13:47:20 by mgodawat          #+#    #+#              #
#    Updated: 2025/07/08 15:58:12 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -Ilibft/includes -Iminilibx-linux -g

# --- Project Structure ---
NAME = cub3d
SRCS_DIR = src
OBJS_DIR = objs
SRCS = $(shell find $(SRCS_DIR) -name '*.c')
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

# --- Library Configurations ---
LIBFT = ./libft/libft.a
MLX_DIR = minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# --- Rules ---

all:
	@# NEW: Check if MiniLibX exists before trying to build
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "❌ Error: MiniLibX directory not found."; \
		echo "👉 Please run 'make mlx' to clone the library first."; \
		exit 1; \
	fi
	@$(MAKE) $(NAME)

# Main executable target
$(NAME): $(OBJS)
	@echo "📚 Building libft..."
	@$(MAKE) -s -C ./libft
	@echo "🖼️  Building minilibx..."
	@$(MAKE) -s -C $(MLX_DIR)
	@echo "🔗 Linking executable '$(NAME)'..."
	@$(CC) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "🚀 Done! Executable '$(NAME)' is ready to use."

# Rule to compile source files into object files
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "⚙️  Compiling $<..."
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# NEW: Dedicated rule to clone the MiniLibX library
mlx:
	@echo "🌐 Cloning MiniLibX repository..."
	@git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)
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

.PHONY: all clean fclean re mlx
