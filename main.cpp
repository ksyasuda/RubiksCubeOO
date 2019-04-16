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
    solver->Crosss();
    solver->Corners();
    solver->SecondLayer();
    solver->topCross();
    return 0;
}