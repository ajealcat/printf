# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 14:14:21 by ajearuth          #+#    #+#              #
#    Updated: 2021/08/29 15:35:59 by ajearuth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils_two.c 
SRCSD = srcs/
bonus = \

OBJSD = objs/

LIBFT_PATH = libft/
LIBFT_SRCS = ft_putchar_fd.c ft_strlen.c ft_putstr_fd.c ft_putnbr_fd.c ft_putnbr_base_fd.c \
			ft_itoa.c
LIBFT_OBJS = $(addprefix $(OBJSD), $(LIBFT_SRCS:.c=.o))
OBJS = $(addprefix $(OBJSD), $(SRCS:.c=.o))
OBJSBONUS = $(bonus:.c=.o)

CC = gcc -c -o
LINKER = ar rcs
FLAGS = -Wall -Wextra -Werror

$(NAME):	$(OBJS) $(LIBFT_OBJS)
	$(LINKER) $@ $(OBJS) $(LIBFT_OBJS)

$(OBJSD)%.o: $(SRCSD)%.c
	mkdir -p $(OBJSD)
	$(CC) $@ $< $(FLAGS) 

$(OBJSD)%.o: $(LIBFT_PATH)%.c
	$(CC) $@ $< $(FLAGS)

all: $(NAME)

clean:
	rm -rf $(OBJSD) $(OBJSBONUS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all 

.PHONY: all clean fclean re
