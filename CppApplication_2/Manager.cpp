#include "Manager.h"
#include <string>
#include <vector>
#include <memory>
#include "Window.h"
#include <iostream>

using namespace std;

Manager::Manager() {
}

void Manager::show() {
    //Show new window
    if (!this->windows.empty())
        this->windows[this->windows.size() - 1]->display();
}

void Manager::createWindow() {
    unique_ptr<Windows> window(new Windows());
    window->create();
    this->num_windows.push(window->getId());
    this->windows.push_back(move(window));
}

void Manager::createMainWindow() {
    this->createWindow();
    this->setMain(this->windows.size() - 1);
}

void Manager::deleteWindow() {
    if (!this->windows.empty()) {
        this->windows[this->num_windows.top()]->close();
        this->windows.pop_back();
        this->num_windows.pop();
        Windows::counter--;
    }
    else cout << "Error! All windows closed.\n";
}

void Manager::setMain(int number) {
    //Make the window main
    if (number >= 0 && number < windows.size())
        this->windows[number]->focus();
    else cout << "Error! This window has not yet been created.\n";
}

Manager::~Manager() {
}

