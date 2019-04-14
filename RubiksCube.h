#include <vector>

class RubiksCube{
public:
    RubiksCube();

    RubiksCube(const RubiksCube &other);

    void initCube();

    void printCube();

    void menu();

private:
    int cube[6][3][3];
};