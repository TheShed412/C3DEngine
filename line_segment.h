#ifndef LINE_SEG
#define LINE_SEG

#include "point.h"

typedef struct line_seg {
	int start_x;
	int end_x;
	int start_y;
	int end_y;
} line_seg;

line_seg* make_line_seg_p(const point*, const point*);
line_seg* make_line_seg_v(const vector*);
line_seg* points_in_segment(const line_seg*);

#endif