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

    void Corners();

    bool whiteOnTop();

    bool topCorrect();

    bool isSolved();

    void SecondLayer();

    void topCross();

    void oll();

    void pll();
private:
    std::string name;
};