#include "image.h"

int main(int argc, const char* argv[]){
	image i = image();
	i.load("../pics/shrek_rectangular.pgm");
	return 0;
}
