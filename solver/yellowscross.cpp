using namespace std;

namespace YSC{
	void YSC(Cube& cube, vector<Rotation*>& commands){
		if (cube.bot.edges[0].prm == YELLOW && cube.bot.edges[1].prm == YELLOW && cube.bot.edges[2].prm == YELLOW && cube.bot.edges[3].prm == YELLOW) return;

		if (cube.bot.edges[0].prm != YELLOW && cube.bot.edges[1].prm != YELLOW && cube.bot.edges[2].prm != YELLOW && cube.bot.edges[3].prm != YELLOW){
			reor(YELLOW, BLUE);
			rotateSeq(cube, new Rotation[7] {{FRONT, 0}, {TOP, 0}, {RIGHT, 0}, {TOP, 1}, {RIGHT, 1}, {FRONT, 1}, {0, 0}});
			commands.push_back(new Rotation[7] {{FRONT, 0}, {TOP, 0}, {RIGHT, 0}, {TOP, 1}, {RIGHT, 1}, {FRONT, 1}, {0, 0}});
		}

		if (cube.bot.edges[0].prm == YELLOW && cube.bot.edges[1].prm == YELLOW){
			reor(YELLOW, BLUE);
			rotateSeq(cube, new Rotation[7] {{FRONT, 0}, {TOP, 0}, {RIGHT, 0}, {TOP, 1}, {RIGHT, 1}, {FRONT, 1}, {0, 0}});
			commands.push_back(new Rotation[7] {{FRONT, 0}, {TOP, 0}, {RIGHT, 0}, {TOP, 1}, {RIGHT, 1}, {FRONT, 1}, {0, 0}});
			return;
		}
		
		if (cube.bot.edges[1].prm == YELLOW && cube.bot.edges[2].prm == YELLOW){
			reor(YELLOW, RED);
			rotateSeq(cube, new Rotation[7] {{FRONT, 0}, {TOP, 0}, {RIGHT, 0}, {TOP, 1}, {RIGHT, 1}, {FRONT, 1}, {0, 0}});
			commands.push_back(new Rotation[7] {{FRONT, 0}, {TOP, 0}, {RIGHT, 0}, {TOP, 1}, {RIGHT, 1}, {FRONT, 1}, {0, 0}});
			return;
		}

		if (cube.bot.edges[2].prm == YELLOW && cube.bot.edges[3].prm == YELLOW){
			reor(YELLOW, GREEN);
			rotateSeq(cube, new Rotation[7] {{FRONT, 0}, {TOP, 0}, {RIGHT, 0}, {TOP, 1}, {RIGHT, 1}, {FRONT, 1}, {0, 0}});
			commands.push_back(new Rotation[7] {{FRONT, 0}, {TOP, 0}, {RIGHT, 0}, {TOP, 1}, {RIGHT, 1}, {FRONT, 1}, {0, 0}});
			return;
		}

		if (cube.bot.edges[3].prm == YELLOW && cube.bot.edges[0].prm == YELLOW){
			reor(YELLOW, ORANGE);
			rotateSeq(cube, new Rotation[7] {{FRONT, 0}, {TOP, 0}, {RIGHT, 0}, {TOP, 1}, {RIGHT, 1}, {FRONT, 1}, {0, 0}});
			commands.push_back(new Rotation[7] {{FRONT, 0}, {TOP, 0}, {RIGHT, 0}, {TOP, 1}, {RIGHT, 1}, {FRONT, 1}, {0, 0}});
			return;
		}

		if (cube.bot.edges[0].prm == YELLOW){
			reor(YELLOW, ORANGE);
			rotateSeq(cube, new Rotation[7] {{FRONT, 0}, {RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 1}, {FRONT, 1}, {0, 0}});
			commands.push_back(new Rotation[7] {{FRONT, 0}, {RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 1}, {FRONT, 1}, {0, 0}});
			return;
		}

		reor(YELLOW, BLUE);
		rotateSeq(cube, new Rotation[7] {{FRONT, 0}, {RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 1}, {FRONT, 1}, {0, 0}});
		commands.push_back(new Rotation[7] {{FRONT, 0}, {RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 1}, {FRONT, 1}, {0, 0}});
	}
}
