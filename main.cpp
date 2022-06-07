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

	buildCube(cube, white, blue, orange, red, green, yellow);
	Telementry::printCube(cube);

	return 0;
}
