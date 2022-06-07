#include "shared/shared.cpp"
#include "solver/rotation.cpp"

using namespace std;

int main(){
	Cube cube;
	
	char* white = new char[9] {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE};
	char* yellow = new char[9] {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW};
	char* blue = new char[9] {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE};
	char* green = new char[9] {GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN};
	char* orange = new char[9] {ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE};
	char* red = new char[9] {RED, RED, RED, RED, RED, RED, RED, RED, RED};
	
	Rotation* moves = new Rotation[13] {{TOP, 0}, {FRONT, 0}, {RIGHT, 0}, {LEFT, 0}, {BACK, 0}, {BOTTOM, 0},
		{BOTTOM, 1}, {BACK, 1}, {LEFT, 1}, {RIGHT, 1}, {FRONT, 1}, {TOP, 1}, {0, 0}};
	buildCube(cube, white, blue, orange, red, green, yellow);
	rotateSeq(cube, moves);
	Telementry::printCube(cube);

	return 0;
}
