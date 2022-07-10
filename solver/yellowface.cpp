using namespace std;

namespace YF{
	void YF(Cube& cube, vector<Rotation*>& commands){
		if (oppositeOf(cube.bot.edges[0].sec) == cube.bot.edges[2].sec){
			reor(YELLOW, BLUE);
			rotateSeq(cube, new Rotation[13] {{FRONT, 0}, {FRONT, 0}, {TOP, 0}, {RIGHT, 1}, {LEFT, 0}, {FRONT, 0}, {FRONT, 0}, {RIGHT, 0}, {LEFT, 1}, {TOP, 0}, {FRONT, 0}, {FRONT, 0}, {0, 0}});
			commands.push_back(new Rotation[13] {{FRONT, 0}, {FRONT, 0}, {TOP, 0}, {RIGHT, 1}, {LEFT, 0}, {FRONT, 0}, {FRONT, 0}, {RIGHT, 0}, {LEFT, 1}, {TOP, 0}, {FRONT, 0}, {FRONT, 0}, {0, 0}});
			goto align;
		}
		
		if (cube.bot.corners[0].sec != cube.bot.edges[0].sec && cube.bot.corners[2].sec != cube.bot.edges[2].sec && cube.bot.corners[1].sid != cube.bot.edges[1].sec && cube.bot.corners[3].sid != cube.bot.edges[3].sec){
			reor(YELLOW, BLUE);
			if (cube.bot.corners[2].sec == cube.bot.corners[3].sid){
				rotateSeq(cube, new Rotation[13] {{FRONT, 0}, {FRONT, 0}, {TOP, 0}, {RIGHT, 1}, {LEFT, 0}, {FRONT, 0}, {FRONT, 0}, {RIGHT, 0}, {LEFT, 1}, {TOP, 0}, {FRONT, 0}, {FRONT, 0}, {0, 0}});
				commands.push_back(new Rotation[13] {{FRONT, 0}, {FRONT, 0}, {TOP, 0}, {RIGHT, 1}, {LEFT, 0}, {FRONT, 0}, {FRONT, 0}, {RIGHT, 0}, {LEFT, 1}, {TOP, 0}, {FRONT, 0}, {FRONT, 0}, {0, 0}});
				goto align;	
			}
			rotateSeq(cube, new Rotation[13] {{FRONT, 0}, {FRONT, 0}, {TOP, 1}, {RIGHT, 1}, {LEFT, 0}, {FRONT, 0}, {FRONT, 0}, {RIGHT, 0}, {LEFT, 1}, {TOP, 1}, {FRONT, 0}, {FRONT, 0}, {0, 0}});
			commands.push_back(new Rotation[13] {{FRONT, 0}, {FRONT, 0}, {TOP, 1}, {RIGHT, 1}, {LEFT, 0}, {FRONT, 0}, {FRONT, 0}, {RIGHT, 0}, {LEFT, 1}, {TOP, 1}, {FRONT, 0}, {FRONT, 0}, {0, 0}});
		}

align:
		reor(YELLOW, BLUE);
		if (cube.bot.corners[0].sec == GREEN) goto sfinal;
		if (cube.bot.corners[0].sec == BLUE){
			rotateSeq(cube, new Rotation[3] {{TOP, 0}, {TOP, 0}, {0, 0}});
			commands.push_back(new Rotation[3] {{TOP, 0}, {TOP, 0}, {0, 0}});
			goto sfinal;
		}
		if (cube.bot.corners[0].sec == RED){
			rotateSeq(cube, new Rotation[2] {{TOP, 0}, {0, 0}});
			commands.push_back(new Rotation[2] {{TOP, 0}, {0, 0}});
			goto sfinal;
		}
		rotateSeq(cube, new Rotation[2] {{TOP, 1}, {0, 0}});
		commands.push_back(new Rotation[2] {{TOP, 1}, {0, 0}});

sfinal:
		char colal = cube.bot.edges[1].sec;
		if (cube.bot.edges[0].sec == GREEN && cube.bot.edges[2].sec == BLUE) return;
		if (cube.bot.edges[0].sec == GREEN){
			reor(YELLOW, BLUE);
			colal = cube.bot.edges[2].sec;
			goto solve;
		}
		if (cube.bot.edges[1].sec == ORANGE){
			reor(YELLOW, RED);
			colal = cube.bot.edges[3].sec;
			goto solve;
		}
		if (cube.bot.edges[2].sec == BLUE){
			reor(YELLOW, GREEN);
			colal = cube.bot.edges[0].sec;
			goto solve;
		}
		reor(YELLOW, ORANGE);

solve:
		if (colal == LEFT){
			rotateSeq(cube, new Rotation[13] {{FRONT, 0}, {FRONT, 0}, {TOP, 0}, {RIGHT, 1}, {LEFT, 0}, {FRONT, 0}, {FRONT, 0}, {RIGHT, 0}, {LEFT, 1}, {TOP, 0}, {FRONT, 0}, {FRONT, 0}, {0, 0}});
			commands.push_back(new Rotation[13] {{FRONT, 0}, {FRONT, 0}, {TOP, 0}, {RIGHT, 1}, {LEFT, 0}, {FRONT, 0}, {FRONT, 0}, {RIGHT, 0}, {LEFT, 1}, {TOP, 0}, {FRONT, 0}, {FRONT, 0}, {0, 0}});
			return;
		}
			rotateSeq(cube, new Rotation[13] {{FRONT, 0}, {FRONT, 0}, {TOP, 1}, {RIGHT, 1}, {LEFT, 0}, {FRONT, 0}, {FRONT, 0}, {RIGHT, 0}, {LEFT, 1}, {TOP, 1}, {FRONT, 0}, {FRONT, 0}, {0, 0}});
			commands.push_back(new Rotation[13] {{FRONT, 0}, {FRONT, 0}, {TOP, 1}, {RIGHT, 1}, {LEFT, 0}, {FRONT, 0}, {FRONT, 0}, {RIGHT, 0}, {LEFT, 1}, {TOP, 1}, {FRONT, 0}, {FRONT, 0}, {0, 0}});
	}
}
