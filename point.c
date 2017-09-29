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

	return -1;
}

vector* sub_points(point p1, point p2){

	vector* vec = malloc(sizeof(vector));



	return vec;
}