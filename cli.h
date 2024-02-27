#ifndef CLI_H
#define CLI_H

#include "shape.h"
#include <bits/stdc++.h>

using namespace std;

class MenuOption {
public:
    int number;
    string label;

    MenuOption(int num, string l);
};

class Cli {
public:

    void run();
    Cli();

private:

    map<string, Shape*> shapeMap; 
    vector<MenuOption> MAIN_MENU_OPTIONS;
    map<int, vector<MenuOption>> SUB_MENU_OPTIONS;

    void displayMainMenu();
    void manage2DShapes();
    void manage3DShapes();
    void addShape(int choice,int flag);
    void updateShape();
    void deleteShape();
    void searchShape();
    void displayAllShapes();

   
};


#endif 
