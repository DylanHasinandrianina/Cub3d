# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 13:47:20 by mgodawat          #+#    #+#              #
#    Updated: 2025/07/09 12:17:29 by mgodawat         ###   ########.fr        #
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
LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_A = $(MLX_DIR)/libmlx.a
MLX_LNK = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# --- Rules ---

all: $(NAME)

help:
	@echo "--------------------------------------------------"
	@echo " cub3d Makefile Help 🧊"
	@echo "--------------------------------------------------"
	@echo "Usage: make [target]"
	@echo ""
	@echo "Targets:"
	@echo "  make / make all    🚀 Compiles the project."
	@echo "  make mlx           🌐 Clones the MiniLibX graphics library."
	@echo "  make clean         🧹 Removes temporary object files."
	@echo "  make fclean        🗑️  Removes all compiled files (inc. executable)."
	@echo "  make re            🔄 Fully recompiles the project from scratch."
	@echo "  make help          ❓ Shows this help message."
	@echo ""

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A)
	@echo "🔗 Linking executable '$(NAME)'..."
	@$(CC) $(OBJS) $(LIBFT_A) $(MLX_LNK) -o $(NAME)
	@echo "🚀 Done! Executable '$(NAME)' is ready to use."

$(LIBFT_A):
	@echo "📚 Building libft..."
	@$(MAKE) -s -C $(LIBFT_DIR)

# MODIFIED: Changed the dependency to be order-only.
$(MLX_A): | check_mlx
	@echo "🖼️  Building minilibx..."
	@$(MAKE) -s -C $(MLX_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | check_mlx
	@echo "⚙️  Compiling $<..."
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

mlx:
	@echo "🌐 Cloning MiniLibX repository..."
	@git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)
	@echo "✅ MiniLibX cloned successfully."

check_mlx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "❌ Error: MiniLibX directory not found."; \
		echo "👉 Please run 'make mlx' to clone the library first."; \
		exit 1; \
	fi

clean:
	@echo "🧹 Cleaning object directory..."
	@rm -rf $(OBJS_DIR)
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -s -C $(LIBFT_DIR) fclean; fi
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -s -C $(MLX_DIR) clean; fi
	@echo "✅ Clean complete."

fclean:
	@echo "🗑️  Cleaning object directory..."
	@rm -rf $(OBJS_DIR)
	@echo "🗑️  Cleaning libft..."
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -s -C $(LIBFT_DIR) fclean; fi
	@echo "🗑️  Removing executable '$(NAME)'..."
	@rm -f $(NAME)
	@echo "🗑️  Removing minilibx directory..."
	@rm -rf $(MLX_DIR)
	@echo "✨ Project fully cleaned."

re: fclean all

.PHONY: all help mlx check_mlx clean fclean re
