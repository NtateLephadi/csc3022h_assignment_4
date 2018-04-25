#include "image.h"

int main(int argc, const char* argv[]){
	image i = image();

	i.load("../pics/shrek_rectangular.pgm");
	image j(i);
	j.save("../pics/save.pgm");
	return 0;
}
