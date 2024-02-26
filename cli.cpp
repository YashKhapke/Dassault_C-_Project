#include "cli.h"
#include <algorithm>
#include <vector>

using namespace std;

// Menu //

void Cli::run() {
    int choice;
    while (true) {
        cout << " #### Geometric Shapes ####- ";
        cout << endl << endl;
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            manage2DShapes();
            break;
        case 2:
            manage3DShapes();
            break;
        case 3:
            cout << "Exiting program...\n";
            return;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}

void Cli::displayMainMenu() {
   
    cout << "Main Menu\n";
    cout << "1. Manage 2D Shapes\n";
    cout << "2. Manage 3D Shapes\n";
    cout << "3. Exit Program\n";
}

void Cli::manage2DShapes() {
    int choice;
    while (true) {
        cout << "\n2D Shapes Menu\n";
        cout << "1. Add Shape\n";
        cout << "2. Update Shape\n";
        cout << "3. Delete Shape\n";
        cout << "4. Search Shape\n";
        cout << "5. Display All Shapes\n";
        cout << "6. Go Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int flag;
            cout << "Select the type of shape:\n";
            cout << "1. Circle\n";
            cout << "2. Rectangle\n";
            cout << "3. Square\n";
       
            int choice;
            cin >> choice;

            addShape(choice,0);
            break;
        case 2:
            updateShape();
            break;
        case 3:
            deleteShape();
            break;
        case 4:
            searchShape();
            break;
        case 5:
           displayAllShapes();
            break;
        case 6:
            return;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}

void Cli::manage3DShapes() {
    int choice;
    while (true) {
        cout << "\n3D Shapes Menu\n";
        cout << "1. Add Shape\n";
        cout << "2. Update Shape\n";
        cout << "3. Delete Shape\n";
        cout << "4. Search Shape\n";
        cout << "5. Display All Shapes\n";
        cout << "6. Go Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int flag ;
            cout << "Select the type of shape:\n";
            cout << "1. Sphere\n";
            cout << "2. Cuboid\n";
            cout << "3. Cube\n";
            int choice;
            cin >> choice;

            addShape(choice,1);
            break;
        case 2:
            updateShape();
            break;
        case 3:
            deleteShape();
            break;
        case 4:
            searchShape();
            break;
        case 5:
           displayAllShapes();
            break;
        case 6:
            return;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}


//// Operations on Shapes ////

void Cli::addShape(int choice,int f) {
    string name;
    cout << "Enter a unique name for the shape: ";
    cin >> name;

    if (f == 0) {
        // 2D Shapes
        switch (choice) {
        case 1: {
            double radius;
            cout << "Enter the radius of the circle: ";
            cin >> radius;

            double x, y, z;
            cout << "Enter the coordinates of the plane (x, y, z): ";
            cin >> x >> y >> z;
            // Circle
            cout << "Circle is in the ";
            if (x != 0 && y != 0) {
                cout << "XY plane" << endl;
            }
            else if (x != 0 && z != 0) {
                cout << "XZ plane" << endl;
            }
            else if (y != 0 && z != 0) {
                cout << "YZ plane" << endl;
            }

            double centerX, centerY;
            cout << "Enter the center coordinates of the circle (x, y): ";
            cin >> centerX >> centerY;
            shapeMap[name] = new Circle(radius, centerX, centerY);
            break;
        }
        case 2: {
            double length, width;
            cout << "Enter the length and width of the rectangle: ";
            cin >> length >> width;

            double x, y, z;
            cout << "Enter the coordinates of the plane (x, y, z): ";
            cin >> x >> y >> z;
            // Rectangle
            cout << "Rectangle is in the ";
            if (x != 0 && y != 0) {
                cout << "XY plane" << endl;
            }
            else if (x != 0 && z != 0) {
                cout << "XZ plane" << endl;
            }
            else if (y != 0 && z != 0) {
                cout << "YZ plane" << endl;
            }


            shapeMap[name] = new Rectangle(length, width);
            break;
        }
        case 3: {
            double side;
            cout << "Enter the side of the square ";
            cin >> side;

            double x, y, z;
            cout << "Enter the coordinates of the plane (x, y, z): ";
            cin >> x >> y >> z;
            // Square
            cout << "Square is in the ";
            if (x!= 0 && y !=0) {
                cout << "XY plane" << endl;
            }
            else if (x != 0 && z != 0) {
                cout << "XZ plane" << endl;
            }
            else if (y != 0 && z != 0) {
                cout << "YZ plane" << endl;
            }

            shapeMap[name] = new Square(side);
            break;



        }
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
    else {
        switch (choice) {
        case 1: {
            double radius;
            cout << "Enter the radius of the sphere: ";
            cin >> radius;
            double centerX, centerY,centerZ;
            cout << "Enter the center coordinates of the sphere (x, y,z): ";
            cin >> centerX >> centerY>>centerZ;
            shapeMap[name] = new Sphere(radius, centerX, centerY,centerZ);
            break;
        }
        case 2: {
            double length, width, height;
            cout << "Enter the length, width, and height of the cuboid: ";
            cin >> length >> width >> height;

            double centerX, centerY, centerZ;
            cout << "Enter the center coordinates of the sphere (x, y,z): ";
            cin >> centerX >> centerY >> centerZ;

            shapeMap[name] = new Cuboid(length, width, height,centerX,centerX,centerZ);
            
            break;
        }
        case 3: {
            double side;
            cout << "Enter the side of the cube: ";
            cin >> side;

            double centerX, centerY, centerZ;
            cout << "Enter the center coordinates of the cube (x, y,z): ";
            cin >> centerX >> centerY >> centerZ;

            shapeMap[name] = new Cube(side, centerX, centerX, centerZ);

            break;



        }
        default:
            cout << "Invalid choice.\n";
            break;
        }

    }
}  //Update  a Particular Shape

void Cli::updateShape() {
    string name;
    cout << "Enter the name of the shape to update: ";
    cin >> name;

    auto it = shapeMap.find(name);
    if (it == shapeMap.end()) {
        cout << "Shape with name " << name << " not found.\n";
        return;
    }

    Shape* shape = it->second;
    if (TwoDShape* twoDShape = dynamic_cast<TwoDShape*>(shape)) {
        cout << "Select the parameter to update:\n";
        cout << "1. Radius (for Circle)\n";
        cout << "2. Length and Width (for Rectangle)\n";
        cout << "3. Side (for Square)\n";
        int choice;
        cin >> choice;


        switch (choice) {
        case 1:
            if (Circle* circle = dynamic_cast<Circle*>(twoDShape)) {
                circle->update();
            }
            break;
        case 2:
            if (Rectangle* rectangle = dynamic_cast<Rectangle*>(twoDShape)) {
                rectangle->update();
            }
        case 3: {
            if (Square * square= dynamic_cast<Square*>(twoDShape)) {
                square->update();
            }
        }
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
    else if (ThreeDShape* threeDShape = dynamic_cast<ThreeDShape*>(shape)) {
        cout << "Select the parameter to update:\n";
        cout << "1. Radius (for Sphere)\n";
        cout << "2. Length, Width, and Height (for Cuboid)\n";
        cout << "3. Side (for Cube)\n";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            if (Sphere* sphere = dynamic_cast<Sphere*>(threeDShape)) {
                sphere->update();
            }
            break;
        case 2:
            if (Cuboid* cuboid = dynamic_cast<Cuboid*>(threeDShape)) {
                cuboid->display();
            }
            break;
        case 3:
            if (Cube* cube = dynamic_cast<Cube*>(threeDShape)) {
                cube->display();
            }
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }

    else {
        cout << "Invalid shape type.\n";
    }

}       //Update a particular Shape  

void Cli::deleteShape() {
    string name;
    cout << "Enter the name of the shape to delete: ";
    cin >> name;
    cin.ignore();
    auto it = shapeMap.find(name);
    if (it != shapeMap.end()) {
        delete it->second;
        shapeMap.erase(it);
        cout << "Shape " << name << " deleted successfully.\n";
    }
    else {
        cout << "Shape with name " << name << " not found.\n";
    }
}         

void Cli::searchShape() {
    string name;
    cout << "Enter the name of the shape to search: ";
    cin >> name;

    auto it = shapeMap.find(name);
    if (it != shapeMap.end()) {
        cout << "Shape found:\n";
        cout << "Name: " << name << endl;

      
            if (Circle* circle = dynamic_cast<Circle*>(it->second)) {
                circle->display();
            }
            else if (Rectangle* rectangle = dynamic_cast<Rectangle*>(it->second)) {
                rectangle->display();
            }
            else if (Square* square = dynamic_cast<Square*>(it->second)) {
                square->display();
            }
            else if (Sphere* sphere = dynamic_cast<Sphere*>(it->second)) {
                sphere->display();
            }
            else if (Cuboid* cuboid = dynamic_cast<Cuboid*>(it->second)) {
                cuboid->display();
            }
            else if (Cube* cube = dynamic_cast<Cube*>(it->second)) {
                cube->display();
            }
    
            else {
                cout << "Error: Invalid shape type.\n";
            }
        }
        else {
            cout << "Shape with name " << name << " not found.\n";
        }

    }

void Cli::displayAllShapes() {
    
    map<double, pair<string, string>> shapesByArea;
    map<double, pair<string, string>> shapesByVolume;

    for ( auto pair : shapeMap) {
        if (Circle* circle = dynamic_cast<Circle*>(pair.second)) {
            double area = circle->area();
            shapesByArea[area] = { pair.first, "Circle" };
        }
        else if (Rectangle* rectangle = dynamic_cast<Rectangle*>(pair.second)) {
            double area = rectangle->area();
            shapesByArea[area] = { pair.first, "Rectangle" };
        }
        else if (Square * square = dynamic_cast<Square*>(pair.second)) {
            double area = square->area();
            shapesByArea[area] = { pair.first, "Square" };
        }
        else if (Sphere* sphere = dynamic_cast<Sphere*>(pair.second)) {
            double volume = sphere->volume();
            shapesByVolume[volume] = { pair.first, "Sphere" };
        }
        else if (Cuboid* cuboid = dynamic_cast<Cuboid*>(pair.second)) {
            double volume = cuboid->volume();
            shapesByVolume[volume] = { pair.first, "Cuboid" };
        }
        else if (Cube* cube = dynamic_cast<Cube*>(pair.second)) {
            double volume = cube->volume();
            shapesByArea[volume] = { pair.first, "Cube" };
        }
    }

    cout << endl;
    cout << "#### Shapes sorted by area: ####\n";
    for (auto pair : shapesByArea) {
        cout << "Name: " << pair.second.first << endl;
        cout << "Type: " << pair.second.second << endl;
        cout << "Area: " << pair.first << endl;
    
    }

    cout << endl;
    cout << "##### Shapes sorted by volume: #####\n";
    for (auto pair : shapesByVolume) {
        cout << "Name: " << pair.second.first << endl;
        cout << "Type: " << pair.second.second << endl;
        cout << "Volume: " << pair.first << endl;
      
    }
}







