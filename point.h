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

/*POINT OPEERATIONS*/
void add_vec_to_point(point*, vector);
void add_vec_to_point(sub*, vector);
vector* sub_points(point, point);

/*VECTOR OPERATIONS*/
void add_vectors(vector*, vector);
void sub_vectors(vector*, vector);
void xy_rotate(double, vector*);
void xz_rotate(double, vector*);
void yz_rotate(double, vector*);
void scale(double, double, double, vector*);

#endif