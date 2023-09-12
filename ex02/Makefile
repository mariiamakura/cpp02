# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 16:36:01 by mparasku          #+#    #+#              #
#    Updated: 2023/09/12 16:36:02 by mparasku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Fixed.cpp
OBJS = $(patsubst %.cpp, obj/%.o, $(SRCS))

all : obj $(NAME)

obj :
	mkdir -p obj

$(NAME) : $(OBJS) $(SRCS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

obj/%.o : %.cpp
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -rf obj

fclean : clean
	rm -f $(NAME)

re : fclean all