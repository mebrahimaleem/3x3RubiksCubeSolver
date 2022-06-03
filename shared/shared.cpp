#define INC_SHARED

#define WHITE 1
#define BLUE 2
#define ORANGE 3
#define RED 4
#define GREEN 5
#define YELLOW 6

int TOP = WHITE;
int FRONT = BLUE;
int RIGHT = ORANGE;
int LEFT = RED;
int BACK = GREEN;
int BOTTOM = YELLOW;

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
