#include "point.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

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

void add_vectors(vector* vec_ret, vector vec){
	point og_start = vec_ret->start;
	point og_end = vec_ret->end;

	
}

void sub_vectors(vector* vec_ret, vector vec){}
void xy_rotate(double deg, vector* vec_ret){}
void xz_rotate(double deg, vector* vec_ret){}
void yz_rotate(double deg, vector* vec_ret){}
void scale(double x_mult, double y_mult, double z_mult, vector* vec_ret){}

void add_vec_test(){
	point p1, p2, p3, p4;
	vector vec1, vec2;

	p1.x = 1;
	p1.y = 1;
	p1.z = 1;

	p2.x = 2;
	p2.y = 2;
	p2.z = 2;

	vec1.start = p1;
	vec1.end = p2;
	vec1.magnitude = get_mag(p1, p2);

	p2.x = 3;
	p2.y = 3;
	p2.z = 3;

	p4.x = 4;
	p4.y = 4;
	p4.z = 4;

	vec2.start = p3;
	vec2.end = p4;
	vec2.magnitude = get_mag(p3, p4);

	add_vectors(&vec1, vec2);

	int sp1x = vec1.start.x;
	int sp1y = vec1.start.y;
	int sp1z = vec1.start.z;

	int ep1x = vec1.end.x;
	int ep1y = vec1.end.y;
	int ep1z = vec1.end.z;

	if(sp1x==4 && sp1y==4 && sp1z==4) printf("Start Point passes\n");
	else printf("Start Point fails\n");

	if(ep1x==6 && ep1y==6 && ep1z==6) printf("End Point passes\n");
	else printf("End Point fails\n");
}

int main(){

	add_vec_test();

}