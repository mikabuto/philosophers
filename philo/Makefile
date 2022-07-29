# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 14:04:22 by mikabuto          #+#    #+#              #
#    Updated: 2022/07/29 15:37:48 by mikabuto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	philo

SRCS =	main.c utils.c init.c libft.c simulation.c
OBJS = 	$(SRCS:.c=.o)

HEAD =	philo.h

CC = 	cc
FLAGS = -Wall -Wextra -Werror -fsanitize=thread -g
RM = 	rm -f

all:	$(NAME)

$(NAME): $(OBJS) $(HEAD) Makefile
	$(CC) $(FLAGS) $(OBJS) -I $(HEAD) -o $(NAME)

.c.o: $(HEAD)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	${RM} ${OBJS} $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re bonus