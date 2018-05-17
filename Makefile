# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile1                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/17 11:28:00 by tvoronyu          #+#    #+#              #
#    Updated: 2018/05/17 14:21:00 by tvoronyu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
				write.c \
				ft_verificare.c \
				ft_check.c \
				ft_check_2.c \
				main_2.c \
				makefigure.c \
				write_box.c \
				tryfig.c \
				lineres.c \
				makebox.c \
				sendfigure.c \
				backtrack.c \

OBJ = *.o

INC = -I fillit.h

LIBFT =	libft/libft.a

CC = gcc

FLAGS = 

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
		$(CC) $(FLAGS) -c $(SRC)

$(LIBFT):
		make -C ./libft/

clean:
		rm -f $(OBJ)
			make clean -C ./libft/

fclean: clean
		rm -f $(NAME)
			make fclean -C ./libft/

re: fclean all
