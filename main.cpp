#include "shared/shared.cpp"
#include "shared/search.cpp"
#include "solver/rotation.cpp"
#include "solver/whitecross.cpp"

using namespace std;

int main(){
	char* white = new char[9] {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE};
	char* yellow = new char[9] {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW};
	char* blue = new char[9] {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE};
	char* green = new char[9] {GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN};
	char* orange = new char[9] {ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE};
	char* red = new char[9] {RED, RED, RED, RED, RED, RED, RED, RED, RED};
	
	Cube cube;
	vector<Rotation*> commands;

	buildCube(cube, white, yellow, blue, green, orange, red);

	WC::WC(cube, commands);

	Telementry::printCube(cube);
	return 0;
}
