#include <cstdlib>
#include "Window.h"
#include "Menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Manager.h"
#include <ctime>

using namespace sf;
    
int Windows::counter = 0;

int main(int argc, char** argv) {
    srand(time(NULL));
    sf::RenderWindow App(sf::VideoMode(2000, 1000), "Menu");
    Menu test(App);
    
    return 0;
}

