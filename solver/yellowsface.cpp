using namespace std;

namespace YSF{ 
	void YSF(Cube& cube, vector<Rotation*>& commands){
		while (cube.bot.corners[0].prm != YELLOW || cube.bot.corners[1].prm != YELLOW || cube.bot.corners[2].prm != YELLOW || cube.bot.corners[3].prm != YELLOW){
			if ((cube.bot.corners[0].prm != YELLOW && cube.bot.corners[1].prm != YELLOW && cube.bot.corners[2].prm != YELLOW && cube.bot.corners[3].prm != YELLOW)){ 
				if (cube.bot.corners[3].sec == YELLOW){
					reor(YELLOW, BLUE);
					rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					continue;
				}
				if (cube.bot.corners[2].sid == YELLOW){
					reor(YELLOW, ORANGE);
					rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					continue;
				}
				if (cube.bot.corners[1].sec == YELLOW){
					reor(YELLOW, GREEN);
					rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					continue;
				}
				if (cube.bot.corners[0].sid == YELLOW){
					reor(YELLOW, RED);
					rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					continue;
				}
			}
			
			if ((cube.bot.corners[0].prm == YELLOW && cube.bot.corners[2].prm == YELLOW) || (cube.bot.corners[1].prm == YELLOW && cube.bot.corners[3].prm == YELLOW)){
				if (cube.bot.corners[0].sid == YELLOW){
					reor(YELLOW, GREEN);
					rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
				}
				if (cube.bot.corners[1].sec == YELLOW){
					reor(YELLOW, ORANGE);
					rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
				}

				if (cube.bot.corners[3].sid == YELLOW){
					reor(YELLOW, BLUE);
					rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
				}

				reor(YELLOW, RED);
				rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
				commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
			}

			if ((cube.bot.corners[0].prm == YELLOW && cube.bot.corners[1].prm == YELLOW) || (cube.bot.corners[1].prm == YELLOW && cube.bot.corners[2].prm == YELLOW) || (cube.bot.corners[2].prm == YELLOW && cube.bot.corners[3].prm == YELLOW) || (cube.bot.corners[3].prm == YELLOW && cube.bot.corners[0].prm == YELLOW)){
				if (cube.bot.corners[2].sec == YELLOW){
					reor(YELLOW, ORANGE);
					rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					continue;
				}
				if (cube.bot.corners[1].sid == YELLOW){
					reor(YELLOW, GREEN);
					rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					continue;
				}
				if (cube.bot.corners[0].sec == YELLOW){
					reor(YELLOW, RED);
					rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					continue;
				}
				if (cube.bot.corners[3].sid == YELLOW){
					reor(YELLOW, BLUE);
					rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
					continue;
				}
			}

			if (cube.bot.corners[3].prm == YELLOW){
				reor(YELLOW, RED);
				rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
				commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
				continue;
			}
			if (cube.bot.corners[0].prm == YELLOW){
				reor(YELLOW, GREEN);
				rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
				commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
				continue;
			}
			if (cube.bot.corners[1].prm == YELLOW){
				reor(YELLOW, ORANGE);
				rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
				commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
				continue;
			}
			reor(YELLOW, BLUE);
			rotateSeq(cube, new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
			commands.push_back(new Rotation[9] {{RIGHT, 0}, {TOP, 0}, {RIGHT, 1}, {TOP, 0}, {RIGHT, 0}, {TOP, 0}, {TOP, 0}, {RIGHT, 1}, {0, 0}});
			continue;
		}
	}
}
