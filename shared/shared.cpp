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
