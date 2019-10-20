
struct point 
{
	float x; 
	float y; 
	float z; 
};
struct face
{
	int vtx[3];
};

struct model
{
	point obj_points[9122];
	face obj_faces[18240];
	int vertices;
	int faces;
};

//-------- Functions --------------------------------
void Keyboard(unsigned char key,int x,int y);
// Function for handling keyboard events.

void Mouse(int button,int state,int x,int y); 

void Render();
// The function responsible for drawing everything in the 
// OpenGL context associated to a window. 

void Resize(int w, int h);
// Handle the window size changes and define the world coordinate 
// system and projection type

void Setup();
// Set up the OpenGL state machine and create a light source

void Idle();

void ReadFile(model*);
//Function for reading a model file

void DisplayModel(model);

void Message(const char *str,float size);

int check_crush(float spac_up_down,float spac_left_right,float aster_up_down,float aster_left_right);

float set_asteroid_size();