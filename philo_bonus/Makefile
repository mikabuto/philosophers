# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 14:04:22 by mikabuto          #+#    #+#              #
#    Updated: 2022/07/29 16:07:58 by mikabuto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	philo_bonus

SRCS =	main_bonus.c utils_bonus.c init_bonus.c simulation_bonus.c
OBJS = 	$(SRCS:.c=.o)

HEAD =	philo_bonus.h

CC = 	cc
FLAGS = -Wall -Wextra -Werror
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