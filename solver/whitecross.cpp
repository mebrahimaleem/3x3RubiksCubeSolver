using namespace std;

namespace WC{
	void WCstep(Cube& cube, char col, vector<Rotation*> commands){
		char align;
state1:
		for (Edge* i = cube.top.edges; i < cube.top.edges + 4; i++){
			if ((i->prm == WHITE && i->sec == col) || (i->prm == col && i->sec == WHITE)){
				align = findEdgeFace(cube, i, false);
				if (i->prm == WHITE && i->sec == align) return;
				reor(WHITE, align);
				rotateSeq(cube, new Rotation[3] {{FRONT, 0}, {FRONT, 0}, {0, 0}});
				commands.push_back(new Rotation[3] {{FRONT, 0}, {FRONT, 0}, {0, 0}});
				goto state3;
			}
		}

state2:
		for (Edge* i = cube.mid.edges; i < cube.mid.edges + 4; i++){
			if ((i->prm == WHITE && i->sec == col) || (i->prm == col && i->sec == WHITE)){
				align = findEdgeFace(cube, i, ((i - cube.mid.edges) % 2 == 0 ? true : false));
				reor(WHITE, align);
				rotateSeq(cube, new Rotation[4] {{RIGHT, 1}, {BOTTOM, 1}, {RIGHT, 0}, {0, 0}});
				commands.push_back(new Rotation[4] {{RIGHT, 1}, {BOTTOM, 1}, {RIGHT, 0}, {0, 0}});
				goto state3;
			}
		}
state3:
		for (Edge* i = cube.bot.edges; i < cube.bot.edges + 4; i++){
			if (i->prm == col && i->sec == WHITE){
				align = findEdgeFace(cube, i, false);
				reor(WHITE, align);
				rotateSeq(cube, new Rotation[6] {{FRONT, 1}, {RIGHT, 1}, {BOTTOM, 0}, {RIGHT, 0}, {FRONT, 0}, {0, 0}});
				commands.push_back(new Rotation[6] {{FRONT, 1}, {RIGHT, 1}, {BOTTOM, 0}, {RIGHT, 0}, {FRONT, 0}, {0, 0}});
				goto state4;
			}
		}
state4:
		for (Edge* i = cube.bot.edges; i < cube.bot.edges + 4; i++){
			if (i->prm == WHITE && i->sec == col){
				reor(WHITE, col);
				align = findEdgeFace(cube, i, false);
				if (FRONT == align) goto state5;
				if (BACK == align){
					rotateSeq(cube, new Rotation[3] {{BOTTOM, 0}, {BOTTOM, 0}, {0, 0}});
					commands.push_back(new Rotation[3] {{BOTTOM, 0}, {BOTTOM, 0}, {0, 0}});
					goto state5;
				}
				if (RIGHT == align){
					rotateSeq(cube, new Rotation[2] {{BOTTOM, 0}, {0, 0}});
					commands.push_back(new Rotation[2] {{BOTTOM, 0}, {0, 0}});
					goto state5;
				}
				else{
					rotateSeq(cube, new Rotation[2] {{BOTTOM, 1}, {0, 0}});
					commands.push_back(new Rotation[2] {{BOTTOM, 1}, {0, 0}});
				}
			}
		}	
state5:
		rotateSeq(cube, new Rotation[3] {{BOTTOM, 0}, {BOTTOM, 0}, {0, 0}});
		commands.push_back(new Rotation[3] {{BOTTOM, 0}, {BOTTOM, 0}, {0, 0}});
	}
	
	void WC(Cube& cube, vector<Rotation*> commands){
		WCstep(cube, BLUE, commands);
		WCstep(cube, ORANGE, commands);
		WCstep(cube, GREEN, commands);
		WCstep(cube, RED, commands);
	}
}
