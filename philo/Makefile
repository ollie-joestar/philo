# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oohnivch <oohnivch@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 12:33:39 by oohnivch          #+#    #+#              #
#    Updated: 2025/03/08 12:01:05 by oohnivch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#									Variables								   #
# **************************************************************************** #

CC = cc
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=undefined
CFLAGS = -Wall -Wextra -Werror -g
MFLAGS = --no-print-directory -C
HEADER = -I./includes
NAME = philo

NORMAL = \033[0m
GREEN = \033[1;32m
PURPLE = \033[1;35m
RED = \033[0;31m
YELLOW = \033[0;33m

# **************************************************************************** #
#									Source Files							   #
# **************************************************************************** #

SRC_PATH = src/
OBJ_PATH = obj/

SRC = clean.c \
	  debug1.c \
	  error.c \
	  general_utils.c \
	  init.c \
	  main.c \
	  numbers.c \
	  overseer.c \
	  philo_utils.c \
	  routine.c \
	  time.c \

OBJ = $(SRC:%.c=%.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

# **************************************************************************** #
#									Rules									   #
# **************************************************************************** #

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJS) | logo
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@if ! $(CC) $(CFLAGS) -o $@ -c $< $(HEADER) 2> error.txt; then\
		echo "$(RED)!!!!!!!! ERROR !!!!!!!!$(NORMAL)"; \
		echo "$(YELLOW)Error caused by $<$(NORMAL)\n"; \
		sed '$$d' error.txt; \
		echo "\n$(RED)Aborting makefile........$(NORMAL)"; \
		exit 1; \
	fi

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@rm -f error.txt
	@echo "$(YELLOW)Deleting $(words $(OBJ)) object file(s) $(NORMAL)"
	@echo "$(GREEN)Deletion success! $(NORMAL)"

fclean:
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME) error.txt
	@echo "$(YELLOW)Deleting $(NAME) and $(words $(OBJ)) object file(s) $(NORMAL)" 
	@echo "$(GREEN)Deletion success! $(NORMAL)"

re: fclean all

logo:
	@echo "\n$(RED)"
	@echo "		┏┓┓ •┓       ┓      "
	@echo "		┃┃┣┓┓┃┏┓┏┏┓┏┓┣┓┏┓┏┓┏"
	@echo "		┣┛┛┗┗┗┗┛┛┗┛┣┛┛┗┗ ┛ ┛"
	@echo "		           ┛"
	@echo "$(NORMAL)"

rebonus: fclean bonus

leak: all
	valgrind -s --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes ./$(NAME)

.PHONY: all leak clean fclean re logo
