cmake_minimum_required(VERSION 3.14)
project(CppRush00)

set(CMAKE_CXX_STANDARD 98)

add_library(CppRush00
        Entity/AEntity.class.hpp
        Entity/AEntity.class.cpp
        Entity/Bonus/Bonus.class.hpp
        Entity/Bonus/Bonus.class.cpp
        Entity/Bonus/HealthPack.class.hpp
        Entity/Bonus/WeaponUpgrade.class.cpp
        Entity/Bonus/WeaponUpgrade.class.hpp
        Entity/Bonus/HealthPack.class.cpp
        Entity/Missiles/Missile.class.cpp
        Entity/Missiles/Missile.class.hpp
        Entity/Characters/Creatures/Creature.hpp
        Entity/Characters/Creatures/Creature.cpp
        Entity/Characters/Creatures/Boss.hpp
        Entity/Characters/Creatures/Boss.cpp
        Entity/Characters/Creatures/Basic.hpp
        Entity/Characters/Creatures/Basic.cpp
        Entity/Characters/Character.class.cpp
        Entity/Characters/Character.class.hpp
        Entity/Characters/Player.class.hpp
        Entity/Characters/Player.class.cpp
        Map/Map.class.cpp
        Map/Map.class.hpp
        Map/Square.class.cpp
        Map/Square.class.hpp
        mainmatthieu.cpp
        Game.class.cpp
        Game.class.hpp
        Constants.hpp)

