#define CATCH_CONFIG_RUNNER
#include "vec2.hpp"
#include "mat2.hpp"
#include <catch.hpp>

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

TEST_CASE("2x2 Matrixtest","[mat2]")
{
	SECTION("Default-Konstruktor-Test")
	{
		Mat2 m;
		REQUIRE(m.matrix[0][0] == 1);
		REQUIRE(m.matrix[0][1] == 0);
		REQUIRE(m.matrix[1][0] == 0);
		REQUIRE(m.matrix[1][1] == 1);
	}

	SECTION("User-Konstruktor-Test")
	{
		Mat2 m{1,2,3,4};
		REQUIRE(m.matrix[0][0] == 1);
		REQUIRE(m.matrix[0][1] == 2);
		REQUIRE(m.matrix[1][0] == 3);
		REQUIRE(m.matrix[1][1] == 4);

		// negative Zahlen

		m = Mat2{-10,13,-15,19};
		REQUIRE(m.matrix[0][0] == -10);
		REQUIRE(m.matrix[0][1] == 13);
		REQUIRE(m.matrix[1][0] == -15);
		REQUIRE(m.matrix[1][1] == 19);
	}

	SECTION("Multiplikation-Gleich-Test")
	{
		Mat2 m{5,10,15,20};
		m *= Mat2{1,2,3,4};

		REQUIRE(m.matrix[0][0] == 35);
		REQUIRE(m.matrix[0][1] == 50);
		REQUIRE(m.matrix[1][0] == 75);
		REQUIRE(m.matrix[1][1] == 110);
	
		m = Mat2{5,2,10,4};
		m *= Mat2{2,5,5,2};

		REQUIRE(m.matrix[0][0] == 20);
		REQUIRE(m.matrix[0][1] == 29);
		REQUIRE(m.matrix[1][0] == 40);
		REQUIRE(m.matrix[1][1] == 58);

		// negative Zahlen

		m = Mat2{-5,5,10,-10};
		m *= Mat2{2,-2,-2,2};

		REQUIRE(m.matrix[0][0] == -20);
		REQUIRE(m.matrix[0][1] == 20);
		REQUIRE(m.matrix[1][0] == 40);
		REQUIRE(m.matrix[1][1] == -40);
	}

	SECTION("Multiplikation-Test")
	{
		Mat2 m1{6,5,4,2};
		Mat2 m2{2,5,1,3};
		Mat2 mRes = m1 * m2;

		REQUIRE(mRes.matrix[0][0] == 17);
		REQUIRE(mRes.matrix[0][1] == 45);
		REQUIRE(mRes.matrix[1][0] == 10);
		REQUIRE(mRes.matrix[1][1] == 26);

		// negative Zahlen

		m1 = Mat2{0,1,-1,2};
		m2 = Mat2{1,-2,0,5};
		mRes = m1 * m2;

		REQUIRE(mRes.matrix[0][0] == 0);
		REQUIRE(mRes.matrix[0][1] == 5);
		REQUIRE(mRes.matrix[1][0] == -1);
		REQUIRE(mRes.matrix[1][1] == 12);		
	}

	SECTION("Matrix *= Vektor-Test")	
	{
		Mat2 m = Mat2{5,5,2,1};
		Vec2 vRes = (m * Vec2{4,1});

		REQUIRE(vRes.x == 25);
		REQUIRE(vRes.y == 9);

		// negative Zahlen

		m = Mat2{5,5,2,-1};
		vRes = (m * Vec2{-4,1});

		REQUIRE(vRes.x == -15);
		REQUIRE(vRes.y == -9);
	}

	SECTION("Matrix * Vektor-Test")
	{
		Mat2 m = Mat2{5,10,2,5};
		Vec2 vRes = (m * Vec2{1,1});

		REQUIRE(vRes.x == 15);
		REQUIRE(vRes.y == 7);

		m = Mat2{1.5,0.5,1.5,2.5};
		vRes = (m * Vec2{1,1});

		REQUIRE(vRes.x == 2);
		REQUIRE(vRes.y == 4);

		// negative Zahlen

		m = Mat2{-2,1,0,5};
		vRes = (m * Vec2{1,-2});

		REQUIRE(vRes.x == -4);
		REQUIRE(vRes.y == -10);
	}

	SECTION("Determinante-Test")
	{
		Mat2 m{5,2,2,4};
		REQUIRE(Mat2Det(m) == 16);

		m = Mat2{3,5,2,1};
		REQUIRE(Mat2Det(m) == -7);

		// negative Zahlen

		m = Mat2{-1,5,-3,2};
		REQUIRE(Mat2Det(m) == 13);

		m = Mat2{0,-0.5,-1,3};
		REQUIRE(Mat2Det(m) == Approx(-0.5));
	}

	SECTION("Inverse-Test")	// TODO: FEHLERHAFT
	{
		Mat2 m{5,4,3,2};
		Mat2 inv = Mat2Inv(m);
		REQUIRE(inv.matrix[0][0] == -1);
		REQUIRE(inv.matrix[0][1] == 2);
		REQUIRE(inv.matrix[1][0] == 1.5);
		REQUIRE(inv.matrix[1][1] == -2.5);

		m = Mat2{8,4,2,0};
		inv = Mat2Inv(m);
		REQUIRE(inv.matrix[0][0] == 0);
		REQUIRE(inv.matrix[0][1] == 0.5);
		REQUIRE(inv.matrix[1][0] == 0.25);
		REQUIRE(inv.matrix[1][1] == -1);

		// negative Zahlen

		m = Mat2{-2,4,0,6};
		inv = Mat2Inv(m);
		REQUIRE(inv.matrix[0][0] == -0.5);
		REQUIRE(inv.matrix[0][1] == Approx(0.333333));
		REQUIRE(inv.matrix[1][0] == 0);
		REQUIRE(inv.matrix[1][1] == Approx(0.166666));
	}
}

int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}
