#include <vector>
#include <iostream>
#include <string>
class RubiksCube {
public:
    RubiksCube();

    RubiksCube(const RubiksCube &other);

    void initCube();

    void printCube();

    int menu();

    void initFaces();

    void turnCube(std::string move, bool print);

    void B();
    void Bp();
    void D();
    void Dp();
    void Up();
    void U();
    void Rp();
    void R();
    void Lp();
    void L();
    void Fp();
    void F();
    void M();
    void Mp();
    void M2();

private:
    const bool show_moves = true;
    const bool print_cube = true;
    int cube[6][3][3];
    bool print = false;
};