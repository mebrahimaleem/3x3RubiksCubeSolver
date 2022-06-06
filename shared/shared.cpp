#define WHITE 1
#define BLUE 2
#define ORANGE 3
#define RED 4
#define GREEN 5
#define YELLOW 6

char TOP = WHITE;
char FRONT = BLUE;
char RIGHT = ORANGE;
char LEFT = RED;
char BACK = GREEN;
char BOTTOM = YELLOW;

struct Edge{
	char prm, sec;
};

struct Corner{
	char prm, sec, sid;
};

struct Outer{
	Edge* edges = new Edge[4];
	Corner* corners = new Corner[4];
};

struct Inner{
	Edge* edges = new Edge[4];
};

struct Cube{
	Outer top;
	Inner mid;
	Outer bot;
};

void buildCube(Cube& cube, char* top, char* front, char* right, char* left, char* back, char* bottom){	
	cube.top.edges[0].prm = top[1];
	cube.top.edges[1].prm = top[5];
	cube.top.edges[2].prm = top[7];
	cube.top.edges[3].prm = top[3];
	cube.top.corners[0].prm = top[0];
	cube.top.corners[1].prm = top[2];
	cube.top.corners[2].prm = top[8];
	cube.top.corners[3].prm = top[6];

	cube.top.edges[2].sec = front[1];
	cube.mid.edges[2].prm = front[5];
	cube.bot.edges[2].sec = front[7];
	cube.mid.edges[3].prm = front[3];
	cube.top.corners[3].sec = front[0];
	cube.top.corners[2].sec = front[2];
	cube.bot.corners[2].sec = front[8];
	cube.bot.corners[3].sec = front[6];

	cube.top.edges[1].sec = right[1];
	cube.mid.edges[1].sec = right[5];
	cube.bot.edges[1].sec = right[7];
	cube.mid.edges[2].sec = right[3];
	cube.top.corners[2].sid = right[0];
	cube.top.corners[1].sid = right[2];
	cube.bot.corners[1].sid = right[8];
	cube.bot.corners[2].sid = right[6];
	
	cube.top.edges[3].sec = left[1];
	cube.mid.edges[3].sec = left[5];
	cube.bot.edges[3].sec = left[7];
	cube.mid.edges[0].sec = left[3];
	cube.top.corners[0].sid = left[0];
	cube.top.corners[3].sid = left[2];
	cube.bot.corners3[].sid = left[8];
	cube.bot.corners[0].sid = left[6];

	cube.top.edges[0].sec = back[1];
	cube.mid.edges[0].prm = back[5];
	cube.bot.edges[0].sec = back[7];
	cube.mid.edges[1].prm = back[3];
	cube.top.corners[1].sec = back[0];
	cube.top.corners[0].sec = back[2];
	cube.bot.corners[0].sec = back[8];
	cube.bot.corners[1].sec = back[6];
	
	cube.bot.edges[2].prm = bottom[1];
	cube.bot.edges[1].prm = bottom[5];
	cube.bot.edges[0].prm = bottom[7];
	cube.bot.edges[3].prm = bottom[3];
	cube.bot.corners[3].prm = bottom[0];
	cube.bot.corners[2].prm = bottom[2];
	cube.bot.corners[1].prm = bottom[8];
	cube.bot.corners[0].prm = bottom[6];
}//-FOLD
