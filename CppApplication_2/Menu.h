#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Manager.h"


class Menu {
public:
    Menu(sf::RenderWindow &);
    virtual ~Menu();
private:
    int run(sf::RenderWindow &);
    Manager manager;
};

#endif /* MENU_H */

