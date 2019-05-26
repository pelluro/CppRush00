# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipham <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 10:32:35 by mipham            #+#    #+#              #
#    Updated: 2019/05/25 19:34:43 by mconti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_retro

_GREEN = $'\033[32m
_CYAN = $'\033[36m
_RED = $'\033[31m
_YELLOW = $'\033[33m
_PURPLE = $'\033[35m
_BLUE = $'\033[34m


CXX := clang++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror -pedantic

files_matthieu := mainmatthieu.cpp

srcfiles :=	Entity/AEntity.class.cpp			\
		Entity/Characters/Character.class.cpp	\
		Entity/Characters/Player.class.cpp \
		Entity/Characters/Creatures/Creature.cpp	\
		Entity/Characters/Creatures/Boss.cpp	\
		Entity/Characters/Creatures/Basic.cpp	\
        Entity/Missiles/Missile.class.cpp			\
		Weapons/Weapon.class.cpp					\
		Weapons/Gun.cpp							\
		Map/Map.class.cpp	\
		Map/Square.class.cpp	\
		Game.class.cpp \

NCURSE = -lncurses

objects  := $(subst .cpp,.o, $(srcfiles))

objects_matthieu := $(subst .cpp,.o, $(files_matthieu))

name_matthieu := matthieu_$(NAME)

all: $(NAME)

$(NAME): $(objects)
	$(CXX) $(CXXFLAGS) $(NCURSE) $(objects) -o $(NAME)
	@echo "${_BLUE}$(NAME) generate${_END} ${_PURPLE}[!${_END}]"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

matthieu: $(objects) $(objects_matthieu)
	$(CXX) $(CXXFLAGS) $(NCURSE) $(objects) $(objects_matthieu) -o $(name_matthieu)
	@echo "${_BLUE}$(NAME) generate${_END} ${_PURPLE}[!${_END}]"

clean:
	rm -f $(objects)
	@echo "${_CYAN}cleaning objects files${_END} ${_PURPLE}[!${_END}]"

fclean: clean
	rm -f $(NAME)
	@echo "${_RED}delete $(NAME) ${_END}${_GREEN}[!${_END}]"

re: fclean all

.PHONY : all, re, clean
