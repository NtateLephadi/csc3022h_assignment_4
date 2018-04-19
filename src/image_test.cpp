#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "image.h"
#include <memory>

using namespace std;


TEST_CASE( "image default constructor", "[image()]" ){
	image i1 = image();
	REQUIRE(i1.getHeight() == 0);
	REQUIRE(i1.getWidth() == 0);
}