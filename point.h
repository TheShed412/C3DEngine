#ifndef POINT
#define POINT

/*
	Struct representing a 3D point
*/
typedef struct {
	int x;
	int y;
	int z;
} point;

/*
	Struct representing a 3D vector
*/
typedef struct {
	point start;
	point end;
} vector;

void add_vectors(vector*, vector);
void sub_vectors(vector*, vector);
void xy_rotate(double);

#endif