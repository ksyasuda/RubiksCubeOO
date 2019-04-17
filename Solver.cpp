#include <iostream>
#include <string>
#include "Solver.h"

Solver::Solver() :name("cross") {}

Solver::Solver(std::string stage){
    name = stage;
}

void Solver::topCross()
{
	//top dot shape
	if (getColor(0,0,1) != "yellow" && getColor(0,1,0) != "yellow" && getColor(0,1,2) != "yellow" && getColor(0,2,1) != "yellow")
	{
		turnCube("F", true); turnCube("R", true); turnCube("U", true); turnCube("Rp", true); turnCube("Up", true); turnCube("Fp", true);
	}
	//top l shape
	if (getColor(0,1,0) == "yellow" && getColor(0,1,1) == "yellow" && getColor(0,2,1) == "yellow" &&
		getColor(0,0,1) != "yellow" && getColor(0,1,2) != "yellow") turnCube("U", true);
	else if(getColor(0,1,1) == "yellow" && getColor(0,1,2) == "yellow" && getColor(0,2,1) == "yellow" && 
		getColor(0,0,1) != "yellow" && getColor(0,1,0) != "yellow") {
		turnCube("U", true); turnCube("U", true);
	}
	else if(getColor(0,0,1) == "yellow" && getColor(0,1,1) == "yellow" && getColor(0,1,2) == "yellow" &&
		getColor(0,1,0) != "yellow" && getColor(0,2,1) != "yellow") {
		turnCube("Up", true);
	}
	if (getColor(0,1,0) == "yellow" && getColor(0,1,1) == "yellow" && getColor(0,0,1) == "yellow" &&
	getColor(0,2,1) != "yellow" && getColor(0,1,2) != "yellow")
	{
		turnCube("F", true); turnCube("R", true); turnCube("U", true); turnCube("Rp", true); turnCube("Up", true); turnCube("Fp", true);
	}
	//top bar
	if (getColor(0, 0, 1) == "yellow" && getColor(0,1,1) == "yellow" && getColor(0,2,1) == "yellow" &&
		getColor(0, 1, 0) != "yellow" && getColor(0,1,2) != "yellow")
	{
		turnCube("U", true); turnCube("F", true); turnCube("R", true); turnCube("U", true); turnCube("Rp", true); turnCube("Up", true); turnCube("Fp", true);
		//f u r u rp up fp
	}
	else if (getColor(0, 1, 0) == "yellow" && getColor(0, 1, 1) == "yellow" && getColor(0, 1, 2) == "yellow" &&
		getColor(0, 0, 1) != "yellow" && getColor(0, 2, 1) != "yellow")
	{
		turnCube("F", true); turnCube("R", true); turnCube("U", true); turnCube("Rp", true); turnCube("Up", true); turnCube("Fp", true);
		//f r u rp up fp
	}
}

void Solver::Crosss() {
	//2 1 2 4 1 0
	//change all but yellow face to move white piece to to layer
	//move white to top then use the yellow checker to move cross pieces
	bool t = true;

	do
	{
		//red face
		if (getColor( 2, 0, 1) == "white")
		{
			if (getColor( 0, 2, 1) == "red") { turnCube("Up", true); turnCube("Rp", true); turnCube("F", true); turnCube("R", true); }
			else if (getColor( 0, 2, 1) == "blue") { turnCube("Fp", true); turnCube("L", true); turnCube("F", true); }
			else if (getColor( 0, 2, 1) == "orange") { turnCube("U", true); turnCube("Lp", true); turnCube("B", true); turnCube("L", true); }
			else if (getColor( 0, 2, 1) == "green") { turnCube("F", true); turnCube("Rp", true); turnCube("Fp", true); }
		}
		else if (getColor( 2, 1, 0) == "white"){ turnCube("Lp", true); turnCube("Up", true); turnCube("L", true);}
		else if (getColor( 2, 1, 2) == "white") { turnCube("R", true); turnCube("U", true); turnCube("Rp", true); }
		else if (getColor( 2, 2, 1) == "white") { turnCube("Fp", true); turnCube("R", true); turnCube("U", true); turnCube("Rp", true); }

		//green face
		if (getColor( 3, 0, 1) == "white") { turnCube("U", true); turnCube("F", true); turnCube("R", true); turnCube("U", true); turnCube("Rp", true); turnCube("Up", true); turnCube("Fp", true);}
		else if (getColor( 3, 1, 0) == "white") { turnCube("Fp", true); turnCube("Up", true); turnCube("F", true); }
		else if (getColor( 3, 1, 2) == "white") { turnCube("B", true); turnCube("U", true); turnCube("Bp", true); }
		else if (getColor( 3, 2, 1) == "white") { turnCube("R", true); turnCube("Fp", true); turnCube("Up", true); turnCube("F", true); turnCube("U", true); }
		
		//orange face
		if (getColor( 4, 0, 1) == "white") { turnCube("B", true); turnCube("L", true); turnCube("Up", true); turnCube("Lp", true); turnCube("Bp", true); }
		else if (getColor( 4, 1, 0) == "white") { turnCube("Rp", true); turnCube("U", true); turnCube("R", true); }
		else if (getColor( 4, 1, 2) == "white") { turnCube("L", true); turnCube("Up", true); turnCube("Lp", true); }
		else if (getColor( 4, 2, 1) == "white") { turnCube("B", true); turnCube("Rp", true); turnCube("U", true); turnCube("R", true); }

		//blue face
		if (getColor( 1, 0, 1) == "white") { turnCube("L", true); turnCube("F", t); turnCube("Up", t); turnCube("Fp", t); turnCube("Lp", t); }
		else if (getColor( 1, 1, 0) == "white") { turnCube("L", t); turnCube("Up", t); turnCube("Lp", t); }
		else if (getColor( 1, 1, 2) == "white") { turnCube("F", t); turnCube("Up", t); turnCube("Fp", t); turnCube("U", true); }
		else if (getColor( 1, 2, 1) == "white") { turnCube("Lp", t); turnCube("F", t); turnCube("U", t); turnCube("Fp", t); turnCube("Up", true); }

		//yellow face
		if(getColor( 0, 0, 1) == "white")
		{
			if (getColor( 4, 0, 1) == "orange") { turnCube("B", true); turnCube("B", true);}
			else if (getColor( 4, 0, 1) == "blue") { turnCube("Up", true); turnCube("L", true); turnCube("L", true); }
			else if (getColor( 4, 0, 1) == "red") { turnCube("U", true); turnCube("U", true); turnCube("F", true); turnCube("F", true); }
			else if (getColor( 4, 0, 1) == "green") { turnCube("U", true); turnCube("R", true); turnCube("R", true); }
		}
		if (getColor( 0, 1, 0) == "white")
		{
			if (getColor( 1, 0, 1) == "blue") { turnCube("L", true); turnCube("L", true);}
			else if (getColor( 1, 0, 1) == "red") { turnCube("Up", true); turnCube("F", true); turnCube("F", true); }
			else if (getColor( 1, 0, 1) == "green") { turnCube("U", true); turnCube("U", true); turnCube("R", true); turnCube("R", true); }
			else if (getColor( 1, 0, 1) == "orange") { turnCube("U", true); turnCube("B", true); turnCube("B", true); }
		}
		if (getColor( 0, 1, 2) == "white")
		{
			if (getColor( 3, 0, 1) == "red") { turnCube("U", true); turnCube("F", true); turnCube("F", true); }
			else if (getColor( 3, 0, 1) == "green") { turnCube("R", true); turnCube("R", true); }
			else if (getColor( 3, 0, 1) == "orange") { turnCube("Up", true); turnCube("B", true); turnCube("B", true); }
			else if (getColor( 3, 0, 1) == "blue") { turnCube("U", true); turnCube("U", true); turnCube("L", true); turnCube("L", true); }
		}
		if (getColor( 0, 2, 1) == "white")
		{
			if (getColor( 2, 0, 1) == "red") { turnCube("F", true); turnCube("F", true);}
			else if (getColor( 2, 0, 1) == "green") { turnCube("Up", true); turnCube("R", true); turnCube("R", true); }
			else if (getColor( 2, 0, 1) == "orange") { turnCube("U", true); turnCube("U", true); turnCube("B", true); turnCube("B", true); }
			else if (getColor( 2, 0, 1) == "blue") { turnCube("U", true); turnCube("L", true); turnCube("L", true); }
		}
		//white face
		if (getColor( 5, 0, 1) == "white" && getColor( 2, 2, 1) != "red") { turnCube("F", t); turnCube("F", t); }
		else if (getColor( 5, 1, 0) == "white" && getColor( 1, 2, 1) != "blue") { turnCube("L", t); turnCube("L", t); }
		else if (getColor( 5, 1, 2) == "white" && getColor( 3, 2, 1) != "green") { turnCube("R", t); turnCube("R", t); }
		else if (getColor( 5, 2, 1) == "white" && getColor( 4, 2, 1) != "orange") { turnCube("B", t); turnCube("B", t); }
	} while(getColor(5, 0, 1) != "white" || getColor(5, 1, 0) != "white" ||
            getColor(5, 1, 2) != "white" || getColor(5, 2, 1) != "white");
}

bool Solver::whiteOnTop() {
    if(getColor(0,0,1) != "white" || getColor(0,1,0) != "white" ||
       getColor(0,1,2) != "white" || getColor(0,2,1) != "white")
       return false;
    return true;
}

void Solver::SecondLayer() 
{
	do
	{
		bool g = true;
		int* ptr = at(0,0,1);// top
		int* ptr2 = at(0,1,0);; //left
		int* ptr3 = at(0,1,2);
		int* ptr4 = at(0,2,1); //right and bottom

		int* red = at(2,0,1); int* blue = at(1,0,1); int* orange = at(4,0,1); int* green = at(3,0,1);
		if(getColor(0, 2, 1) == "green" and getColor(2, 0, 1) == "red") { turnCube("U", g); turnCube("R", g); turnCube("Up", g); turnCube("Rp", g); turnCube("Up", g); 
		turnCube("Fp", g); turnCube("U", g); turnCube("F", g);}
		if(getColor(0, 2, 1) == "blue" and getColor(2,0,1) == "red") { turnCube("Up", g); turnCube("Lp", g); turnCube("U", g); turnCube("L", g); turnCube("U", g); turnCube("F", g); turnCube("Up", g); turnCube("Fp", g);}
		if (getColor(0, 1, 0) == "red" and getColor(1, 0, 1) == "blue") {
			turnCube("U", g); turnCube("F", g); turnCube("Up", g); turnCube("Fp", g); turnCube("Up", g); turnCube("Lp", g); turnCube("U", g); turnCube("L", g);
		}
		if (getColor(0, 1, 2) == "red" and getColor(3, 0, 1) == "green") {
			turnCube("Up", g); turnCube("Fp", g); turnCube("U", g); turnCube("F", g); turnCube("U", g); turnCube("R", g); turnCube("Up", g); turnCube("Rp", g);
		}
		if(getColor(0, 1, 0) == "orange" and getColor(1, 0, 1) == "blue") {
			turnCube("Up", g); turnCube("Bp", g); turnCube("U", g); turnCube("B", g); turnCube("U", g);
			turnCube("L", g); turnCube("Up", g); turnCube("Lp", g);
		}
		if(getColor(0,1,2) == "orange" and getColor(3,0,1) == "green") {
			turnCube("U", g); turnCube("B", g); turnCube("Up", g); turnCube("Bp", g); turnCube("Up", g);
			turnCube("Rp", g); turnCube("U", g); turnCube("R", g);
		}
		if(getColor(0, 0, 1) == "blue" and getColor(4, 0, 1) == "orange") {
			turnCube("U", g); turnCube("L", g); turnCube("Up", g); turnCube("Lp", g); turnCube("Up", g);
			turnCube("Bp", g); turnCube("U", g); turnCube("B", g);
		}
		if(getColor(0,0,1) == "green" and getColor(4,0,1) == "orange") {
			turnCube("Up", g); turnCube("Rp", g); turnCube("U", g); turnCube("R", g); turnCube("U", g);
			turnCube("B", g); turnCube("Up", g); turnCube("Bp", g);
		}
		turnCube("U", true);
		int count = 0;
		if (getColor(ptr) == "yellow") count++;
		if (getColor(ptr2) == "yellow") count++;
		if (getColor(ptr3) == "yellow") count++;
		if (getColor(ptr4) == "yellow") count++;
		if (getColor(red) == "yellow") count++;
		if (getColor(blue) == "yellow") count++;
		if (getColor(orange) == "yellow") count++;
		if (getColor(green) == "yellow") count++;
		//this is the problem rn  goes into infinite loop //fixed
		if (count >= 4 and !secondLayerCorrect()){
			if (getColor(2,1,2) != "red" || getColor(3,1,0) != "green") {
				turnCube("U", g); turnCube("R", g); turnCube("Up", g); turnCube("Rp", g); turnCube("Up", g);
				turnCube("Fp", g); turnCube("U", g); turnCube("F", g);
			}
			else if (getColor(1,1,2) != "blue" || getColor(2,1,0) != "red") {
				turnCube("Up", g); turnCube("Lp", g); turnCube("U", g); turnCube("L", g); turnCube("U", g); turnCube("F", g); turnCube("Up", g); turnCube("Fp", g);
			}
			else if (getColor(3,1,2) != "green" || getColor(4,1,0) != "orange") {
				turnCube("U", g); turnCube("B", g); turnCube("Up", g); turnCube("Bp", g); turnCube("Up", g);
				turnCube("Rp", g); turnCube("U", g); turnCube("R", g);
			}
			else {
				turnCube("Up", g); turnCube("Bp", g); turnCube("U", g); turnCube("B", g); turnCube("U", g);
				turnCube("L", g); turnCube("Up", g); turnCube("Lp", g);
			}
		}
		count = 0;
		/*
		if(getColor(2, 1, 2) != "red" and getColor(3, 1, 0) != "green") {
			turnCube("U", g); turnCube("Rp", g); turnCube("Up", g); turnCube("Rp", g); turnCube("Up", g);
			turnCube("Fp", g); turnCube("U", g); turnCube("F", g);
		}
		else if(getColor(2, 1, 0) != "red" and getColor(1, 1, 2) != "blue") { turnCube("Up", g); turnCube("Lp", g); turnCube("U", g); turnCube("L", g); turnCube("U", g); turnCube("F", g); turnCube("Up", g); turnCube("Fp", g); }
		else if(getColor(3, 1, 2) != )
		*/
	} while(!secondLayerCorrect());
}

//solver
void Solver::Corners()
{
    bool g = true;

	//check if white is in bottom layer if it is being to top


	do {

		//white red green corner piece
		if (getColor(2, 0, 2) == "green" && getColor(0, 2, 2) == "white" && getColor(3, 0, 0) == "red") { turnCube("R", g); turnCube("U", g); turnCube("U", g); turnCube("Rp", g); turnCube("Up", g); }
		if (getColor(2, 0, 2) == "white" && getColor(0, 2, 2) == "red" && getColor(3, 0, 0) == "green") { turnCube("U", true); turnCube("R", g); turnCube("Up", g); turnCube("Rp", g); }
		if (getColor(2, 0, 2) == "red" && getColor(0, 2, 2) == "green" && getColor(3, 0, 0) == "white") { turnCube("R", g); turnCube("U", g); turnCube("Rp", g); }

		//white red blue corner
		if (getColor(0, 2, 0) == "white" && getColor(1, 0, 2) == "red" && getColor(2, 0, 0) == "blue") { turnCube("F", g); turnCube("Up", g); turnCube("Fp", g); turnCube("U", g); turnCube("U", g); }
		if (getColor(0, 2, 0) == "red" && getColor(1, 0, 2) == "blue" && getColor(2, 0, 0) == "white") { turnCube("F", g); turnCube("U", g); turnCube("Fp", g); }
		if (getColor(0, 2, 0) == "blue" && getColor(1, 0, 2) == "white" && getColor(2, 0, 0) == "red") { turnCube("Lp", g); turnCube("Up", g); turnCube("L", g); }

		//white blue orange corner
		if (getColor(0, 0, 0) == "white" && getColor(1, 0, 0) == "orange" && getColor(4, 0, 2) == "blue") { turnCube("L", g); turnCube("U", g); turnCube("U", g); turnCube("Lp", g); turnCube("Up", g); }
		if (getColor(0, 0, 0) == "blue" && getColor(1, 0, 0) == "white" && getColor(4, 0, 2) == "orange") { turnCube("L", g); turnCube("U", g); turnCube("Lp", g); }
		if (getColor(0, 0, 0) == "orange" && getColor(1, 0, 0) == "blue" && getColor(4, 0, 2) == "white") { turnCube("U", g); turnCube("L", g); turnCube("Up", g); turnCube("Lp", g); }

		//white green orange corner 0 3 4
		if (getColor(0, 0, 2) == "white" && getColor(3, 0, 2) == "orange" && getColor(4, 0, 0) == "green") { turnCube("Rp", g); turnCube("U", g); turnCube("U", g); turnCube("R", g); turnCube("U", g); }
		if (getColor(0, 0, 2) == "green" && getColor(3, 0, 2) == "white" && getColor(4, 0, 0) == "orange") { turnCube("U", g); turnCube("B", g); turnCube("Up", g); turnCube("Bp", g); } //check
		if (getColor(0, 0, 2) == "orange" && getColor(3, 0, 2) == "green" && getColor(4, 0, 0) == "white") { turnCube("Up", g); turnCube("Rp", g); turnCube("U", g); turnCube("R", g); }
		//if there is a white piece in botom layer but is not oriented correctly, bring back into top layer to be inserted
		if (!whiteOnTop())
		{
			if (getColor(5, 0, 0) == "white" || getColor(5, 0, 2) == "white" || getColor(5, 2, 0) == "white" || getColor(5, 2, 2) == "white" ||
				getColor(1,2,0) == "white" || getColor(1, 2, 2) == "white" || getColor(2,2,0) == "white" || getColor(2,2,2) == "white" ||
				getColor(3,2,0) == "white" || getColor(3,2,2) == "white" || getColor(4,2,0) == "white" || getColor(4,2,2) == "white") {
				if ((getColor(2, 2, 2) == "white" || getColor(3, 2, 0) == "white" || getColor(5, 0, 2) == "white") && (getColor(2, 2, 2) != "red" || getColor(3, 2, 0) != "green" || getColor(5,0,2) != "white")) {
					turnCube("R", g); turnCube("Up", g); turnCube("Rp", g);
				}
				else if ((getColor(2, 2, 0) == "white" || getColor(1, 2, 2) == "white" || getColor(5, 0, 0) == "white") && (getColor(2, 2, 0) != "red" || getColor(1, 2, 2) != "blue" || getColor(5,0,0) != "white")) {
					turnCube("Lp", g); turnCube("Up", g); turnCube("L", g);
				}
				else if ((getColor(1, 2, 0) == "white" || getColor(4, 2, 2) == "white" || getColor(5, 2, 0) == "white") && (getColor(1, 2, 0) != "blue" || getColor(4, 2, 2) != "orange" || getColor(5,0,2) != "white")) {
					turnCube("L", g); turnCube("Up", g); turnCube("Lp", g);
				}
				else if ((getColor(3, 2, 2) == "white" || getColor(4, 2, 0) == "white" || getColor(5, 2, 2) == "white") && (getColor(3, 2, 2) != "green" || getColor(4, 2, 0) != "orange" || getColor(5,2,2) != "white")) {
					turnCube("Rp", g); turnCube("U", g); turnCube("R", g);
				}
			}
		}
		turnCube("Up", true);
	} while (!(getColor(5, 0, 0) == "white" && getColor(5, 0, 2) == "white" && getColor(5, 2, 0) == "white" && getColor(5, 2, 2) == "white" && getColor(2,2,0) == "red" && getColor(2,2,2) == "red" &&
			   getColor(1,2,0) == "blue" && getColor(1,2,2) == "blue" && getColor(3,2,0) == "green" && getColor(3,2,2) == "green" && getColor(4,2,0) == "orange" && getColor(4,2,2) == "orange"));
}