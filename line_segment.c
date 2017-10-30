#include "line_segment.h"
#include "point.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * This will be where the 3d points and vectors wwill be projected on to 2d space
*/

/**
 * The projcted 2D point
*/
typedef struct point2d {
	int proj_x;
	int proj_y;
} point2d;

static point2d* project(const point* p3d){

}

line_seg* make_line_seg_p(const point* p1, const point* p2){

	line_seg* seg = (line_seg*)malloc(sizeof(line_seg));

}

line_seg* make_line_seg_v(const vector* vec){}

line_seg* points_in_segment(const line_seg* seg){}


/**
 * unit tests
*/
int main(){
	printf("Line\n");
}