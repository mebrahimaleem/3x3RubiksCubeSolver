using namespace std;

namespace misc{
	//Coppies cube
	void copyCube(Cube& src, Cube& tar){
		copy(src.top.edges, src.top.edges + 4, tar.top.edges);
		copy(src.top.corners, src.top.corners + 4, tar.top.corners);
		copy(src.mid.edges, src.mid.edges + 4, tar.mid.edges);
		copy(src.bot.edges, src.bot.edges + 4, tar.bot.edges);
		copy(src.bot.corners, src.bot.corners + 4, tar.bot.corners);
	}
	//Randomly shuffles cube
	int shuffle(Cube& cube, int rots = 100, int seed = -1){
		int s;
		if (seed == -1) s = time(0);
		else s = seed;
		srand(s);
		for (; rots > 0; rots--)
			rotate(cube, rand() % 6 + 1, rand() % 1);
		return s;
	}
	
	//Command line simulator for cube
	void simLine(Cube cube){
		char T, F;
		T = TOP;
		F = FRONT;
		reor(WHITE, BLUE);
		char op;
		char inv = 0;
		char t, f;
		while (true){
			Telementry::printCube(cube);
			cin >> op;
			inv = 0;
			if (op == 'q'){
				reor(T, F);
				return;
			}
			if (op == '\''){
				inv = 1;
				cin >> op;
			}

			switch (op){
				case 'd':
					rotate(cube, BOTTOM, inv);
					break;
				case 'u':
					rotate(cube, TOP, inv);
					break;
				case 'r':
					rotate(cube, RIGHT, inv);
					break;
				case 'l':
					rotate(cube, LEFT, inv);
					break;
				case 'f':
					rotate(cube, FRONT, inv);
					break;
				case 'b':
					rotate(cube, BACK, inv);
					break;
				default:
					cout << "INVALID\n";
					break;
			}
		}
	}
}
