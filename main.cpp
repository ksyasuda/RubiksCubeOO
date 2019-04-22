#include <iostream>
#include "Solver.h"
#include <cstring>

//for debugging only put inside solver debug later
void delay();

int menu();

void pickDelays(Solver* solver);


int main(int argc, char**argv)
{
    Solver* solver = new Solver("cross");
    solver->initCube();
    if(argc != 2){
        std::cout << "Wrong number of args" << std::endl;
        return -1;
    }
    else if(argc == 1 || argc == 2)
    {
        if(!strcmp(argv[2], "--debug") == 0){
            std::cout << "--debug or no --debug.. one other the other" << std::endl;
            return -1;
        }
    }
    if(strcmp(argv[2], "--debug") == 0){
        pickDelays(solver);
    }
    //testing
    //int choice = cube.menu();
    for(int i = 0; i < 5; i++){
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
    solver->oll();
    solver->pll();
    if(!solver->isSolved())
        solver->auf();
    delay();
    }
    return 0;
}

//need to add error trapping in both menus
//for some reason really doesn't like using solver outside of main
//move this back into main
void pickDelays(Solver* solver)
{
    int choice = 0;
    std::cout << "Delay chooser" << std::endl;
    std::cout << "1. CFOP Delay ON" << std::endl;
    std::cout << "2. Turn Delay ON" << std::endl;
    std::cout << "3. CFOP Delay OFF" << std::endl;
    std::cout << "4. Turn Delay OFF" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter in your choice:";
    std::cin >> choice;
    if(choice ==1)
        solver->setDelay("cfop", true);
    if(choice == 2)
        solver->setDelay("turn", true);
    else if(choice == 3)
        solver->setDelay("cfop", false);
    else if(choice == 4)
        solver->setDelay("turn", false);
    else if(choice == 5)
        return;
    return;
}

int menu()
{
    int choice;
    std::cout << "MENU" << std::endl;
    std::cout << "1. Regular solve" << std::endl;
    std::cout << "2. Debug solve" << std::endl;
    std::cout << "3. Choose delays" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter in your choice:";
    std::cin >> choice;
    return choice;
}

void delay()
{
    for(int i = 0; i < 10000; i++)
        for(int j = 0; j < 100000; j++);
}