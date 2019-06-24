#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <unistd.h>
#include "Manager.h"

using namespace sf;
using namespace std;

Menu::Menu(sf::RenderWindow& app) {
    this->run(app);
}    

int Menu::run(sf::RenderWindow& app) {
    //Create elements menu
    sf::Text Button1;
    sf::Text Button2;
    sf::Text Button3;
    sf::Text Button4;
    sf::Font Font;

    if (!Font.loadFromFile("verdanab.ttf")) {
	std::cerr << "Error loading verdanab.ttf" << std::endl;
    }
	    
    int buttonNum = 0;
        
    Button1.setFont(Font);
    Button1.setCharacterSize(20);
    Button1.setString("Create window");
    Button1.setPosition({ 280.f, 160.f });

    Button2.setFont(Font);
    Button2.setCharacterSize(20);
    Button2.setString("Create main window");
    Button2.setPosition({ 280.f, 220.f });
        
    Button3.setFont(Font);
    Button3.setCharacterSize(20);
    Button3.setString("Close window");
    Button3.setPosition({ 280.f, 160.f });
    
    Button4.setFont(Font);
    Button4.setCharacterSize(20);
    Button4.setString("Exit");
    Button4.setPosition({ 280.f, 220.f });

    Button1.setPosition(100, 30);
    Button2.setPosition(100, 90);
    Button3.setPosition(100, 150);
    Button4.setPosition(100, 210);
 
    while (app.isOpen()) {
        //Set Color
	Button1.setColor(Color::White);
	Button2.setColor(Color::White);
	Button3.setColor(Color::White);
        Button4.setColor(Color::White);
	buttonNum = 0;
	app.clear(Color(129, 181, 200));
            
        sf::Event event;
        while (app.pollEvent(event)) {
        // Request for closing the window
            if (event.type == sf::Event::Closed)
                app.close();
        }
        
    
        //Change the color of the buttons when you hover
	if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(app))) { Button1.setColor(Color::Blue); buttonNum = 1; }
	if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(app))) { Button2.setColor(Color::Blue); buttonNum = 2; }
	if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(app))) { Button3.setColor(Color::Blue); buttonNum = 3; }
        if (IntRect(100, 210, 300, 50).contains(Mouse::getPosition(app))) { Button4.setColor(Color::Blue); buttonNum = 4; }

        //Perform action when pressed
	if (Mouse::isButtonPressed(Mouse::Left)) {
            if (buttonNum == 1) this->manager.createWindow();
            if (buttonNum == 2) this->manager.createMainWindow();  
            if (buttonNum == 3) this->manager.deleteWindow();
            if (buttonNum == 4) app.close();
	}
            
        //Display menu
	app.draw(Button1);
	app.draw(Button2);
	app.draw(Button3);
        app.draw(Button4);
		
        app.display();
        usleep(140000);
    }
}

Menu::~Menu() {
}

