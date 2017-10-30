#ifndef POINT
#define POINT

/*
	Struct representing a 3D point
	We are adding a 4th atribute will allow for easieer projections 
*/
typedef struct {
	int x;
	int y;
	int z;
	int trans;
} point;

/*
	Struct representing a 3D vector
*/
typedef struct {
	point start;
	point end;
	int magnitude;
} vector;

/*POINT OPEERATIONS*/
void add_vec_to_point(point*, const vector*);
void sub_vec_to_point(point*, const vector*);
vector* sub_points(point, point);

/*VECTOR OPERATIONS*/
void add_vectors(vector*, const vector*);
void sub_vectors(vector*, const vector*);
void xy_rotate(double, vector*);
void xz_rotate(double, vector*);
void yz_rotate(double, vector*);
void scale(double, double, double, vector*);

#endif