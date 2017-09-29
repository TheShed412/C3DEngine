
#include <fcntl.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

#include <linux/fb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/select.h>

#include "graphics.h"

void*   _start_map;
int     _fb_start;
int     _map_size;
struct termios old, new;

/*
    init_graphics()
    
    opens necissary devices for the rest of the program to use for
    graphics manipulation
*/
static int my_open(){
    int fp_start = open("/dev/fb0", O_RDWR);

    if (fp_start < 0)
    {
        perror("could not open device");
    }

    return fp_start;
}

static void* my_mmap(int fb_start, int size){
    void* map = mmap(
        0, size, PROT_EXEC|PROT_READ|PROT_WRITE, 
        MAP_SHARED, fb_start, 0
    );  //get the pointer for the memory map
        // will be shared with os processkun

    if (map == NULL)
    {
        perror("no pointer");
    }

    return map;
}

static void get_vs_info(struct fb_var_screeninfo** vs_info, int* fb_start){

    int info = ioctl(*fb_start, FBIOGET_VSCREENINFO, *vs_info);
    if (info < 0)
        perror("ioctl failed getting virtual screen");
}

static void get_fs_info(struct fb_fix_screeninfo** fs_info, int* fb_start){
    
        int info = ioctl(*fb_start, FBIOGET_FSCREENINFO, *fs_info);
        if (info < 0)
            perror("ioctl failed getting bit depth");
}

static void disable_keys(){

    int term_ret = ioctl(0, TCGETS, &old);

    if(term_ret<0){
        perror("error disabling terminal with TCGETS");
        return;
    }

    new = old;
    new.c_lflag &= ~ICANON;
    new.c_lflag &= ~ECHO;

    term_ret = ioctl(0, TCSETS, &new);
    
        if(term_ret<0){
            perror("error disabling terminal TCSETS");
            return;
        }
}

static void enable_keys(){
    
        int term_ret = ioctl(0, TCGETS, &old);
    
        if(term_ret<0){
            perror("error enabling terminal with TCGETS");
            return;
        }
    
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
    
        term_ret = ioctl(0, TCSETS, &old);
        
            if(term_ret<0){
                perror("error enabling terminal TCSETS");
                return;
            }
}

void my_printf(const char* str){
    write(STDOUT_FILENO, str, sizeof(str)-1);
}

void init_graphics(){

    struct fb_var_screeninfo vs_info;
    struct fb_fix_screeninfo fs_info;

    //So who's afraid of a little abstraction? 
    struct fb_var_screeninfo* vs_infop = &vs_info;
    struct fb_fix_screeninfo* fs_infop = &fs_info;

    _fb_start = my_open(); //get the file descriptor for the framebuffer
    my_printf("\033[2J");
    
    get_vs_info(&vs_infop, &_fb_start);
    get_fs_info(&fs_infop, &_fb_start);
    
    int tot_size = fs_info.line_length * vs_info.yres_virtual;
    _map_size = tot_size;
    _start_map = my_mmap(_fb_start, tot_size); //use framebuffer for the mmap

    disable_keys();
}

void exit_graphics() {

    enable_keys();
    close(_fb_start);
    munmap(_start_map, _map_size);

}

char getkey(){

    char key = 0;
    fd_set rd;
    FD_ZERO(&rd);
    FD_SET(0, &rd);

    int pressed = select(1, &rd, NULL,NULL, NULL);
    if(pressed){
        int thing = read(0, &key, sizeof(key));
        if(key < 0) perror("read error");
    } else if(pressed<0){
        perror("error getting key");
    } 

    return key;
}

void sleep_ms(long ms) {

    long ns = ms*1000000L;
    struct timespec wait;
    wait.tv_sec = 0;
    wait.tv_nsec = ns;

    int pass = nanosleep(&wait, NULL);
    if(pass<0) perror("sleeep was interuppted");

}

void* new_offscreen_buffer() {
    void* map = mmap(
        0, _map_size, PROT_EXEC|PROT_READ|PROT_WRITE, 
        MAP_PRIVATE | MAP_ANONYMOUS, -1, 0
    );  

    if (map == NULL){
        perror("no pointer");
    }

    return map;
}

void blit(void* src) {
    
    color_t* src_int = (color_t*)src;
    color_t* map_int = (color_t*)_start_map;
    color_t temp;

    int i;
    for(i=0; i<(_map_size/2); i++){
        temp = *(src_int+i);
        *(map_int+i) = temp;
    }

}

void clear_screen(void* img) {

    color_t* map_int = (color_t*)img;
   
    int i;
    int j;
        for(i=0; i<_map_size/2; i++){
            map_int[i] = 0;
        }

}

static int my_abs(int num){
    
    if (num<0)  return num*(-1);
    else        return num;
}

static int my_sign(int num){
    if(num > 0) return 1;
    else if(num < 0) return -1;
    else return 0;
}

/*
    img will be the offscreen buffer I draw to. I'm not drawing to the screen.
*/
void draw_pixel(void* img, int x, int y, color_t color) {
    color_t* ct_img = (color_t*)img;
    int y_address = my_abs(y*640);
    int pixel_pos = y_address + x;

    ct_img[pixel_pos] = color;
}


/*
    https://www.tutorialspoint.com/computer_graphics/line_generation_algorithm.htm
    https://www.cs.umd.edu/class/fall2003/cmsc427/bresenham.html
*/
void draw_line(void *img, int x1, int y1, int width, int height, color_t c) {
    //width is x2, height is y2
    int x = x1;
    int y = y1;

    int swap = 0;

    int dy = my_abs(height - y1);
    int dx = my_abs(width - x1);
    int s1 = my_sign(width - x1);
    int s2 = my_sign(height - y1);
    int dbl_dy = dy*2;
    int diff = (dbl_dy - (2*dx));

    if (dy > dx){
        int temp = dx;
        dx = dy;
        dy = temp;
        swap = 1;
    }

    int p = (dbl_dy - dx);

    int i;
    for (i=0; i<dx; i++){
        draw_pixel(img, x,  y, c);

        while(p >= 0){
            p = p - 2*dx;
            if(swap)    x+=s1;
            else        y+=s2;
        }

        p = p + dbl_dy;
        if(swap)    y+=s2;
        else        x+=s1;
    }//for
} 

//;3