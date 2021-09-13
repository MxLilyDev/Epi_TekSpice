##
## EPITECH PROJECT, 2020
## B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
## File description:
## Makefile
##
OBJS	=	$(patsubst %.cpp, %.o, $(wildcard src/*.cpp))	\
			$(patsubst %.cpp, %.o, $(wildcard src/graph/*.cpp))

INCLUDE	=	include

HFILE	=	$(wildcard $(INCLUDE)/*.hpp)

NAME	=	nanotekspice

INCLUDES	=	$(foreach d, $(INCLUDE), -I$d)

FLAG	=	$(INCLUDES)
FLAG	+=	-g3
FLAG	+=	-Wall -Wextra -O3 -fno-builtin

CC	=	@g++

RM	=	@rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(FLAG)

$(OBJS): $(HFILE)

clean:
	@$(RM) $(OBJS)
	@echo "\e[32m[ DONE ]\033[0m  Cleanned *o"

fclean: clean
	@rm -f $(NAME)
	@echo "\e[32m[ DONE ]\033[0m  Cleanned $(NAME)"

re:	fclean all

.cpp.o:	%.c
	@$(CC) -c $< -o $@ $(FLAG) && echo "\e[32m[ DONE ] \033[0m" $< || echo "\e[91;5m[ FAIL ] \e[25m" $< "\033[0m"

.PHONY: all clean fclean re