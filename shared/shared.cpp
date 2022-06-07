#define WHITE 1
#define BLUE 2
#define ORANGE 3
#define RED 4
#define GREEN 5
#define YELLOW 6

#include <iostream>

using namespace std;

char TOP = WHITE;
char FRONT = BLUE;
char RIGHT = ORANGE;
char LEFT = RED;
char BACK = GREEN;
char BOTTOM = YELLOW;

struct Edge{
	char prm, sec;
};

struct Corner{
	char prm, sec, sid;
};

struct Outer{
	Edge* edges = new Edge[4];
	Corner* corners = new Corner[4];
};

struct Inner{
	Edge* edges = new Edge[4];
};

struct Cube{
	Outer top;
	Inner mid;
	Outer bot;
};
//-FOLD

void buildCube(Cube& cube, char* a1, char* a2, char* a3, char* a4, char* a5, char* a6){	
	char* top, *front, *right, *left, *back, *bottom;
	
	top = (a1[4] == WHITE ? a1 : (a2[4] == WHITE ? a2 : (a3[4] == WHITE ? a3 : (a4[4] == WHITE ? a4 : (a5[4] == WHITE ? a5 : a6)))));
	front = (a1[4] == BLUE ? a1 : (a2[4] == BLUE ? a2 : (a3[4] == BLUE ? a3 : (a4[4] == BLUE ? a4 : (a5[4] == BLUE ? a5 : a6)))));
	right = (a1[4] == ORANGE ? a1 : (a2[4] == ORANGE ? a2 : (a3[4] == ORANGE ? a3 : (a4[4] == ORANGE ? a4 : (a5[4] == ORANGE ? a5 : a6)))));
	left = (a1[4] == RED ? a1 : (a2[4] == RED ? a2 : (a3[4] == RED ? a3 : (a4[4] == RED ? a4 : (a5[4] == RED ? a5 : a6)))));
	back = (a1[4] == GREEN ? a1 : (a2[4] == GREEN ? a2 : (a3[4] == GREEN ? a3 : (a4[4] == GREEN ? a4 : (a5[4] == GREEN ? a5 : a6)))));
	bottom = (a1[4] == YELLOW ? a1 : (a2[4] == YELLOW ? a2 : (a3[4] == YELLOW ? a3 : (a4[4] == YELLOW ? a4 : (a5[4] == YELLOW ? a5 : a6)))));

	cube.top.edges[0].prm = top[1];
	cube.top.edges[1].prm = top[5];
	cube.top.edges[2].prm = top[7];
	cube.top.edges[3].prm = top[3];
	cube.top.corners[0].prm = top[0];
	cube.top.corners[1].prm = top[2];
	cube.top.corners[2].prm = top[8];
	cube.top.corners[3].prm = top[6];

	cube.top.edges[2].sec = front[1];
	cube.mid.edges[2].prm = front[5];
	cube.bot.edges[2].sec = front[7];
	cube.mid.edges[3].prm = front[3];
	cube.top.corners[3].sec = front[0];
	cube.top.corners[2].sec = front[2];
	cube.bot.corners[2].sec = front[8];
	cube.bot.corners[3].sec = front[6];

	cube.top.edges[1].sec = right[1];
	cube.mid.edges[1].sec = right[5];
	cube.bot.edges[1].sec = right[7];
	cube.mid.edges[2].sec = right[3];
	cube.top.corners[2].sid = right[0];
	cube.top.corners[1].sid = right[2];
	cube.bot.corners[1].sid = right[8];
	cube.bot.corners[2].sid = right[6];
	
	cube.top.edges[3].sec = left[1];
	cube.mid.edges[3].sec = left[5];
	cube.bot.edges[3].sec = left[7];
	cube.mid.edges[0].sec = left[3];
	cube.top.corners[0].sid = left[0];
	cube.top.corners[3].sid = left[2];
	cube.bot.corners[3].sid = left[8];
	cube.bot.corners[0].sid = left[6];

	cube.top.edges[0].sec = back[1];
	cube.mid.edges[0].prm = back[5];
	cube.bot.edges[0].sec = back[7];
	cube.mid.edges[1].prm = back[3];
	cube.top.corners[1].sec = back[0];
	cube.top.corners[0].sec = back[2];
	cube.bot.corners[0].sec = back[8];
	cube.bot.corners[1].sec = back[6];
	
	cube.bot.edges[2].prm = bottom[1];
	cube.bot.edges[1].prm = bottom[5];
	cube.bot.edges[0].prm = bottom[7];
	cube.bot.edges[3].prm = bottom[3];
	cube.bot.corners[3].prm = bottom[0];
	cube.bot.corners[2].prm = bottom[2];
	cube.bot.corners[1].prm = bottom[8];
	cube.bot.corners[0].prm = bottom[6];
}//-FOLD

namespace Telementry{
	string getName(char col){
		if (col == WHITE) return "WHITE";
		if (col == YELLOW) return "YELLOW";
		if (col == BLUE) return "BLUE";
		if (col == GREEN) return "GREEN";
		if (col == ORANGE) return "ORANGE";
		return "RED";
	}

	void printSide(Cube cube, char side){
		if (side == WHITE){
			cout << "Side ~ WHITE:\n";

			cout << getName(cube.top.corners[0].prm) << '\t' << 
			getName(cube.top.edges[0].prm) << '\t' << 
			getName(cube.top.corners[1].prm) << '\n' << 
			getName(cube.top.edges[3].prm) << "\tWHITE\t" << 
			getName(cube.top.edges[1].prm) << '\n' << 
			getName(cube.top.corners[3].prm) << '\t' << 
			getName(cube.top.edges[2].prm) << '\t' << 
			getName(cube.top.corners[2].prm) << "\n\n"; 
		}
		
		else if (side == BLUE){
			cout << "Side ~ BLUE:\n";

			cout << getName(cube.top.corners[3].sec) << '\t' << 
			getName(cube.top.edges[2].sec) << '\t' << 
			getName(cube.top.corners[2].sec) << '\n' << 
			getName(cube.mid.edges[3].prm) << "\tBLUE\t" << 
			getName(cube.mid.edges[2].prm) << '\n' << 
			getName(cube.bot.corners[3].sec) << '\t' << 
			getName(cube.bot.edges[2].sec) << '\t' << 
			getName(cube.bot.corners[2].sec) << "\n\n"; 
		}

		else if (side == ORANGE){
			cout << "Side ~ ORANGE:\n";

			cout << getName(cube.top.corners[2].sid) << '\t' << 
			getName(cube.top.edges[1].sec) << '\t' << 
			getName(cube.top.corners[1].sid) << '\n' << 
			getName(cube.mid.edges[2].sec) << "\tORANGE\t" << 
			getName(cube.mid.edges[1].sec) << '\n' << 
			getName(cube.bot.corners[2].sid) << '\t' << 
			getName(cube.bot.edges[1].sec) << '\t' << 
			getName(cube.bot.corners[1].sid) << "\n\n"; 
		}
			
		else if (side == RED){
			cout << "Side ~ RED:\n";

			cout << getName(cube.top.corners[0].sid) << '\t' << 
			getName(cube.top.edges[3].sec) << '\t' << 
			getName(cube.top.corners[3].sid) << '\n' << 
			getName(cube.mid.edges[0].sec) << "\tRED\t" << 
			getName(cube.mid.edges[3].sec) << '\n' << 
			getName(cube.bot.corners[0].sid) << '\t' << 
			getName(cube.bot.edges[3].sec) << '\t' << 
			getName(cube.bot.corners[3].sid) << "\n\n"; 
		}
		
		else if (side == GREEN){
			cout << "Side ~ GREEN:\n";

			cout << getName(cube.top.corners[1].sec) << '\t' << 
			getName(cube.top.edges[0].sec) << '\t' << 
			getName(cube.top.corners[0].sec) << '\n' << 
			getName(cube.mid.edges[1].prm) << "\tGREEN\t" << 
			getName(cube.mid.edges[0].prm) << '\n' << 
			getName(cube.bot.corners[1].sec) << '\t' << 
			getName(cube.bot.edges[0].sec) << '\t' << 
			getName(cube.bot.corners[0].sec) << "\n\n"; 
		}	
		
		else{
			cout << "Side ~ YELLOW:\n";

			cout << getName(cube.bot.corners[3].prm) << '\t' << 
			getName(cube.bot.edges[2].prm) << '\t' << 
			getName(cube.bot.corners[2].prm) << '\n' << 
			getName(cube.bot.edges[3].prm) << "\tYELLOW\t" << 
			getName(cube.bot.edges[1].prm) << '\n' << 
			getName(cube.bot.corners[0].prm) << '\t' << 
			getName(cube.bot.edges[0].prm) << '\t' << 
			getName(cube.bot.corners[1].prm) << "\n\n"; 
		}
	}

	void printCube(Cube cube){
		for (int i = 1; i < 7; i++) printSide(cube, i);
		cout << '\n';
	}
}//-FOLD
