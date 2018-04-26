#include "image.h"

int main(int argc, const char* argv[]){

	image i1, i2, i3;

	i1.load("../pics/Lenna_hat_mask.pgm");
	i2.load("../pics/Lenna_standard.pgm");
	i3 = i1 + i2;
	i3.save("../pics/Lenna_add.pgm");

	// switch(argv[1][1]){
	// 	case 'a':
	// 		i1.load(argv[2]);
	// 		i2.load(argv[3]);
	// 		i3 = i1 + i2;
	// 		i3.save(argv[4]);
	// 	break;
	// 	case 's':
	// 		i1.load(argv[2]);
	// 		i2.load(argv[3]);
	// 		i3 = i1 - i2;
	// 		i3.save(argv[4]);
	// 	break;
	// 	case 'i':
	// 		i1.load(argv[1]);
	// 		i2 = !(i1);
	// 		i2.save(argv[3]);
	// 	break;
	// 	case 'l':
	// 		i1.load(argv[2]);
	// 		i2.load(argv[3]);
	// 		i3 = i1 / i2;
	// 		i3.save(argv[4]);
	// 	break;
	// 	case 't':
	// 		i1.load(argv[2]);
	// 		i2 = i1 * atoi(argv[3]);
	// 		i2.save(argv[4]);
	// 	break;
	// 	default:
	// 		std::cout << "Unexpected input format" << '\n';
	// 	break;
	// }
	return 0;
}
