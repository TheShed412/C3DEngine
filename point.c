#include "point.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void add_vec_to_point(point* p1, const vector* vec){
	
	point p2 = vec->start;
	point p3 = vec->end;

	int x = abs(p2.x - p3.x);
	int y = abs(p2.y - p3.y);
	int z = abs(p2.z - p3.z);
	//int t = abs(p2.trans - p3.trans);

	p1->x += x;
	p1->y += y;
	p1->z += z;
	//p1->trans += t;

}

void sub_vec_to_point(point* p1, const vector* vec){

	point p2 = vec->start;
	point p3 = vec->end;

	int x = abs(p2.x - p3.x);
	int y = abs(p2.y - p3.y);
	int z = abs(p2.z - p3.z);
	//int t = abs(p2.trans - p3.trans);

	p1->x -= x;
	p1->y -= y;
	p1->z -= z;
	//p1->trans -= t;

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

void add_vectors(vector* vec_ret, const vector* vec){
	point og_start = vec_ret->start;
	point og_end = vec_ret->end;

	point add_start = vec->start;
	point add_end = vec->end;

	int mag = get_mag(og_start, add_end);

	og_start.x += add_start.x;
	og_start.y += add_start.y;
	og_start.z += add_start.z;

	og_end.x += add_end.x;
	og_end.y += add_end.y;
	og_end.z += add_end.z;
	
	vec_ret->start = og_start;
	vec_ret->end = og_end;
	vec_ret->magnitude = mag;
}

void sub_vectors(vector* vec_ret, const vector* vec){}
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

	p3.x = 3;
	p3.y = 3;
	p3.z = 3;

	p4.x = 4;
	p4.y = 4;
	p4.z = 4;

	vec2.start = p3;
	vec2.end = p4;
	vec2.magnitude = get_mag(p3, p4);

	add_vectors(&vec1, &vec2);

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

void sub_points_test(){
	point p1;
	point p2;

	p1.x = 0;
	p1.y = 1;
	p1.z = 8;

	p1.x = 4;
	p1.y = 2;
	p1.z = 0;

	vector* vec = sub_points(p1, p2);
}

int main(){

	add_vec_test();
	sub_points_test();
}