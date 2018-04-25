#include "image.h"

int main(int argc, const char* argv[]){
	image i = image();
	i.load("../pics/shrek_rectangular.pgm");
	i.save("../pics/save.pgm");
	return 0;
}
