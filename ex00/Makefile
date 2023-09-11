NAME = fixed
SRC = main.cpp Fixed.cpp
OBJS = $(patsubst $(SRC), $(OBJ_DIR)/%.o, $(SRC))
FLAGS = c++ -Wall -Wextra -Werror -std=c++98
OBJ_DIR = obj

all: $(NAME)

$(NAME): $(OBJS)
	$(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC)
	@mkdir "obj"
	@$(FLAGS) -o $@ -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all