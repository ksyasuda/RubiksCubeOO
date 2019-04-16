#include <iostream>
#include "RubiksCube.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>

//colored numbers
constexpr auto RED2 = "\033[31m";
constexpr auto GREEN2 = "\033[32m";
constexpr auto YELLOW2 = "\033[33m";
constexpr auto BLUE2 = "\033[34m";
constexpr auto WHITE2 = "\033[37m";
constexpr auto ORANGE2 = "\033[35m";


//only colors
constexpr auto RESET = "\033[0m";
constexpr auto RED = "\033[41m";
constexpr auto GREEN = "\033[42m";
constexpr auto YELLOW = "\033[43m";
constexpr auto BLUE = "\033[44m";
constexpr auto WHITE = "\033[47m";
constexpr auto ORANGE = "\033[45m";

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

void RubiksCube::scrambleCube(int val) {
	std::vector<std::string> vect = { "R", "Rp", "U", "Up", "L", "Lp", "F", "Fp", "D", "Dp", "B", "Bp" };
	srand (time(NULL));
	int random;
	std::string move;
	for(int i = 0; i < val; i++) {
		random = rand() % 12;
		move = vect.at(random);
		//add the if delay here
		turnCube(move, true);
	}
}

int* RubiksCube::at(int x, int y, int z){
	return &cube[x][y][z];
}

bool RubiksCube::secondLayerCorrect(){
	if(getColor(1, 1, 0) != "blue" || getColor(1, 1, 2) != "blue" ||
	   getColor(2, 1, 0) != "red" || getColor(2, 1, 2) != "red" ||
	   getColor(3, 1, 0) != "green" || getColor(3, 1, 2) != "green" ||
	   getColor(4, 1, 0) != "orange" || getColor(4, 1, 2) != "orange")
	   return false;
	return true;
}

std::string RubiksCube::getColor(int x, int y, int z){
	if(cube[x][y][z] >= 0 and cube[x][y][z] <= 8) return "yellow";
	else if(cube[x][y][z] >= 9 and cube[x][y][z] <= 17) return "blue";
	else if(cube[x][y][z] >= 18 and cube[x][y][z] <= 26) return "red";
	else if(cube[x][y][z] >= 27 and cube[x][y][z] <= 35) return "green";
	else if(cube[x][y][z] >= 36 and cube[x][y][z] <= 44) return "orange";
	else if(cube[x][y][z] >= 45 and cube[x][y][z] <= 53) return "white";
	return "this should never happen only here to avoid compile error";
}


std::string RubiksCube::getColor(int * pos){
	if(*pos >= 0 and *pos <= 8) return "yellow";
	else if(*pos >= 9 and *pos <= 17) return "blue";
	else if(*pos >= 18 and *pos <= 26) return "red";
	else if(*pos >= 27 and *pos <= 35) return "green";
	else if(*pos >= 36 and *pos <= 44) return "orange";
	else if(*pos >= 45 and *pos <= 53) return "white";
	return "this should never happen only here to avoid compile error";
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

void RubiksCube::printCube()
{
	const char* colors[7] = { RESET, RED, GREEN, YELLOW, BLUE, WHITE, ORANGE };
	//const char* colors[7] = { RESET, RED2, GREEN2, YELLOW2, BLUE2, WHITE2, ORANGE2 };
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

int RubiksCube::menu()
{
	int choice;
	//add a debug menu
	std::cout << std::endl;
	std::cout << "Rubik's Cube Solver" << std::endl;
	std::cout << "1. Randomly Scramble the Cube" << std::endl;
	std::cout << "2. Solve the cube yourself" << std::endl;
	std::cout << "3. Upload a custom scramble" << std::endl;
	std::cout << "4. Load a custom solution " << std::endl;
	std::cout << "5. Ai cube solve" << std::endl;
	std::cout << "6. Cheeky Ai cube solve" << std::endl;
	std::cout << "7. Quit" << std::endl;
	std::cout << "Enter in a choice: "; std::cin >> choice;
	while (choice != 1 and choice != 2 and choice != 3 and choice != 4 and choice != 5 and choice != 6 and choice != 7) {
		std::cout << "Invalid menu choice, try again" << std::endl;
		std::cout << "Enter in a choice: ";
		std::cin >> choice;
	}
	return choice;
}

void RubiksCube::turnCube(std::string move, bool print) {
	if (move == "R") R();
	else if (move == "Rp") Rp();
	else if (move == "U") U();
	else if (move == "Up") Up();
	else if (move == "L") L();
	else if (move == "Lp") Lp();
	else if (move == "F") F();
	else if (move == "Fp") Fp();
	else if (move == "D") D();
	else if (move == "Dp") Dp();
	else if (move == "B") B();
	else if (move == "Bp") Bp();
	else if (move == "M") M();
	else if (move == "Mp") Mp();
	else if (move == "M2") M2();
	if(show_moves)
		std::cout << "One " << move << " rotation" << std::endl;
	//if(turn_delay)
	//	delay2();
		
	if (print and print_cube)
	{
		printCube();
		std::cout << std::endl;
	}
}

void RubiksCube::M()
{
	int temp[3] = { cube[0][2][1], cube[0][1][1], cube[0][0][1] };
	int temp2[3] = { cube[2][0][1], cube[2][1][1], cube[2][2][1] };
	int temp3[3] = { cube[5][0][1], cube[5][1][1], cube[5][2][1] };
	int temp4[3] = { cube[4][2][1], cube[4][1][1], cube[4][0][1] };
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		cube[4][i][1] = temp[count];
		cube[0][i][1] = temp2[count];
		cube[2][i][1] = temp3[count];
		cube[5][i][1] = temp4[count];
		count++;
	}
}

void RubiksCube::Mp()
{
	M(); M(); M();
}

void RubiksCube::M2()
{
	M(); M();
}



void RubiksCube::B()
{
	int foo[9];
	int c = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			foo[c] = cube[4][j][i];
			c++;
		}
	}
	c = 0;
	for (int a = 0; a < 3; a++)
	{
		for (int k = 0; k < 3; k++)
		{
			cube[4][a][k] = foo[c];
			c++; //lol
		}
	}
	c = 0;
	//rotate edges
	//yellow
	int temp[3] = { cube[0][0][2], cube[0][0][1], cube[0][0][0] };
	//green
	int temp2[3] = { cube[3][0][2], cube[3][1][2], cube[3][2][2] };
	//white
	int temp3[3] = { cube[5][2][2], cube[5][2][1], cube[5][2][0] };
	//blue
	int temp4[3] = { cube[1][0][0], cube[1][1][0], cube[1][2][0] };
	for(int v = 0; v < 3; v++)
	{
		cube[1][v][0] = temp[c];
		cube[0][0][v] = temp2[c];
		cube[3][v][2] = temp3[c];
		cube[5][2][v] = temp4[c];
		c++;
	}
}

void RubiksCube::Bp()
{
	for (int i = 0; i < 3; i++) B();
}

void RubiksCube::D()
{
	int foo[9];
	int c = 0;
	//roate face
	for (int i = 0; i < 3; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			foo[c] = cube[5][j][i];
			c++; //hah
		}
	}
	c = 0;
	for (int a = 0; a < 3; a++)
	{
		for (int k = 0; k < 3; k++)
		{
			cube[5][a][k] = foo[c];
			c++;
		}
	}
	c = 0;
	//rotate edges
	//blue
	int temp[3] = { cube[1][2][0], cube[1][2][1], cube[1][2][2] };
	//red
	int temp2[3] = { cube[2][2][0], cube[2][2][1], cube[2][2][2] };
	//green
	int temp3[3] = { cube[3][2][0], cube[3][2][1], cube[3][2][2] };
	//orange
	int temp4[3] = { cube[4][2][0], cube[4][2][1], cube[4][2][2] };
	for(int v = 0; v < 3; v++)
	{
		cube[2][2][v] = temp[c];
		cube[3][2][v] = temp2[c];
		cube[4][2][v] = temp3[c];
		cube[1][2][v] = temp4[c];
		c++; //hahah
	}
}

void RubiksCube::Dp()
{
	for (int i = 0; i < 3; i++) D();
}

void RubiksCube::Up()
{
	for (int i = 0; i < 3; i++) U();
}

void RubiksCube::U()
{
	int foo[9];
	int c = 0;
	//rotate face
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 2; j >= 0; j--) 
		{
			foo[c] = cube[0][j][i];
			c++; //haha
		} 
	}
	c = 0;
	for (int a = 0; a < 3; a++) 
	{
		for (int k = 0; k < 3; k++)
		{
			cube[0][a][k] = foo[c];
			c++;
		}
	}
	//ROTATE EDGES
	//orange
	int temp[3] = { cube[4][0][0], cube[4][0][1], cube[4][0][2] };
	//green
	int temp2[3] = { cube[3][0][0], cube[3][0][1],cube[3][0][2] };
	//red
	int temp3[3] = { cube[2][0][0], cube[2][0][1], cube[2][0][2] };
	//blue
	int temp4[4] = { cube[1][0][0], cube[1][0][1], cube[1][0][2] };
	c = 0;
	for (int v = 0; v < 3; v++)
	{
		cube[3][0][v] = temp[c];
		cube[2][0][v] = temp2[c];
		cube[1][0][v] = temp3[c];
		cube[4][0][v] = temp4[c];
		c++;
	}
}

void RubiksCube::Rp()
{
	R(); R(); R();
}

void RubiksCube::R()
{
	int foo[9];
	int c = 0;
	//rotate face
	for (int i = 0; i < 3; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			foo[c] = cube[3][j][i];
			c++;
		}
	}
	c = 0;
	for (int a = 0; a < 3; a++) {
		for (int k = 0; k < 3; k++) {
			cube[3][a][k] = foo[c]; c++;
		}
	}
	//ROTATE EDGES
	//red
	int temp[3] = { cube[2][0][2], cube[2][1][2], cube[2][2][2] };
	//white
	int temp2[3] = { cube[5][0][2], cube[5][1][2], cube[5][2][2] };
	//orange
	int temp3[3] = { cube[4][2][0], cube[4][1][0], cube[4][0][0] };
	//yellow
	int temp4[3] = { cube[0][2][2], cube[0][1][2], cube[0][0][2] };
	c = 0;
	for (int v = 0; v < 3; v++) {
		cube[0][v][2] = temp[c];
		cube[2][v][2] = temp2[c];
		cube[5][v][2] = temp3[c];
		cube[4][v][0] = temp4[c];
		c++;
	}
}

void RubiksCube::Lp()
{
	int foo[9];
	int c = 0;
	//rotate face
	for (int i = 2; i >= 0; i--)
	{
		for (int j = 0; j <= 2; j++)
		{
			foo[c] = cube[1][j][i];
			c++;
		}
	}
	c = 0;
	for (int a = 0; a < 3; a++)
	{
		for (int k = 0; k < 3; k++)
		{
			cube[1][a][k] = foo[c];
			c++;
		}
	}
	//ROTATE EDGES
	int temp[3] = { cube[5][0][0], cube[5][1][0], cube[5][2][0] };
	int temp2[3] = { cube[2][0][0], cube[2][1][0], cube[2][2][0] };
	int temp3[3] = { cube[0][2][0], cube[0][1][0], cube[0][0][0] };
	int temp4[3] = { cube[4][2][2], cube[4][1][2], cube[4][0][2] };
	c = 0;
	for (int v = 0; v < 3; v++)
	{
		cube[2][v][0] = temp[c];
		cube[0][v][0] = temp2[c];
		cube[4][v][2] = temp3[c];
		cube[5][v][0] = temp4[c];
		c++;
	}
}

void RubiksCube::L()
{
	int foo[9];
	int c = 0;
	//rotate face only
	for (int i = 0; i < 3; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			foo[c] = cube[1][j][i];
			c++; //haha
		}
	}
	c = 0;
	for (int a = 0; a < 3; a++)
	{
		for (int k = 0; k < 3; k++)
		{
			cube[1][a][k] = foo[c];
			c++;//hehe
		}
	}
	//ROTATE EDGES
	int temp[3] = { cube[5][2][0], cube[5][1][0], cube[5][0][0] };
	int temp2[3] = { cube[4][2][2], cube[4][1][2], cube[4][0][2] };
	int temp3[3] = { cube[0][0][0], cube[0][1][0], cube[0][2][0] };
	int temp4[3] = { cube[2][0][0], cube[2][1][0], cube[2][2][0] };
	c = 0;
	for (int v = 0; v < 3; v++)
	{
		cube[4][v][2] = temp[c];
		cube[0][v][0] = temp2[c];
		cube[2][v][0] = temp3[c];
		cube[5][v][0] = temp4[c];
		c++;
	}
}

void RubiksCube::Fp()
{
	F(); F(); F();
}

void RubiksCube::F()
{
	int foo[9];
	int c = 0;
	//ROTATES RED FACE ONLY
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			foo[c] = cube[2][j][i];
			c++; //hehe
		}
	}
	c = 0;
	for (int a = 0; a < 3; a++)
	{
		for (int k = 0; k < 3; k++)
		{
			cube[2][a][k] = foo[c];
			c++; //hah
		}
	}
	//ROTATE EDGES
	int temp[3] = { cube[0][2][0], cube[0][2][1], cube[0][2][2] };
	int temp2[3] = { cube[3][2][0], cube[3][1][0], cube[3][0][0] };
	int temp3[3] = { cube[1][2][2], cube[1][1][2], cube[1][0][2] };
	int temp4[3] = { cube[5][0][0], cube[5][0][1], cube[5][0][2] };
	c = 0;
	for (int v = 0; v < 3; v++)
	{
		cube[3][v][0] = temp[c];
		cube[5][0][v] = temp2[c];
		cube[0][2][v] = temp3[c];
		cube[1][v][2] = temp4[c];
		c++;
	}
}

