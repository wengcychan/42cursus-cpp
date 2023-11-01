NAME = diamondtrap

SRCS = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS) $(FLAGS)

%.o: %.cpp
	$(CC) -c $(FLAGS) -o $@ $<

.PHONY: clean fclean re

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
