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
    
    bool hasBar();

    bool topLayerCorrect();

    void auf();

    void SecondLayer();

    void topCross();

    void oll();

    void pll();

    void delay();

    void Ua_perm();
    void Ub_perm();
    void H_perm();
    void Z_perm();
    void T_perm();
private:
    std::string name;
};