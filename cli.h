#ifndef CLI_H
#define CLI_H

#include "shape.h"
using namespace std;
class Cli {
public:

    void run();
private:

    map<string, Shape*> shapeMap; 

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
