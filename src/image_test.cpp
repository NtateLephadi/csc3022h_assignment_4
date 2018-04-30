#define CATCH_CONFIG_MAIN
#include "image.h"

TEST_CASE( "image()" ){
	image i = image();

	REQUIRE(i.getWidth() == 0);
	REQUIRE(i.getHeight() == 0);
	REQUIRE(i.getData() == nullptr);
}

TEST_CASE("image(int width, int height, unsigned char* data)"){
	unsigned char hold[] = "abcd";
	unsigned char* holder = &hold[0];
	image i1 = image(2, 2, holder);

	REQUIRE(i1.getWidth() == 2);
	REQUIRE(i1.getHeight() == 2);

	REQUIRE(i1.getData()[0] == 'a');
	REQUIRE(i1.getData()[1] == 'b');
	REQUIRE(i1.getData()[2] == 'c');
	REQUIRE(i1.getData()[3] == 'd');

}

TEST_CASE("image(const image& rhs);"){

	image i1;
	i1.load("../pics/test.pgm");

	image i2(i1);

	REQUIRE(i2.getWidth() == 2);
	REQUIRE(i2.getHeight() == 2);
	REQUIRE(i2.getData()[0] == 'a');
	REQUIRE(i2.getData()[1] == 'b');
	REQUIRE(i2.getData()[2] == 'c');
	REQUIRE(i2.getData()[3] == 'd');

}

TEST_CASE("image(image&& rhs)"){

	image i1;
	i1.load("../pics/test.pgm");

	image i2 = std::move(i1);

	REQUIRE(i2.getWidth() == 2);
	REQUIRE(i2.getHeight() == 2);

	REQUIRE(i1.getWidth() == 0);
	REQUIRE(i1.getHeight() == 0);
}

TEST_CASE("void load(const std::string& filename)"){
	image i1;
	i1.load("../pics/test.pgm");

	REQUIRE(i1.getWidth() == 2);
	REQUIRE(i1.getHeight() == 2);

	REQUIRE(i1.getData()[0] == 'a');
	REQUIRE(i1.getData()[1] == 'b');
	REQUIRE(i1.getData()[2] == 'c');
	REQUIRE(i1.getData()[3] == 'd');

}

TEST_CASE("void save(const std::string& filename)"){
	image i1;
	i1.load("../pics/shrek_rectangular.pgm");
	image i2 = i1;
	i2.save("../pics/shrek_rectangular_save.pgm");
}

TEST_CASE("image& operator=(const image& rhs)"){
	image i1;
	i1.load("../pics/test.pgm");
	image i2 = i1;

	REQUIRE(i2.getWidth() == 2);
	REQUIRE(i2.getHeight() == 2);

	REQUIRE(i2.getData()[0] == 'a');
	REQUIRE(i2.getData()[1] == 'b');
	REQUIRE(i2.getData()[2] == 'c');
	REQUIRE(i2.getData()[3] == 'd');
}

TEST_CASE("image& operator=(image&& rhs)"){
	image i1;
	i1.load("../pics/test.pgm");
	image i2 = std::move(i1);

	REQUIRE(i1.getWidth() == 0);
	REQUIRE(i1.getHeight() == 0);

	REQUIRE(i2.getWidth() == 2);
	REQUIRE(i2.getHeight() == 2);

}

TEST_CASE("image operator+(const image& rhs);"){
	image i1, i2;
	i1.load("../pics/test.pgm");
	i2.load("../pics/test_1.pgm");

	REQUIRE((i1 + i2).getData()[0] == 'a' + 'e');
	REQUIRE((i1 + i2).getData()[1] == 'b' + 'f');
	REQUIRE((i1 + i2).getData()[2] == 'c' + 'g');
	REQUIRE((i1 + i2).getData()[3] == 'd' + 'h');
}

TEST_CASE("image operator-(const image& rhs);"){
	image i1, i2;
	i1.load("../pics/test.pgm");
	i2.load("../pics/test_1.pgm");

	REQUIRE((i2 - i1).getData()[0] == 'e' - 'a');
	REQUIRE((i2 - i1).getData()[1] == 'f' - 'b');
	REQUIRE((i2 - i1).getData()[2] == 'g' - 'c');
	REQUIRE((i2 - i1).getData()[3] == 'h' - 'd');
}

TEST_CASE("image operator/(const image& rhs)"){
	image i1, i2;
	i1.load("../pics/test.pgm");
	i2.load("../pics/test_1.pgm");

	REQUIRE((i2 / i1).getData()[0] == 0);
	REQUIRE((i2 / i1).getData()[1] == 0);
	REQUIRE((i2 / i1).getData()[2] == 0);
	REQUIRE((i2 / i1).getData()[3] == 0);
}

TEST_CASE("image operator!()"){
	image i1;
	i1.load("../pics/test.pgm");
	REQUIRE((!(i1)).getData()[0] == 255 - 'a');
	REQUIRE((!(i1)).getData()[1] == 255 - 'b');
	REQUIRE((!(i1)).getData()[2] == 255 - 'c');
	REQUIRE((!(i1)).getData()[3] == 255 - 'd');
}

TEST_CASE("image operator*(const int& threshold)"){
	image i1;
	i1.load("../pics/test.pgm");
	REQUIRE((i1 * 100).getData()[0] == 0);
	REQUIRE((i1 * 100).getData()[1] == 0);
	REQUIRE((i1 * 100).getData()[2] == 0);
	REQUIRE((i1 * 100).getData()[3] == 0);
}
