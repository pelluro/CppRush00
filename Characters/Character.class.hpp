
#ifndef CHARACTER_CLASS_H

# define CHARACTER_CLASS_H

# include <string>
# include <iostream>

#include "../AEntity.class.hpp"
#include "../Weapons/Weapon.class.hpp"

class Character:public AEntity
{
    public:

    int     getHP(void);
    void    setHP(int);

    void    equipWeapon(Weapon*);
    Weapon* getWeapon(void);

    virtual void	onEntityHit ( void ) = 0;

    protected:
    //health point
    int _hp;
    Weapon* weapon;


};

#endif