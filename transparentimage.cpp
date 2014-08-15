#include <png++/png.hpp>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <png++/rgba_pixel.hpp>
 
int main(int nNumberofArgs, char *pszArgs[]) {
  
  png::image< png::rgba_pixel > image("gnome.png");
  png::image< png::rgba_pixel > image2(image.get_width(),image.get_height());
  std::cout<<"inaltimea imagini: "<<image.get_height()<<"\n";
  std::cout<<"lungimea imagini: "<<image.get_width()<<"\n";
  for (size_t y = 0; y < image.get_height(); ++y) {
    for (size_t x = 0; x < image.get_width(); ++x) {
	image2[y][x].red = image.get_pixel(x,y).red;
	image2[y][x].green = image.get_pixel(x,y).green;
	image2[y][x].blue = /*0;*/image.get_pixel(x,y).blue;
	image2[y][x].alpha = 200;
	}
  }
    
 image2.write("translucid.png");
}
