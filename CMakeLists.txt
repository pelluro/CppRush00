cmake_minimum_required(VERSION 3.14)
project(CppRush00)

set(CMAKE_CXX_STANDARD 98)

add_library(CppRush00
        main.cpp
        Ncurses.cpp
        Ncurses.hpp
        Entity/Bonus/Bonus.class.hpp
        Entity/Bonus/Bonus.class.cpp
        Entity/Bonus/HealthPack.class.hpp

        Entity/Bonus/WeaponUpgrade.class.cpp
        Map/Map.class.cpp
        Map/Map.class.hpp
        Map/Square.class.cpp
        Map/Square.class.hpp
        )