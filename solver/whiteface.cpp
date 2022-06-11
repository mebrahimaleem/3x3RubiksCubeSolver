using namespace std;

//namespace containing all function for solving the white face
//Assumes WC::WC(Cube&) has already been called
namespace WF{
	//Solves individual white face piece
	void WFstep(Cube& cube, char colf, char cols, vector<Rotation*>& commands){
		char palign;
state1:
		for (Corner* i = cube.top.corners; i < cube.top.corners + 4; i++){
			if (verifyCorner(*i, WHITE, colf, cols)){
				palign = findCornerFace(cube, i, ((i - cube.bot.corners) % 2 == 0 ? 1 : 2));
				if (i->prm ==WHITE && i->sec == palign && i->sid == cols) return;
				reor(WHITE, palign);
				rotateSeq(cube, new Rotation[4] {{RIGHT, 1}, {BOTTOM, 1}, {RIGHT, 0}, {0, 0}});
				commands.push_back(new Rotation[4] {{RIGHT, 1}, {BOTTOM, 1}, {RIGHT, 0}, {0, 0}});
				goto state2;
			}
		}

state2:
		for (Corner* i = cube.bot.corners; i < cube.bot.corners + 4; i++){
			if ((i->prm == WHITE && i->sec == colf && i->sid == cols) || (i->prm == WHITE && i->sec == cols && i->sid == colf)){
				palign = findCornerFace(cube, i, ((i - cube.bot.corners) % 2 == 0 ? 1 : 2));
				reor(WHITE, palign);
				rotateSeq(cube, new Rotation[9] {{RIGHT, 1}, {BOTTOM, 0}, {BOTTOM, 0}, {RIGHT, 0}, {BOTTOM, 0}, {RIGHT, 1}, {BOTTOM, 0}, {RIGHT, 0}, {0, 0}});
				commands.push_back(new Rotation[9] {{RIGHT, 1}, {BOTTOM, 0}, {BOTTOM, 0}, {RIGHT, 0}, {BOTTOM, 0}, {RIGHT, 1}, {BOTTOM, 0}, {RIGHT, 0}, {0, 0}});
				goto state3;
			}
		}

state3: 
		for (Corner* i = cube.bot.corners; i < cube.bot.corners + 4; i++){
			if (verifyCorner(*i, WHITE, colf, cols)){
				reor(WHITE, (((colf == BLUE &&  cols == RED) || (colf == GREEN && cols == ORANGE)) ? cols : colf));
				palign = findCornerFace(cube, i, ((i - cube.bot.corners) % 2 == 0 ? 1 : 2));
				if (palign == FRONT) goto state4;
				if (palign == RIGHT){
					rotateSeq(cube, new Rotation[2] {{BOTTOM, 1}, {0, 0}});
					commands.push_back(new Rotation[2] {{BOTTOM, 1}, {0, 0}});
					goto state4;
				}
				if (palign == LEFT){
					rotateSeq(cube, new Rotation[2] {{BOTTOM, 0}, {0, 0}});
					commands.push_back(new Rotation[2] {{BOTTOM, 0}, {0, 0}});
					goto state4;
				}
				rotateSeq(cube, new Rotation[3] {{BOTTOM, 0}, {BOTTOM, 0}, {0, 0}});
				commands.push_back(new Rotation[3] {{BOTTOM, 0}, {BOTTOM, 0}, {0, 0}});
				goto state4;
				}
		}

state4: 
		for (Corner* i = cube.bot.corners; i < cube.bot.corners + 4; i++){
			if (verifyCorner(*i, WHITE, colf, cols)){
				int dif = i - cube.bot.corners;
				if((i->sec == WHITE && (dif == 0 || dif == 2)) || (i->sid == WHITE && (dif == 1 || dif == 3))){
					reor(WHITE, (dif % 2 == 0 ? colf : cols));
					rotateSeq(cube, new Rotation[5] {{BOTTOM, 1}, {RIGHT, 1}, {BOTTOM, 0}, {RIGHT, 0}, {0, 0}});
					commands.push_back(new Rotation[5] {{BOTTOM, 1}, {RIGHT, 1}, {BOTTOM, 0}, {RIGHT, 0}, {0, 0}});
					return;
				}
				reor(WHITE, (dif % 2 == 0 ? cols : colf));
				rotateSeq(cube, new Rotation[5] {{BOTTOM, 0}, {LEFT, 0}, {BOTTOM, 1}, {LEFT, 1}, {0, 0}});
				commands.push_back(new Rotation[5] {{BOTTOM, 0}, {LEFT, 0}, {BOTTOM, 1}, {LEFT, 1}, {0, 0}});
				return;
			}
		}
	}
	
	//Solves entire white face
	void WF(Cube& cube, vector<Rotation*>& commands){
		WFstep(cube, BLUE, RED, commands);
		WFstep(cube, BLUE, ORANGE, commands);
		WFstep(cube, GREEN, ORANGE, commands);
		WFstep(cube, GREEN, RED, commands);
	}
}
