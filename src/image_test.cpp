#define CATCH_CONFIG_MAIN
#include "image.h"

TEST_CASE( "image()" ){
	image i = image();
	REQUIRE(i.getWidth() == 0);
	REQUIRE(i.getHeight() == 0);
	REQUIRE(i.getData() == nullptr);
}

TEST_CASE("image(const image& rhs);"){
	image i1;
	i1.load("../test/pics/shrek_rectangular.pgm");
	image i2(i1);
	REQUIRE(i1.getWidth() == i2.getWidth());
	REQUIRE(i1.getHeight() == i2.getHeight());
}
