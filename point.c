#include "point.h"

#include <math.h>
#include <stdlib.h>

void add_vec_to_point(point* p1, vector vec){
	
	point p2 = vec.start;
	point p3 = vec.end;

	int x = abs(p2.x - p3.x);
	int y = abs(p2.y - p3.y);
	int z = abs(p2.z - p3.z);

	p1->x += x;
	p1->y += y;
	p1->z += z;

}

void sub_vec_to_point(point* p1, vector vec){

	point p2 = vec.start;
	point p3 = vec.end;

	int x = abs(p2.x - p3.x);
	int y = abs(p2.y - p3.y);
	int z = abs(p2.z - p3.z);

	p1->x -= x;
	p1->y -= y;
	p1->z -= z;

}

static int get_mag(point p1, point p2){
	// mag = x^2+y^2+z^2
	
	int x = p2.x - p1.x;
	int y = p2.y - p1.y;
	int z = p2.z - p1.z;

	int mag = (int)sqrt(x^2 + y^2 + z^2);

	return mag;
}

vector* sub_points(point p1, point p2){

	vector* vec = malloc(sizeof(vector));

	vec->start 	= p1;
	vec->end	= p2;
	vec->magnitude = get_mag(p1, p2);

	return vec;
}

void add_vectors(vector* vec_ret, vector vec){}
void sub_vectors(vector* vec_ret, vector vec){}
void xy_rotate(double deg, vector* vec_ret){}
void xz_rotate(double deg, vector* vec_ret){}
void yz_rotate(double deg, vector* vec_ret){}
void scale(double x_mult, double y_mult, double z_mult, vector* vec_ret){}