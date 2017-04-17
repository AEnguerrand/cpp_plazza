##
## Makefile for cpp_plazza in /Users/metge_q/rendu/cpp_plazza
##
## Made by Quentin Metge
## Login   <metge_q@epitech.net>
##
## Started on  Mon Apr 17 19:25:10 2017 Quentin Metge
## Last update Mon Apr 17 19:25:10 2017 Quentin Metge
##

OS 				:= 	$(shell uname)

NAME    	= 	plazza

CC				=		g++

RM      	= 	rm -f

CPPFLAGS  =		-Wall -Wextra -Werror -std=c++11

CPPFLAGS	+=	-I./Srcs/															\

SRC     	=		./Srcs/main.cpp 											\
							./Srcs/plazza.cpp											\

OBJ     	= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -ldl -o $(NAME) $(CPPFLAGS)
	@printf "\033[0;32mPlazza compiled successfully !\n\033[0m"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
