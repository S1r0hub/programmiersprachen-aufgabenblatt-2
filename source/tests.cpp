#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

#include <iostream>

using namespace std;

TEST_CASE("teste vec2", "[vec2]")
{
	SECTION("Initialisierungstest")
	{
		Vec2 v;				// lege leeren Vektor an
		Vec2 v2{5,4};		// lege Vektor mit x = 5 und y = 4 an
		REQUIRE(v.x == 0);
		REQUIRE(v.y == 0);
		REQUIRE(v2.x == 5);
		REQUIRE(v2.y == 4);
	}

	SECTION("Berechnungstest +=")
	{
		Vec2 v;
		Vec2 v2{10,20};
		
		Vec2 vErg{10,20};	// Ergebnisvektor
		v += v2;

		REQUIRE(v.x == vErg.x);
		REQUIRE(v.y == vErg.y);
	}

	SECTION("Berechnungstest -=")
	{
		Vec2 v{10,20};
		Vec2 v2{10,20};
		
		Vec2 vErg{0,0};	// Ergebnisvektor
		v -= v2;

		REQUIRE(v.x == vErg.x);
		REQUIRE(v.y == vErg.y);
	}

	SECTION("Berechnungstest *=")
	{
		Vec2 v{2,0.5};
		Vec2 vErg{20,5};	// Ergebnisvektor

		v *= 10;

		REQUIRE(v.x == vErg.x);
		REQUIRE(v.y == vErg.y);
	}

	SECTION("Berechnungstest /=")
	{
		Vec2 v{100,50};
		Vec2 vErg{10,5};	// Ergebnisvektor

		v /= 10;

		REQUIRE(v.x == vErg.x);
		REQUIRE(v.y == vErg.y);
	}
}

int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}
