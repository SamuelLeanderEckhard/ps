# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 15:47:51 by seckhard          #+#    #+#              #
#    Updated: 2024/09/08 23:32:15 by seckhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colours
GREEN=\e[0;32m
RED=\e[0;31m
NC=\e[0m

# Standard
NAME			= push_swap

# Source Files
SOURCES 		= \
					main.c create.c error.c push.c \
					sort.c utils.c \

# Object Files	
OBJ_DIR			= o_files
OBJECTS 		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

# Directories
INCLUDE_DIR		= header_file
INCLUDE 		= $(INCLUDE_DIR)/push_swap.h
LIBFT			= ./libft/libft.a
FT_PRINTF		= ./ft_printf/libftprintf.a

# Compiler and CFlags
CC 				= cc
CFLAGS			= -Wall -Wextra -Werror -I$(INCLUDE_DIR)
LDFLAGS			= -L./libft -lft -L./ft_printf -lftprintf

# Build Rules
$(NAME): 		$(OBJECTS) $(LIBFT) $(FT_PRINTF)
				$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LDFLAGS)
				@echo "$(GREEN)Project built successfully$(NC)"

all:			$(NAME)

%.o: %.c		$(INCLUDE)
				@echo "$(GREEN)Compiling $<$(NC)"
				$(CC) -c $(CFLAGS) $< -o $@

.DEFAULT_GOAL := all

$(LIBFT):
	make -C ./libft

$(FT_PRINTF):
	make -C ./ft_printf

$(OBJ_DIR)/%.o: %.c $(INCLUDE)
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
				rm -rf $(OBJ_DIR)
				make -C ./libft clean
				make -C ./ft_printf clean
				@echo "$(RED)Cleaned$(NC)"

fclean:			clean
				rm -f $(NAME)
				make -C ./libft fclean
				make -C ./ft_printf fclean
				@echo "$(RED)Fully cleaned$(NC)"

re:				fclean all
				@echo "$(GREEN)Project rebuilt successfully$(NC)"

.PHONY:			all clean fclean re