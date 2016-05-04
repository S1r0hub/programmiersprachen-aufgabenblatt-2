#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

// AUFGABE 2.2
/*
	INCLUDE GUARDS

Verhindern die Mehrfacheinbindung von Header-Dateien.
Fehler tritt auf, wenn in einerm Programm eine
Header-Datei mehrfach eingebunden wird.

Loesung des Problems mit sog. Praeprozessor-Makros!
(#ifndef... #define... #endif)
-> dadurch definiert und wird nicht erneut geladen.
*/

#include <iostream>
using namespace std;

TEST_CASE("teste vec2 Memberfunktionen", "[vec2Member]")
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
	
		// negative Zahlen

		Vec2 v3{-10,-5};
		Vec2 v4{10,-5};
		Vec2 vErg2{0,-10};

		v3 += v4;

		REQUIRE(v3.x == vErg2.x);
		REQUIRE(v3.y == vErg2.y);
	}

	SECTION("Berechnungstest -=")
	{
		Vec2 v{10,20};
		Vec2 v2{10,20};
		Vec2 vErg{0,0};	// Ergebnisvektor

		v -= v2;

		REQUIRE(v.x == vErg.x);
		REQUIRE(v.y == vErg.y);

		// negative Zahlen

		Vec2 v3{10,-20};
		Vec2 v4{-10,20};
		Vec2 vErg2{20,-40};

		v3 -= v4;

		REQUIRE(v3.x == vErg2.x);
		REQUIRE(v3.y == vErg2.y);
	}

	SECTION("Berechnungstest *=")
	{
		Vec2 v{2,0.5};
		Vec2 vErg{20,5};	// Ergebnisvektor

		v *= 10;

		REQUIRE(v.x == vErg.x);
		REQUIRE(v.y == vErg.y);
	
		// negative Zahlen

		Vec2 v2{-5,6};
		Vec2 vErg2{25,-30};	// Ergebnisvektor

		v2 *= -5;

		REQUIRE(v2.x == vErg2.x);
		REQUIRE(v2.y == vErg2.y);
	}

	SECTION("Berechnungstest /=")
	{
		Vec2 v{100,50};
		Vec2 vErg{10,5};	// Ergebnisvektor

		v /= 10;

		REQUIRE(v.x == vErg.x);
		REQUIRE(v.y == vErg.y);

		// negative Zahlen

		Vec2 v2{-10,20};
		Vec2 vErg2{5,-10};	// Ergebnisvektor

		v2 /= -2;

		REQUIRE(v2.x == vErg2.x);
		REQUIRE(v2.y == vErg2.y);
	}
}

TEST_CASE("teste vec2 freie Funktionen", "[vec2Free]")
{
	SECTION("Berechnungstest +")
	{
		Vec2 v{10,15};
		Vec2 v2{30,25};
		Vec2 vErg{40,40};

		Vec2 vRes = v + v2;
		
		REQUIRE(vRes.x == vErg.x);
		REQUIRE(vRes.y == vErg.y);

		// negative Zahlen

		Vec2 v3{-10,-20};
		Vec2 v4{-5,5};
		Vec2 vErg2{-15,-15};
		vRes = v3 + v4;

		REQUIRE(vRes.x == vErg2.x);
		REQUIRE(vRes.y == vErg2.y);
	}

	SECTION("Berechnungstest -")
	{
		Vec2 v{10,50};
		Vec2 v2{30,25};
		Vec2 vErg{-20,25};

		Vec2 vRes = v - v2;

		REQUIRE(vRes.x == vErg.x);
		REQUIRE(vRes.y == vErg.y);

		// negative Zahlen

		Vec2 v3{-10,-5};
		Vec2 v4{-5,-5};
		Vec2 vErg2{-5,0};

		vRes = v3 - v4;

		REQUIRE(vRes.x == vErg2.x);
		REQUIRE(vRes.y == vErg2.y);
	}

	SECTION("Berechnungstest * (1)")
	{
		Vec2 v{10,15};
		Vec2 vErg{100,150};

		Vec2 vRes = v * 10;

		REQUIRE(vRes.x == vErg.x);
		REQUIRE(vRes.y == vErg.y);

		// negative Zahlen

		Vec2 v3{-10,-5};
		Vec2 vErg2{-20,-10};

		vRes = v3 * 2;

		REQUIRE(vRes.x == vErg2.x);
		REQUIRE(vRes.y == vErg2.y);
	}

	SECTION("Berechnungstest /")
	{
		Vec2 v{10,15};
		Vec2 vErg{100,150};

		Vec2 vRes = v * 10;

		REQUIRE(vRes.x == vErg.x);
		REQUIRE(vRes.y == vErg.y);

		// negative Zahlen

		Vec2 v3{-10,-5};
		Vec2 vErg2{-20,-10};

		vRes = v3 * 2;

		REQUIRE(vRes.x == vErg2.x);
		REQUIRE(vRes.y == vErg2.y);
	}

	SECTION("Berechnungstest * (2)")
	{
		Vec2 v{10,20};
		Vec2 vErg{50,100};

		Vec2 vRes = 5 * v;

		REQUIRE(vRes.x == vErg.x);
		REQUIRE(vRes.y == vErg.y);

		// negative Zahlen

		Vec2 v3{-5,-10};
		Vec2 vErg2{-15,-30};

		vRes = 3 * v3;

		REQUIRE(vRes.x == vErg2.x);
		REQUIRE(vRes.y == vErg2.y);
	}
}

int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}
