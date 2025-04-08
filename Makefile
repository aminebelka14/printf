# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 15:16:46 by ambelkac          #+#    #+#              #
#    Updated: 2020/08/20 18:19:53 by ambelkac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

INCLUDES	=   -I ./includes/ft_printf.h

SRCS	=	str_utils.c \
			str_check.c \
			manage_memory.c \
			ft_putnbr_fd.c \
			ft_putnbr_base.c \
			ft_printf.c \
			ft_atoi.c \
			flag_check.c \
			display_params.c \
			display_functions.c \
			display_format.c \
			flag_parsing.c \
			form_parsing.c \
			display_more_functions.c \
			manage_more_memory.c \
			lenght_function.c \
			extended.c

OBJS	=	$(SRCS:.c=.o)

AR	=	ar r

CFLAGS	+=	-Werror -Wall -Wextra

RM	=	rm -f

CLEAN	=	clean

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(AR) $@ $^

clean	:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	: clean fclean all bonus re
