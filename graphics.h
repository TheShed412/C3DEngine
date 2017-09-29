#ifndef GFX_LIB
#define GFX_LIB

#define WIDTH   640
#define HEIGHT  480 
#define CLEAR   "\033[2J"

typedef unsigned short color_t;

#define RGB(red, green, blue) (((red) << 11) | ((green) << 5) | (blue))
#define sign(x) ((x > 0)? 1 : ((x < 0)? -1: 0))

void init_graphics();
void exit_graphics();
char getkey();
void sleep_ms(long);
void clear_screen(void*);
void draw_pixel(void*, int, int, color_t);
void draw_line(void*, int, int, int, int, color_t);
void* new_offscreen_buffer();
void blit(void*);

#endif