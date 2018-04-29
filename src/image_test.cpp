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
	i1.load("../pics/shrek_rectangular.pgm");
	image i2(i1);

	REQUIRE(i2.getWidth() == 1207);
	REQUIRE(i2.getHeight() == 1280);
}

TEST_CASE("image(image&& rhs)"){
	image i1;
	i1.load("../pics/shrek_rectangular.pgm");
	image i2 = std::move(i1);

	REQUIRE(i1.getWidth() == 0);
	REQUIRE(i1.getHeight() == 0);

	REQUIRE(i2.getWidth() == 1207);
	REQUIRE(i2.getHeight() == 1280);
}

TEST_CASE("void load(const std::string& filename)"){
	image i1;
	i1.load("../pics/shrek_rectangular.pgm");

	REQUIRE(i1.getWidth() == 1207);
	REQUIRE(i1.getHeight() == 1280);
}

TEST_CASE("void save(const std::string& filename)"){
	image i1;
	i1.load("../pics/shrek_rectangular.pgm");
	image i2 = i1;
	i2.save("../pics/shrek_rectangular_save.pgm");
}

TEST_CASE("image& operator=(const image& lhs)"){
	image i1;
	i1.load("../pics/shrek_rectangular.pgm");
	image i2 = i1;

	REQUIRE(i2.getWidth() == 1207);
	REQUIRE(i2.getHeight() == 1280);
}

TEST_CASE("image& operator=(image&& rhs)"){
	image i1;
	i1.load("../pics/shrek_rectangular.pgm");
	image i2 = std::move(i1);

	REQUIRE(i1.getWidth() == 0);
	REQUIRE(i1.getHeight() == 0);

	REQUIRE(i2.getWidth() == 1207);
	REQUIRE(i2.getHeight() == 1280);
}

TEST_CASE("image operator+(const image& rhs);"){
	image i1, i2;
	i1.load("../pics/shrek_rectangular.pgm");
	i2.load("../pics/donkey_mask.pgm");
}
