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

RubiksCube::RubiksCube(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                cube[i][j][k] = 0;
            }
        }
    }
}

RubiksCube::RubiksCube(const RubiksCube &other){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                cube[i][j][k] = other.cube[i][j][k];
            }
        }
    }
}

void RubiksCube::initCube(){
    int count = 0;
     for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                cube[i][j][k] = count;
                count++;
            }
        }
    }
}

void RubiksCube::printCube(){
	const char* colors[7] = { RESET, RED, GREEN, YELLOW, BLUE, WHITE, ORANGE };
	const char* colors2[7] = { RESET, RED2, GREEN2, YELLOW2, BLUE2, WHITE2, ORANGE2 };
	int color = 0;
	//YELLOW FACE
	for (int i = 0; i <= 2; i++)
	{
		std::cout << "         ";
		for (int e = 0; e <= 2; e++)
		{
			//asigns each number to its respective color
			if (cube[0][i][e] >= 0 && cube[0][i][e] <= 8) color = 3;
			else if (cube[0][i][e] >= 9 && cube[0][i][e] <= 17) color = 4;
			else if (cube[0][i][e] >= 18 && cube[0][i][e] <= 26) color = 1;
			else if (cube[0][i][e] >= 27 && cube[0][i][e] <= 35) color = 2;
			else if (cube[0][i][e] >= 36 && cube[0][i][e] <= 44) color = 6;
			else if (cube[0][i][e] >= 45 && cube[0][i][e] <= 53) color = 5;
			if (cube[0][i][e] < 9) std::cout << colors[3] << colors2[3] << "0";
			if (cube[0][i][e] == 9) std::cout << colors[4] << colors2[4] << "0";
			std::cout << colors[color] << colors2[color] << cube[0][i][e] << " " << RESET;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int j = 0; j <= 2; j++)
	{
		for (int q = 1; q <= 4; q++)
		{
			/*
			if (q == 1) color = 4;
			else if (q == 2) color = 1;
			else if (q == 3) color = 2;
			else if (q == 4) color = 7;
			*/
			for (int p = 0; p < 3; p++)
			{
				if (cube[q][j][p] >= 0 && cube[q][j][p] <= 8) color = 3;
				else if (cube[q][j][p] >= 9 && cube[q][j][p] <= 17) color = 4;
				else if (cube[q][j][p] >= 18 && cube[q][j][p] <= 26) color = 1;
				else if (cube[q][j][p] >= 27 && cube[q][j][p] <= 35) color = 2;
				else if (cube[q][j][p] >= 36 && cube[q][j][p] <= 44) color = 6;
				else if (cube[q][j][p] >= 45 && cube[q][j][p] <= 53) color = 5;
				if (cube[q][j][p] < 10) std::cout << colors[color] << colors2[color] << "0";
				std::cout << colors[color] << colors2[color] << cube[q][j][p] << " " << RESET;

			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int k = 0; k <= 2; k++)
	{
		std::cout << "         ";
		for (int a = 0; a <= 2; a++)
		{
			if (cube[5][k][a] >= 0 && cube[5][k][a] <= 8) color = 3;
			else if (cube[5][k][a] >= 9 && cube[5][k][a] <= 17) color = 4;
			else if (cube[5][k][a] >= 18 && cube[5][k][a] <= 26) color = 1;
			else if (cube[5][k][a] >= 27 &&cube[5][k][a] <= 35) color = 2;
			else if (cube[5][k][a] >= 36 &&cube[5][k][a] <= 44) color = 6;
			else if (cube[5][k][a] >= 45 && cube[5][k][a] <= 53) color = 5;
			if (cube[5][k][a] < 10) std::cout << colors[color] << colors2[color] << "0";
			std::cout << colors[color] << colors2[color] << cube[5][k][a] << " " << RESET;
		}
		std::cout << std::endl;
	}
}

void RubiksCube::menu(){
	return;
}