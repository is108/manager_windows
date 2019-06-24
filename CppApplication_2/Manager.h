#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <stack>
#include <memory>
#include "Window.h"

using namespace std;

class Manager {
public:
    Manager();
    void createWindow();
    void createMainWindow();
    void deleteWindow();
    void setMain(int);
    void show();
    virtual ~Manager();
private:
    vector<unique_ptr<Windows> > windows; 
    stack<int> num_windows;
};

#endif /* MANAGER_H */

