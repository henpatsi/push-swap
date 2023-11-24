# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:05:59 by hpatsi            #+#    #+#              #
#    Updated: 2023/11/21 14:05:59 by hpatsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	  ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
	  ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
	  ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_isspace.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	  ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	  ft_lstiter.c ft_lstmap.c ft_putunbr_fd.c ft_puthex_fd.c \
	  ft_putaddr_fd.c ft_printf.c ft_printf_strutils.c \
	  ft_printf_nbrutils.c ft_printf_hexutils.c

OBJECTS = $(SOURCES:.c=.o)

INCLUDES_DIR = ../includes/

CFLAGS += -Wall -Wextra -Werror -I $(INCLUDES_DIR)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests: $(NAME)
	cc $(CFLAGS) tests.c $(NAME) -I $(INCLUDES_DIR) -o test.out
	./test.out
	rm -f test.out