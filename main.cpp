#include <iostream>
#include "Solver.h"


int main()
{
    //testing
    Solver* solver = new Solver("cross");
    //int choice = cube.menu();
    solver->initCube();
    solver->printCube();
    //solver->printCube();
    //solver->turnCube("U", true);
    solver->scrambleCube(25);
    //solver->printCube();
    do{solver->Crosss();
    } while(solver->getColor(5, 0, 1) != "white" or solver->getColor(5, 1, 0) != "white" or
            solver->getColor(5, 1, 2) != "white" or solver->getColor(5, 2, 1) != "white");
    solver->Corners();
    do{solver->SecondLayer();}while(!solver->secondLayerCorrect());
    return 0;
}