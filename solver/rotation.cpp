#define adcycle(a, b, c, d) t=d;d=c;c=b;b=a;a=t
#define dacycle(a, b, c, d) t=a;a=b;b=c;c=d;d=t

void reor(char top, char front){
	TOP = top;
	FRONT = front;
	
	BOTTOM = (top == WHITE ? YELLOW : (top == YELLOW ? WHITE : (top == BLUE ? GREEN : (top == GREEN ? BLUE : (top == RED ? ORANGE : RED)))));
	BACK = (front == WHITE ? YELLOW : (front == YELLOW ? WHITE : (front == BLUE ? GREEN : (front == GREEN ? BLUE : (front == RED ? ORANGE : RED)))));

	if (front == BLUE) RIGHT = (top == WHITE ? ORANGE : (top == ORANGE ? YELLOW : (top == YELLOW ? RED : WHITE)));
	else if (front == ORANGE) RIGHT = (top == WHITE ? GREEN : (top == GREEN ? YELLOW : (top == YELLOW ? BLUE : WHITE)));
	else if (front == GREEN) RIGHT = (top == WHITE ? RED : (top == RED ? YELLOW : (top == YELLOW ? ORANGE : WHITE)));
	else if (front == RED) RIGHT = (top == WHITE ? BLUE : (top == BLUE ? YELLOW : (top == YELLOW ? GREEN : WHITE)));
	else if (front == WHITE) RIGHT = (top == BLUE ? RED : (top == RED ? GREEN : (top == GREEN ? ORANGE : BLUE)));
	else RIGHT = (top == BLUE ? ORANGE : (top == ORANGE ? GREEN : (top == GREEN ? RED : BLUE)));

	LEFT = (RIGHT == WHITE ? YELLOW : (RIGHT == YELLOW ? WHITE : (RIGHT == BLUE ? GREEN : (RIGHT == GREEN ? BLUE : (RIGHT == RED ? ORANGE : RED)))));
}//-FOLD

void rotate(Cube& cube, char side, bool inv){
	char t;

	if (side == WHITE && !inv){
		adcycle(cube.top.edges[0].prm, cube.top.edges[1].prm, cube.top.edges[2].prm, cube.top.edges[3].prm);
		adcycle(cube.top.corners[0].prm, cube.top.corners[1].prm, cube.top.corners[2].prm, cube.top.corners[3].prm);
		adcycle(cube.top.edges[0].sec, cube.top.edges[1].sec, cube.top.edges[2].sec, cube.top.edges[3].sec);
		adcycle(cube.top.corners[0].sec, cube.top.corners[1].sid, cube.top.corners[2].sec, cube.top.corners[3].sid);
		adcycle(cube.top.corners[0].sid, cube.top.corners[1].sec, cube.top.corners[2].sid, cube.top.corners[3].sec);
	}

	else if (side == WHITE && inv){
		dacycle(cube.top.edges[0].prm, cube.top.edges[1].prm, cube.top.edges[2].prm, cube.top.edges[3].prm);
		dacycle(cube.top.corners[0].prm, cube.top.corners[1].prm, cube.top.corners[2].prm, cube.top.corners[3].prm);
		dacycle(cube.top.edges[0].sec, cube.top.edges[1].sec, cube.top.edges[2].sec, cube.top.edges[3].sec);
		dacycle(cube.top.corners[0].sec, cube.top.corners[1].sid, cube.top.corners[2].sec, cube.top.corners[3].sid);
		dacycle(cube.top.corners[0].sid, cube.top.corners[1].sec, cube.top.corners[2].sid, cube.top.corners[3].sec);
	}


	else if (side == YELLOW && !inv){
		dacycle(cube.bot.edges[0].prm, cube.bot.edges[1].prm, cube.bot.edges[2].prm, cube.bot.edges[3].prm);
		dacycle(cube.bot.corners[0].prm, cube.bot.corners[1].prm, cube.bot.corners[2].prm, cube.bot.corners[3].prm);
		dacycle(cube.bot.edges[0].sec, cube.bot.edges[1].sec, cube.bot.edges[2].sec, cube.bot.edges[3].sec);
		dacycle(cube.bot.corners[0].sec, cube.bot.corners[1].sid, cube.bot.corners[2].sec, cube.bot.corners[3].sid);
		dacycle(cube.bot.corners[0].sid, cube.bot.corners[1].sec, cube.bot.corners[2].sid, cube.bot.corners[3].sec);
	}

	else if (side == YELLOW && inv){
		adcycle(cube.bot.edges[0].prm, cube.bot.edges[1].prm, cube.bot.edges[2].prm, cube.bot.edges[3].prm);
		adcycle(cube.bot.corners[0].prm, cube.bot.corners[1].prm, cube.bot.corners[2].prm, cube.bot.corners[3].prm);
		adcycle(cube.bot.edges[0].sec, cube.bot.edges[1].sec, cube.bot.edges[2].sec, cube.bot.edges[3].sec);
		adcycle(cube.bot.corners[0].sec, cube.bot.corners[1].sid, cube.bot.corners[2].sec, cube.bot.corners[3].sid);
		adcycle(cube.bot.corners[0].sid, cube.bot.corners[1].sec, cube.bot.corners[2].sid, cube.bot.corners[3].sec);
	}

	else if (side == BLUE && !inv){
		adcycle(cube.top.edges[2].sec, cube.mid.edges[2].prm, cube.bot.edges[2].sec, cube.mid.edges[3].prm);
		adcycle(cube.top.corners[3].sec, cube.top.corners[2].sec, cube.bot.corners[2].sec, cube.bot.corners[3].sec);
		adcycle(cube.top.edges[2].prm, cube.mid.edges[2].sec, cube.bot.edges[2].prm, cube.mid.edges[3].sec);
		adcycle(cube.top.corners[3].prm, cube.top.corners[2].sid, cube.bot.corners[2].prm, cube.bot.corners[3].sid);
		adcycle(cube.top.corners[3].sid, cube.top.corners[2].prm, cube.bot.corners[2].sid, cube.bot.corners[3].prm);
	}

	else if (side == BLUE && inv){
		dacycle(cube.top.edges[2].sec, cube.mid.edges[2].prm, cube.bot.edges[2].sec, cube.mid.edges[3].prm);
		dacycle(cube.top.corners[3].sec, cube.top.corners[2].sec, cube.bot.corners[2].sec, cube.bot.corners[3].sec);
		dacycle(cube.top.edges[2].prm, cube.mid.edges[2].sec, cube.bot.edges[2].prm, cube.mid.edges[3].sec);
		dacycle(cube.top.corners[3].prm, cube.top.corners[2].sid, cube.bot.corners[2].prm, cube.bot.corners[3].sid);
		dacycle(cube.top.corners[3].sid, cube.top.corners[2].prm, cube.bot.corners[2].sid, cube.bot.corners[3].prm);
	}

	else if (side == GREEN && !inv){
		adcycle(cube.top.edges[0].sec, cube.mid.edges[0].prm, cube.bot.edges[0].sec, cube.mid.edges[1].prm);
		adcycle(cube.top.corners[1].sec, cube.top.corners[0].sec, cube.bot.corners[0].sec, cube.bot.corners[1].sec);
		adcycle(cube.top.edges[0].prm, cube.mid.edges[0].sec, cube.bot.edges[0].prm, cube.mid.edges[1].sec);
		adcycle(cube.top.corners[1].prm, cube.top.corners[0].sid, cube.bot.corners[0].prm, cube.bot.corners[1].sid);
		adcycle(cube.top.corners[1].sid, cube.top.corners[0].prm, cube.bot.corners[0].sid, cube.bot.corners[1].prm);
	}
	
	else if (side == GREEN && inv){
		dacycle(cube.top.edges[0].sec, cube.mid.edges[0].prm, cube.bot.edges[0].sec, cube.mid.edges[1].prm);
		dacycle(cube.top.corners[1].sec, cube.top.corners[0].sec, cube.bot.corners[0].sec, cube.bot.corners[1].sec);
		dacycle(cube.top.edges[0].prm, cube.mid.edges[0].sec, cube.bot.edges[0].prm, cube.mid.edges[1].sec);
		dacycle(cube.top.corners[1].prm, cube.top.corners[0].sid, cube.bot.corners[0].prm, cube.bot.corners[1].sid);
		dacycle(cube.top.corners[1].sid, cube.top.corners[0].prm, cube.bot.corners[0].sid, cube.bot.corners[1].prm);
	}

	else if (side == ORANGE && !inv){
		adcycle(cube.top.edges[1].sec, cube.mid.edges[1].sec, cube.bot.edges[1].sec, cube.mid.edges[2].sec);
		adcycle(cube.top.corners[2].sid, cube.top.corners[1].sid, cube.bot.corners[1].sid, cube.bot.corners[2].sid);
		adcycle(cube.top.edges[1].prm, cube.mid.edges[1].prm, cube.bot.edges[1].prm, cube.mid.edges[2].prm);
		adcycle(cube.top.corners[2].prm, cube.top.corners[1].sec, cube.bot.corners[1].prm, cube.bot.corners[2].sec);
		adcycle(cube.top.corners[2].sec, cube.top.corners[1].prm, cube.bot.corners[1].sec, cube.bot.corners[2].prm);
	}

	else if (side == ORANGE && inv){
		dacycle(cube.top.edges[1].sec, cube.mid.edges[1].sec, cube.bot.edges[1].sec, cube.mid.edges[2].sec);
		dacycle(cube.top.corners[2].sid, cube.top.corners[1].sid, cube.bot.corners[1].sid, cube.bot.corners[2].sid);
		dacycle(cube.top.edges[1].prm, cube.mid.edges[1].prm, cube.bot.edges[1].prm, cube.mid.edges[2].prm);
		dacycle(cube.top.corners[2].prm, cube.top.corners[1].sec, cube.bot.corners[1].prm, cube.bot.corners[2].sec);
		dacycle(cube.top.corners[2].sec, cube.top.corners[1].prm, cube.bot.corners[1].sec, cube.bot.corners[2].prm);
	}
	
	else if (side == RED && !inv){
		adcycle(cube.top.edges[3].sec, cube.mid.edges[3].sec, cube.bot.edges[3].sec, cube.mid.edges[0].sec);
		adcycle(cube.top.corners[0].sid, cube.top.corners[3].sid, cube.bot.corners[3].sid, cube.bot.corners[0].sid);
		adcycle(cube.top.edges[3].prm, cube.mid.edges[3].prm, cube.bot.edges[3].prm, cube.mid.edges[0].prm);
		adcycle(cube.top.corners[0].prm, cube.top.corners[3].sec, cube.bot.corners[3].prm, cube.bot.corners[0].sec);
		adcycle(cube.top.corners[0].sec, cube.top.corners[3].prm, cube.bot.corners[3].sec, cube.bot.corners[0].prm);
	}

	else{
		dacycle(cube.top.edges[3].sec, cube.mid.edges[3].sec, cube.bot.edges[3].sec, cube.mid.edges[0].sec);
		dacycle(cube.top.corners[0].sid, cube.top.corners[3].sid, cube.bot.corners[3].sid, cube.bot.corners[0].sid);
		dacycle(cube.top.edges[3].prm, cube.mid.edges[3].prm, cube.bot.edges[3].prm, cube.mid.edges[0].prm);
		dacycle(cube.top.corners[0].prm, cube.top.corners[3].sec, cube.bot.corners[3].prm, cube.bot.corners[0].sec);
		dacycle(cube.top.corners[0].sec, cube.top.corners[3].prm, cube.bot.corners[3].sec, cube.bot.corners[0].prm);
	}
}//-FOLD

void rotateSeq(Cube& cube, Rotation* seq){
	for (Rotation* i = seq; i->side != 0; i++){
		rotate(cube, i->side, i->inv);	
	}
}
