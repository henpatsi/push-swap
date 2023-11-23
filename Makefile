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
		  push_smallest_sort.c \
		  push_to_place_sort.c \
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

debug:
	cc $(OBJECTS) $(LIBFT) -g -o $(NAME)

test: $(NAME)
	./$(NAME) 2 1 3 6 5 8
	./$(NAME) 3 4 1 10 7 5 6 2 8 9
	./$(NAME) 6 9 13 19 15 5 17 12 20 10 4 7 11 18 14 16 2 1 3 8
#	./$(NAME) 77 92 70 50 69 32 9 65 86 19 98 89 1 52 2 6 36 68 10 63 79 57 41 53 35 3 23 83 59 20 45 62 38 18 88 44 71 95 55 93 56 100 4 91 99 48 43 40 82 31 72 24 13 54 61 90 7 17 5 67 37 34 80 15 74 8 26 81 11 78 58 21 96 28 87 16 30 39 64 75 22 94 46 42 66 27 97 49 14 85 25 73 76 12 29 51 47 84 33 60
