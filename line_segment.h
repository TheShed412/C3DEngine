#ifndef LINE_SEG
#define LINE_SEG

#include "point.h"

typedef struct line_seg {
	int start_x;
	int end_x;
	int start_y;
	int end_y;
} line_seg;

line_seg* make_line_seg_p(point, point);
line_seg* make_line_seg_v(vector);
line_seg* points_in_segment(line_seg);

#endif