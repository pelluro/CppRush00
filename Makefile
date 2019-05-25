# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipham <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 10:32:35 by mipham            #+#    #+#              #
#    Updated: 2019/05/22 10:32:40 by mipham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = eval_expr

_GREEN = $'\033[32m
_CYAN = $'\033[36m
_RED = $'\033[31m
_YELLOW = $'\033[33m
_PURPLE = $'\033[35m
_BLUE = $'\033[34m


CXX := clang++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror -pedantic
NCURSE := -lncurses

srcfiles := main.cpp		Entity/AEntity.class.cpp	\
		Map/Map.class.cpp	Map/Square.class.cpp

objects  := $(subst .cpp,.o, $(srcfiles))



all: $(NAME)

$(NAME): $(objects)
	$(CXX) $(CXXFLAGS) $(NCURSE) $(objects) -o $(NAME)
	@echo "${_BLUE}$(NAME) generate${_END} ${_PURPLE}[!${_END}]"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f $(objects)
	@echo "${_CYAN}cleaning objects files${_END} ${_PURPLE}[!${_END}]"

fclean: clean
	rm -f $(NAME)
	@echo "${_RED}delete $(NAME) ${_END}${_GREEN}[!${_END}]"

re: fclean all

.PHONY : all, re, clean