#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;
using namespace std;

class Windows {
public:
    Windows(int, int, string);
    Windows(int, int);
    Windows();
    void setLength(int);
    void setWidth(int);
    void setHeadline(string);
    int getLength();
    int getWidth();
    int getId();
    string getHeadline();
    void create();
    void display();
    void focus();
    void close();
    virtual ~Windows();
    static int counter; //Amount windows
private:
    int id;
    RenderWindow window;
    int length;
    int width;
    string headline;
};


#endif /* WINDOW_H */

