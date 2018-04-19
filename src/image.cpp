#include "image.h"
#include <fstream>
#include <sstream>

image::image(){
		width = 0;
		height = 0;
		data = nullptr;
}

image::~image(){
}

int image::getHeight() const{
	return image::height;
}

int image::getWidth() const{
	return image::width;
}

void image::load(std::string filename){
	
}