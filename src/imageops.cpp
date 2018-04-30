#include "image.h"

int main(int argc, const char* argv[]){

	image i1, i2;
	std::cout << (argv[1][1]) << '\n';
	switch(argv[1][1]){
		case 'a':
			i1.load(argv[2]);
			i2.load(argv[3]);
			(i1 + i2).save(argv[4]);
		break;
		case 's':
			i1.load(argv[2]);
			i2.load(argv[3]);
			(i1 - i2).save(argv[4]);
		break;
		case 'i':
			i1.load(argv[2]);
			(!(i1)).save(argv[3]);
		break;
		case 'l':
			i1.load(argv[2]);
			i2.load(argv[3]);
			(i1 / i2).save(argv[4]);
		break;
		case 't':
			i1.load(argv[2]);
			(i1 * atoi(argv[3])).save(argv[4]);
		break;
		default:
			std::cout << "Unexpected input format" << '\n';
		break;
	}

	return 0;
}
