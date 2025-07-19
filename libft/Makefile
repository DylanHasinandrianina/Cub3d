# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 14:19:22 by mgodawat          #+#    #+#              #
#    Updated: 2025/07/19 14:19:24 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables ---
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

# --- Project Structure ---
OBJS_DIR = objs

# --- Auto-discovery of Files ---
SRCS = $(wildcard *.c)
INCS = $(wildcard includes/*.h)
# Place all object files into the OBJS_DIR
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

# --- Rules ---
all: $(NAME)

# The library depends on all the object files.
$(NAME): $(OBJS)
	@echo "✅ libft compiled successfully. Archiving library $(NAME)..."
	@ar rcs $@ $(OBJS)
	@echo "📚 Library $(NAME) is ready."

# Rule to compile a .c file into a .o file inside the OBJS_DIR
# The '|' makes sure the directory exists before the rule runs.
$(OBJS_DIR)/%.o: %.c $(INCS) | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the object directory if it doesn't exist.
$(OBJS_DIR):
	@mkdir -p $@

# --- Cleaning Rules ---
clean:
	@echo "🧹 Cleaning object directory..."
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "🗑️  Cleaning library..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re