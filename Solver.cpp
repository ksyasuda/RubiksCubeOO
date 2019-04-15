#include <iostream>
#include <string>
#include "Solver.h"

Solver::Solver() :name("cross") {}

Solver::Solver(std::string stage){
    name = stage;
}

void Solver::Crosss() {
    Cross c;
    c.cross();
}