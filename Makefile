# **************************************************************************** #
:q
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 14:14:21 by ajearuth          #+#    #+#              #
#    Updated: 2021/08/16 10:38:25 by ajearuth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c 
SRCSD = srcs/
bonus = \

OBJSD = objs/

LIBFT_PATH = libft/
LIBFT_SRCS = ft_putchar_fd.c 
LIBFT_OBJS = $(addprefix $(OBJSD), $(LIBFT_SRCS:.c=.o))
OBJS = $(addprefix $(OBJSD), $(SRCS:.c=.o))
OBJSBONUS = $(bonus:.c=.o)

CC = gcc -c -o
LINKER = ar rcs
FLAGS = -Wall -Wextra -Werror

$(NAME):	$(OBJS) $(LIBFT_OBJS)
	$(LINKER) $@ $(OBJS) $(LIBFT_OBJS)

# bonus:	$(OBJSBONUS) $(OBJS)
#		$(LINKER) $(NAME) $(OBJSBONUS) $(OBJS)

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
