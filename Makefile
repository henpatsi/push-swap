# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 10:43:55 by hpatsi            #+#    #+#              #
#    Updated: 2023/11/22 14:58:14 by hpatsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./libft/libft.a

SOURCES = push_swap.c handle_input.c stack_utils.c check_state.c stack_commands.c \
		  test_stack_print.c

BONUS_SOURCE = checker_bonus.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCE:.c=.o)

CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	cc $(OBJECTS) $(LIBFT) -o $(NAME)

$(OBJECTS): $(SOURCES)

$(LIBFT):
	make -C ./libft

bonus:


clean:
	make clean -C ./libft
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME) 6 4 3 1 7 2 9 5 8