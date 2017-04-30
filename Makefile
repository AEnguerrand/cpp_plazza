##
## Makefile for Rendu in /home/enguerand/Rendu/
##
## Made by Enguerrand Allamel
## Login   <enguerrand.allamel@epitech.net>
##
## Started on  Sat Jan 21 11:51:59 2017 Enguerrand Allamel
## Last update Sat Jan 21 11:51:59 2017 Enguerrand Allamel
##

NAME 			= 		plazza

CC      	= 		g++

RM      	= 		rm -f

CPPFLAGS  += 		-W -Wall -Wextra -Werror -std=c++11 	\
								--pipe -o3

CPPFLAGS 	+=		-I./Srcs  							\
								-I./Srcs/Encapsulation 	\
								-I./Srcs/Process 				\
								-I./Srcs/Scrapper 			\
								-I./Srcs/ManagerProcess	\
								-I./Srcs/Graphic

LDFLAGS 	= 		-lpthread

UIFLAGS		=			-lsfml-graphics	\
								-lsfml-window		\
								-lsfml-system		\
								-lsfml-audio

SRCS 			= 		./Srcs/main.cpp 	\
								./Srcs/Plazza.cpp

SRCS 			+=		./Srcs/Process/ThreadPool.cpp 			\
								./Srcs/Process/ThreadPoolWorker.cpp	\
								./Srcs/Process/ProcessPlazza.cpp \
								./Srcs/Process/ProcessChildPlazza.cpp

SRCS 			+= 		./Srcs/ManagerProcess/ManagerProcess.cpp

SRCS 			+=		./Srcs/Encapsulation/Mutex.cpp 			\
								./Srcs/Encapsulation/Thread.cpp			\
								./Srcs/Encapsulation/Process.cpp		\
								./Srcs/Encapsulation/NamedPipe.cpp	\
								./Srcs/Encapsulation/CondVar.cpp

SRCS			+=		./Srcs/Scrapper/Scrapper.cpp				\
								./Srcs/Scrapper/Phone.cpp						\
								./Srcs/Scrapper/Ip.cpp							\
								./Srcs/Scrapper/Email.cpp						\


SRCS_TXT 	= 		./Srcs/Display/Text.cpp

SRCS_UI		=			./Srcs/Display/Graphic.cpp

OBJ    		= 		$(SRCS:.cpp=.o)

OBJ_TXT		=			$(SRCS_TXT:.cpp=.o)

OBJ_UI		=			$(SRCS_UI:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ) $(OBJ_TXT)
	  $(CC) $(OBJ) $(OBJ_TXT) -o $(NAME) $(LDFLAGS)
	  @printf "\033[0;32mPlazza compiled successfully !\n\033[0m"

ui: $(OBJ) $(OBJ_UI)
		$(CC) $(OBJ) $(OBJ_UI) -o $(NAME) $(LDFLAGS) $(UIFLAGS)
		@printf "\033[0;32mPlazza (GUI) compiled successfully !\n\033[0m"

clean:
	  $(RM) $(OBJ) $(OBJ_GUI)

fclean: clean
	  $(RM) $(NAME)

re: fclean all
