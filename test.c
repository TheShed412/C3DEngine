#include <stdio.h>
#include "graphics.h"
#include "point.h"

void color_test(int red, int green, int blue){
    printf("Red: %x\n", red);
    printf("Green: %x\n", green);
    printf("Blue: %x\n", blue);

    color_t color = RGB(red, green, blue);

    printf("color: %x\n", color);
}

void wait_test(){
    sleep_ms(5000);
}

void blit_test(){
    init_graphics(); //makes mmap of screen
    color_t* off_buff = new_offscreen_buffer();
    
    color_t col = RGB(0xff, 0x00, 0xff);

    int i;
    for(i=0; i<153600*2; i++){
        *(off_buff+i) = col;
    }

    blit(off_buff);

    exit_graphics();
}


void draw_pixel_test(){
    init_graphics();
    color_t* off_buff = new_offscreen_buffer();
    color_t col = RGB(0xff, 0x00, 0xff);
    draw_pixel(off_buff, 250, 250, col);
    blit(off_buff);
    exit_graphics();
}

void line_test(){
    init_graphics();
    color_t* off_buff = new_offscreen_buffer();
    color_t col = RGB(0xff, 0x00, 0xff);
    draw_line(off_buff, 500, 400, 150, 150, col);
    blit(off_buff);
    exit_graphics();
}

void key_test(){

    char key;

    do{
        key = getkey();
        if(key == 'q') break;
    }while(1);
}

int main(){
   line_test();
}