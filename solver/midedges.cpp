using namespace std;

namespace ME{
	void MEstep(Cube& cube, char colf, char cols, vector<Rotation*>& commands){
		char palign;
		char salign;
state1:
		for (Edge* i = cube.mid.edges; i < cube.mid.edges + 4; i++){
			if ((i->prm == colf && i->sec == cols) || (i->prm == cols && i->sec == colf)){
				palign = findEdgeFace(cube, i, 1);
				salign = findEdgeFace(cube, i, 0);
				if (palign == i->prm && salign == i->sec) return;
				reor(YELLOW, (((palign == BLUE && salign == ORANGE) || (palign == GREEN && salign == RED)) ? salign : palign));
				rotateSeq(cube, new Rotation[9] {{TOP, 0}, {RIGHT, 0}, {TOP, 1}, {RIGHT, 1}, {TOP, 1}, {FRONT, 1}, {TOP, 0}, {FRONT, 0}, {0, 0}});
				commands.push_back(new Rotation[9] {{TOP, 0}, {RIGHT, 0}, {TOP, 1}, {RIGHT, 1}, {TOP, 1}, {FRONT, 1}, {TOP, 0}, {FRONT, 0}, {0, 0}});
				goto state2;
			}
		}
state2:
		for (Edge* i = cube.bot.edges; i < cube.bot.edges + 4; i++){
			if ((i->prm == colf && i->sec == cols) || (i->prm == cols && i->sec == colf)){
				palign = findEdgeFace(cube, i, 0);
				reor(YELLOW, i->sec);
				if (palign == RIGHT){
					rotateSeq(cube, new Rotation[2] {{TOP, 0}, {0, 0}});
					commands.push_back(new Rotation[2] {{TOP, 0}, {0, 0}});
				}
				else if (palign == LEFT){
					rotateSeq(cube, new Rotation[2] {{TOP, 1}, {0, 0}});
					commands.push_back(new Rotation[2] {{TOP, 1}, {0, 0}});
				}
				else if (palign == BACK){
					rotateSeq(cube, new Rotation[3] {{TOP, 0}, {TOP, 0}, {0, 0}});
					commands.push_back(new Rotation[3] {{TOP, 0}, {TOP, 0}, {0, 0}});
				}
				goto state3;
			}
		}
state3:
		for (Edge* i = cube.bot.edges; i < cube.bot.edges + 4; i++){
			if ((i->prm == colf && i->sec == cols) || (i->prm == cols && i->sec == colf)){
				if (i->prm == RIGHT){
					rotateSeq(cube, new Rotation[9] {{TOP, 0}, {RIGHT, 0}, {TOP, 1}, {RIGHT, 1}, {TOP, 1}, {FRONT, 1}, {TOP, 0}, {FRONT, 0}, {0, 0}});
					commands.push_back(new Rotation[9] {{TOP, 0}, {RIGHT, 0}, {TOP, 1}, {RIGHT, 1}, {TOP, 1}, {FRONT, 1}, {TOP, 0}, {FRONT, 0}, {0, 0}});
					return;
				}
				rotateSeq(cube, new Rotation[9] {{TOP, 1}, {LEFT, 1}, {TOP, 0}, {LEFT, 0}, {TOP, 0}, {FRONT, 0}, {TOP, 1}, {FRONT, 1}, {0, 0}});
				commands.push_back(new Rotation[9] {{TOP, 1}, {LEFT, 1}, {TOP, 0}, {LEFT, 0}, {TOP, 0}, {FRONT, 0}, {TOP, 1}, {FRONT, 1}, {0, 0}});
				return;
			}
		}
	}

	void ME(Cube& cube, vector<Rotation*>& commands){
		MEstep(cube, BLUE, RED, commands);
		MEstep(cube, BLUE, ORANGE, commands);
		MEstep(cube, GREEN, ORANGE, commands);
		MEstep(cube, GREEN, RED, commands);
	}
}
