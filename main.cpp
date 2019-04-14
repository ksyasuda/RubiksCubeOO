#include <iostream>
#include "RubiksCube.h"


//colored numbers
constexpr auto RED2 = "\033[31m";
constexpr auto GREEN2 = "\033[32m";
constexpr auto YELLOW2 = "\033[33m";
constexpr auto BLUE2 = "\033[34m";
constexpr auto WHITE2 = "\033[37m";
constexpr auto ORANGE2 = "\033[91m";


//only colors
constexpr auto RESET = "\033[0m";
constexpr auto RED = "\033[41m";
constexpr auto GREEN = "\033[42m";
constexpr auto YELLOW = "\033[43m";
constexpr auto BLUE = "\033[44m";
constexpr auto WHITE = "\033[47m";
constexpr auto ORANGE = "\033[101m";
int main()
{
    RubiksCube cube;
    cube.initCube();
    cube.printCube();
    return 0;
}