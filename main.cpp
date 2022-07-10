//Include all local files
#include "shared/shared.cpp"
//#include "shared/search.cpp"
//#include "solver/rotation.cpp"
//#include "solver/whitecross.cpp"
//#include "solver/whiteface.cpp"
//#include "solver/midedges.cpp"
//#include "solver/yellowscross.cpp"
//#include "solver/yellowsface.cpp"
//#include "shared/misc.cpp"

using namespace std;

int main(){
	char* white = new char[9] {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE};
	char* yellow = new char[9] {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW};
	char* blue = new char[9] {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE};
	char* green = new char[9] {GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN};
	char* orange = new char[9] {ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE};
	char* red = new char[9] {RED, RED, RED, RED, RED, RED, RED, RED, RED};
/*	
	Cube cube;
	Cube rest;
	vector<Rotation*> commands;

	buildCube(cube, white, yellow, blue, green, orange, red);
	cout << "~~~~~~~~~~~SEED: " << misc::shuffle(cube, 100, 1655223602) << '\n';
	misc::copyCube(cube, rest);


	WC::WC(cube, commands);
	WF::WF(cube, commands);
	ME::ME(cube, commands);
	YSC::YSC(cube, commands);
	//YSF::YSF(cube, commands);

	Telementry::printCube(cube);

	for (auto i : commands)
		rotateSeq(rest, i);

	Telementry::printCube(rest);
	return 0;
	*/
}
