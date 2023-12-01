# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 08:54:08 by hpatsi            #+#    #+#              #
#    Updated: 2023/12/01 10:47:10 by hpatsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

LIBFT = ../libft/libft.a

SOURCES = checker_bonus.c handle_input_bonus.c \
			exec_command_bonus.c p_s_commands_bonus.c r_commands_bonus.c \
			stack_utils_bonus.c check_state_bonus.c

OBJECTS = $(SOURCES:.c=.o)

INCLUDES_DIR = ../includes/

CFLAGS += -Wall -Wextra -Werror -I $(INCLUDES_DIR)

all: $(NAME)

$(NAME): $(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(OBJECTS): $(SOURCES)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all