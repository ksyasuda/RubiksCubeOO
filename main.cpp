#include <iostream>
#include "Solver.h"


int main()
{
    Solver* solver = new Solver("cross");
    //int choice = cube.menu();
    solver->initCube();
    solver->printCube();
    solver->turnCube("U", true);
    solver->Crosss();
    //if(choice == 7) std::cout << "BIE" << std::endl;
    return 0;
}