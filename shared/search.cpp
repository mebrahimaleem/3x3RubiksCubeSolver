//find which face an edge is located on
char findEdgeFace(Cube cube, Edge* edge, bool prm){
	int topr = edge - cube.top.edges;
	int midr = edge - cube.mid.edges;
	int botr = edge - cube.bot.edges;

	if (topr > -1 && topr < 4){
		if (prm) return WHITE;
		return (topr == 0 ? GREEN : (topr == 1 ? ORANGE : (topr == 2 ? BLUE : RED)));
	}

	if (midr > -1 && midr < 4){
		if (prm) return (midr < 2 ? GREEN : BLUE);
		return ((midr == 0 || midr == 3) ? RED : ORANGE);
	}

	if (prm) return YELLOW;
	return (botr == 0 ? GREEN : (botr == 1 ? ORANGE : (botr == 2 ? BLUE : RED)));
}

//find which face a corner is located on
char findCornerFace(Cube cube, Corner* corner, char dir){
	int topr = corner - cube.top.corners;
	int botr = corner - cube.bot.corners;
	
	if (topr > -1 && topr < 4){
		if (dir == 0) return WHITE;
		if (dir == 1) return (topr < 2 ? GREEN : BLUE);
		return (topr == 0 || topr == 3 ? RED : ORANGE);
	}

	if (dir == 0) return YELLOW;
	if (dir == 1) return (botr < 2 ? GREEN : BLUE);
	return (botr == 0 || botr == 3 ? RED : ORANGE);
}

bool verifyCorner(Corner c, char s1, char s2, char s3){
	char* b = (char*)&c;
	char f = 0;
	if (b[0] == s1 || b[0] == s2 || b[0] == s3) f++;
	if (b[1] == s1 || b[1] == s2 || b[1] == s3) f++;
	if (b[2] == s1 || b[2] == s2 || b[2] == s3) f++;
	return f == 3;
}
