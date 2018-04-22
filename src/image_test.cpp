#define CATCH_CONFIG_MAIN
#include "image.h"

TEST_CASE( "image_iterator default constructor", "[image_iterator(unsigned char)]" ){
	image::image_iterator i_itr = image::image_iterator(0);
	REQUIRE(i_itr.ptr  == 0);
	REQUIRE(i1.getWidth() == 0);
}