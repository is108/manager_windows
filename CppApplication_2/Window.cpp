#include "Window.h"
#include <string>
#include <SFML/Window.hpp>
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;
using namespace sf;

//Generate name for the window
string generateName(int id) {
    stringstream ss;
    ss << ++id;
    string number = ss.str();
    return "Window" + number;
}

Windows::Windows(int length, int width, string headline) {
    counter++;
    this->id = counter - 1;
    this->length = length;
    this->width = width;
    this->headline = headline;
}

Windows::Windows(int length, int width) {
    counter++;
    this->id = counter - 1;
    this->length = length;
    this->width = width;
    this->headline = generateName(this->id);
}

Windows::Windows() {
    counter++;
    this->id = counter - 1;
    this->length = 200 + rand() % 1400;
    this->width = 200 + rand() % 1400;
    this->headline = generateName(this->id);
}

Windows::~Windows() {
}

void Windows::setLength(int length) {
    this->length = length;
}
 
void Windows::setWidth(int width) {
    this->width = width;
}

void Windows::setHeadline(string headline) {
    this->headline = headline;
}

void Windows::create() {
    this->window.create(VideoMode(this->length, this->width), this->headline);
}

void Windows::display() {
    this->window.display();
}

void Windows::focus() {
    this->window.requestFocus();
}

void Windows::close() {
    this->window.close();
}

int Windows::getLength() {
    return this->length;
}

int Windows::getWidth() {
    return this->width;
}
    
string Windows::getHeadline() {
    return this->headline;
}

int Windows::getId() {
    return this->id;
}



