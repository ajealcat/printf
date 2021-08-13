# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajearuth <ajearuth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 14:14:21 by ajearuth          #+#    #+#              #
#    Updated: 2021/08/13 14:28:24 by ajearuth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################################
#                                           #
#               Coucou Github !             #
#         Qu'est ce qu'on ferait pas        #
#             pour pas bosser !!            #
#                                           #
#############################################


NAME := libftprintf.a

SRCS := \
bonus := \

LIBDIR := libft/
LIBSRC :=

LIBOBJS := $(LIBSRC:.c=.o)
LIBOBJS := $(addprefix $(OBJSD), $(LIBOBJS))
OBJS := $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJSD), $(OBJS))
OBJSBONUS := $(bonus: .c=.o)

CC := gcc -c -o
LINKER := ar rcs
FLAG := -Wall -Wextra -Werror

$(NAME):	$(OBJS)
	$(LINKER) $(NAME) $(OBJS)

# Manque des trucs pour que ca marche

all:	$(NAME)

bonus:	$(OBJSBONUS) $(OBJS)
		$(LINKER) $(NAME) $(OBJSBONUS) $(OBJS)

$(OBJSD)%.o:	$(SRCSD)%.c
	$(CC) $@^ $(FLAGS)

clean:
	rm -rf $(OBJS) $(OBJSBONUS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all 

.PHONY: all clean fclean re
