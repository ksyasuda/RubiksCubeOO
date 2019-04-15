#include <iostream>
#include <string>
#include <vector>
#include "RubiksCube.h"
#include "Cross.h"

class Solver : public RubiksCube {
public:
    Solver();

    Solver(std::string stage);

    void Crosss();
private:
    std::string name;
};