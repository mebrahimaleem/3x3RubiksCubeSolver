using namespace std;

namespace YC{
	void YC(Cube& cube, vector<Rotation*>& commands){
		if (cube.bot.corners[0].sec == cube.bot.corners[1].sec && cube.bot.corners[2].sec == cube.bot.corners[3].sec) return;	
	
		if ((cube.bot.corners[0].sec != cube.bot.corners[1].sec) && (cube.bot.corners[1].sid != cube.bot.corners[2].sid) && (cube.bot.corners[2].sec != cube.bot.corners[3].sec) && (cube.bot.corners[3].sid != cube.bot.corners[0].sid)){
			reor(YELLOW, BLUE);
			rotateSeq(cube, new Rotation[13] {{RIGHT, 1}, {FRONT, 0}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {FRONT, 1}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {RIGHT, 0}, {0, 0}});	
			commands.push_back(new Rotation[13] {{RIGHT, 1}, {FRONT, 0}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {FRONT, 1}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {RIGHT, 0}, {0, 0}});	
		}

		if (cube.bot.corners[0].sec ==  cube.bot.corners[1].sec){
			reor(YELLOW, BLUE);
			rotateSeq(cube, new Rotation[13] {{RIGHT, 1}, {FRONT, 0}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {FRONT, 1}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {RIGHT, 0}, {0, 0}});	
			commands.push_back(new Rotation[13] {{RIGHT, 1}, {FRONT, 0}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {FRONT, 1}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {RIGHT, 0}, {0, 0}});	
			return;
		}
		if (cube.bot.corners[1].sid ==  cube.bot.corners[2].sid){
			reor(YELLOW, RED);
			rotateSeq(cube, new Rotation[13] {{RIGHT, 1}, {FRONT, 0}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {FRONT, 1}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {RIGHT, 0}, {0, 0}});	
			commands.push_back(new Rotation[13] {{RIGHT, 1}, {FRONT, 0}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {FRONT, 1}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {RIGHT, 0}, {0, 0}});	
			return;
		}
		if (cube.bot.corners[2].sec ==  cube.bot.corners[3].sec){
			reor(YELLOW, GREEN);
			rotateSeq(cube, new Rotation[13] {{RIGHT, 1}, {FRONT, 0}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {FRONT, 1}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {RIGHT, 0}, {0, 0}});	
			commands.push_back(new Rotation[13] {{RIGHT, 1}, {FRONT, 0}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {FRONT, 1}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {RIGHT, 0}, {0, 0}});	
			return;
		}
		reor(YELLOW, ORANGE);
		rotateSeq(cube, new Rotation[13] {{RIGHT, 1}, {FRONT, 0}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {FRONT, 1}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {RIGHT, 0}, {0, 0}});	
		commands.push_back(new Rotation[13] {{RIGHT, 1}, {FRONT, 0}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {FRONT, 1}, {RIGHT, 1}, {BACK, 0}, {BACK, 0}, {RIGHT, 0}, {RIGHT, 0}, {0, 0}});	
	}	
}
