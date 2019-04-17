#include <iostream>
#include "Solver.h"

//for debugging only put inside solver debug later
void delay();


int main()
{
    //testing
    Solver* solver = new Solver("cross");
    //int choice = cube.menu();
    //for(int i = 0; i < 10; i++){
    solver->initCube();
    solver->printCube();
    //solver->printCube();
    //solver->turnCube("U", true);
    solver->scrambleCube(25);
    //solver->printCube();
    solver->Crosss();
    solver->Corners();
    solver->SecondLayer();
    //delay();
    //}
    solver->topCross();
    return 0;
}

void delay()
{
    for(int i = 0; i < 10000; i++)
        for(int j = 0; j < 100000; j++);
}