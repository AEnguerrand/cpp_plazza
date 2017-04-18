##
## Makefile for Rendu in /home/enguerand/Rendu/
##
## Made by Enguerrand Allamel
## Login   <enguerrand.allamel@epitech.net>
##
## Started on  Sat Jan 21 11:51:59 2017 Enguerrand Allamel
## Last update Sat Jan 21 11:51:59 2017 Enguerrand Allamel
##

OS :=	$(shell uname)

NAME = 	plazza

CC      = 	g++

RM      = 	rm -f

CPPFLAGS  += 	-W -Wall -Wextra -Werror -std=c++11 	\
							--pipe

CPPFLAGS +=	-I./Encapsulation/ 	\
			-I./Srcs/

LDFLAGS = 	-lpthread

SRCS = 	./Srcs/main.cpp 	\
		./Srcs/Plazza.cpp

SRCS +=	./Encapsulation/Mutex.cpp 		\
		./Encapsulation/Thread.cpp		\
		./Encapsulation/Process.cpp		\
		./Encapsulation/NamedPipe.cpp

OBJ    = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	  $(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
	  @printf "\033[0;32mPlazza compiled successfully !\n\033[0m"

clean:
	  $(RM) $(OBJ)

fclean: clean
	    $(RM) $(NAME)

re: fclean all
