char findEdgeFace(Cube cube, Edge* edge, bool prm){
	int topr = edge - cube.top.edges;
	int midr = edge - cube.mid.edges;
	int botr = edge - cube.bot.edges;

	if (topr > -1 && topr < 4){
		if (prm) return WHITE;
		return (topr == 0 ? GREEN : (topr == 1 ? ORANGE : (topr == 2 ? BLUE : RED)));
	}

	if (midr > -1 && midr < 4){
		if (prm) return (topr < 2 ? GREEN : BLUE);
		return ((midr == 0 || midr == 3) ? RED : ORANGE);
	}

	if (prm) return YELLOW;
	return (botr == 0 ? GREEN : (botr == 1 ? BLUE : (botr == 2 ? BLUE : RED)));
}

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
