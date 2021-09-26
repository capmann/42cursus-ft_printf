# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 22:31:24 by cmarteau          #+#    #+#              #
#    Updated: 2021/09/26 16:23:32 by cmarteau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c ft_printf_utils.c ft_printf_utils_1.c \
	ft_printf_utils_2.c ft_printf_utils_3.c ft_printf_utils_4.c \
	ft_printf_utils_5.c ft_printf_utils_6.c ft_convert.c ft_flags.c

OBJS	=	${SRCS:.c=.o}

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a

.c.o	:	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}	:	${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all	:	${NAME}

clean	:
		rm -rf ${OBJS}

fclean	:	clean
	rm -rf ${NAME}

re	:	fclean all

.PHONY	:	all clean fclean re

