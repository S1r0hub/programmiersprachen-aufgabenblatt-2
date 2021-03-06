#define CATCH_CONFIG_RUNNER
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include <catch.hpp>


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
	SECTION("Matrix-Vergleich-Test")
	{
		Mat2 m{0,1,2,3};
		Mat2 m2{0,1,2,3};
		REQUIRE(m.equal(m2) == true);

		m = Mat2{-5,5,-4,2.5};
		m2 = Mat2{-5,5,-4,2.5};
		REQUIRE(m.equal(m2) == true);

		m = Mat2{0,1,-2,3};
		m2 = Mat2{0.001,1,-2,3};
		REQUIRE(m.equal(m2) == false);

		m = Mat2{0,1,-2,3};
		m2 = Mat2{0,2,-2,3};
		REQUIRE(m.equal(m2) == false);

		m = Mat2{0,1,-2,3};
		m2 = Mat2{0,1,0,3};
		REQUIRE(m.equal(m2) == false);

		m = Mat2{0,1,-2,3};
		m2 = Mat2{0,1,-2,3.1};
		REQUIRE(m.equal(m2) == false);
	}

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
		Mat2 correctResult{35,50,75,110};
		m *= Mat2{1,2,3,4};

		REQUIRE(m.equal(correctResult) == true);
	
		m = Mat2{5,2,10,4};
		correctResult = Mat2{20,29,40,58};
		m *= Mat2{2,5,5,2};

		REQUIRE(m.equal(correctResult) == true);

		// negative Zahlen

		m = Mat2{-5,5,10,-10};
		correctResult = Mat2{-20,20,40,-40};
		m *= Mat2{2,-2,-2,2};

		REQUIRE(m.equal(correctResult) == true);
	}

	SECTION("Multiplikation-Test")
	{
		Mat2 m1{6,5,4,2};
		Mat2 m2{2,5,1,3};
		Mat2 correctResult{17,45,10,26};
		Mat2 mRes = m1 * m2;

		REQUIRE(mRes.equal(correctResult) == true);

		// negative Zahlen

		m1 = Mat2{0,1,-1,2};
		m2 = Mat2{1,-2,0,5};
		correctResult = Mat2{0,5,-1,12};
		mRes = m1 * m2;

		REQUIRE(mRes.equal(correctResult));	
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

	SECTION("Vektor * Matrix-Test")
	{
		Mat2 m = Mat2{5,10,2,5};
		Vec2 vRes = (Vec2{1,1} * m);

		REQUIRE(vRes.x == 15);
		REQUIRE(vRes.y == 7);

		m = Mat2{1.5,0.5,1.5,2.5};
		vRes = (Vec2{1,1} * m);

		REQUIRE(vRes.x == 2);
		REQUIRE(vRes.y == 4);

		// negative Zahlen

		m = Mat2{-2,1,0,5};
		vRes = (Vec2{1,-2} * m);

		REQUIRE(vRes.x == -4);
		REQUIRE(vRes.y == -10);
	}

	SECTION("Determinante-Test")
	{
		Mat2 m{5,2,2,4};
		REQUIRE(m.det() == 16);

		m = Mat2{3,5,2,1};
		REQUIRE(m.det() == -7);

		// negative Zahlen

		m = Mat2{-1,5,-3,2};
		REQUIRE(m.det() == 13);

		m = Mat2{0,-0.5,-1,3};
		REQUIRE(m.det() == Approx(-0.5));
	}

	SECTION("Inverse-Test")	// TODO: FEHLERHAFT
	{
		Mat2 inv = inverse(Mat2{5,4,3,2});
		Mat2 correctResult{-1,2,1.5,-2.5};
		REQUIRE(inv.equal(correctResult) == true);

		inv = inverse(Mat2{8,4,2,0});
		correctResult = Mat2{0,0.5,0.25,-1};
		REQUIRE(inv.equal(correctResult) == true);

		// negative Zahlen

		inv = inverse(Mat2{-2,4,0,6});
		REQUIRE(inv.matrix[0][0] == -0.5);
		REQUIRE(inv.matrix[0][1] == Approx(0.333333));
		REQUIRE(inv.matrix[1][0] == 0);
		REQUIRE(inv.matrix[1][1] == Approx(0.166666));
	}

	SECTION("Transponierte-Test")
	{
		Mat2 m = transpose(Mat2{0,5,2,1});
		Mat2 correctResult{0,2,5,1};
		REQUIRE(m.equal(correctResult) == true);

		m = transpose(Mat2{5,-8,7,-6});
		correctResult = Mat2{5,7,-8,-6};
		REQUIRE(m.equal(correctResult) == true);

		m = transpose(Mat2{-4.7,3.8,5,12});
		correctResult = Mat2{-4.7,5,3.8,12};
		REQUIRE(m.equal(correctResult) == true);
	}

	SECTION("Rotationsmatrix-Test")
	{
		Mat2 m = make_rotation_mat2(0.087266); // = 5 Grad * (PI/180)
		REQUIRE(m.matrix[0][0] == Approx(0.996195));
		REQUIRE(m.matrix[0][1] == Approx(-0.087156));
		REQUIRE(m.matrix[1][0] == Approx(0.087156));
		REQUIRE(m.matrix[1][1] == Approx(0.996195));

		Mat2 m2 = make_rotation_mat2(1.5708); // = PI/2 = 90 Grad * (PI/180)
		REQUIRE(m2.matrix[0][0] == Approx(0));
		REQUIRE(m2.matrix[0][1] == Approx(-1));
		REQUIRE(m2.matrix[1][0] == Approx(1));
		REQUIRE(m2.matrix[1][1] == Approx(0));
	}
}

TEST_CASE("Circle-Test","[circle]")
{
	SECTION("Default-Constructor-Circ")
	{
		Circle circ;
		REQUIRE(circ.getPos().x == 0);
		REQUIRE(circ.getPos().y == 0);
		REQUIRE(circ.getRadius() == 0.0);
		REQUIRE(circ.getDiameter() == 0.0);
		REQUIRE(circ.getBBox().x == 0);
		REQUIRE(circ.getBBox().y == 0);
		REQUIRE(circ.getBBox().width == 0.0);
		REQUIRE(circ.getBBox().height == 0.0);
	}

	SECTION("User-Constructor-Circ")
	{
		Circle circ{5,10,6};
		REQUIRE(circ.getPos().x == 5);
		REQUIRE(circ.getPos().y == 10);
		REQUIRE(circ.getRadius() == 6.0);
		REQUIRE(circ.getDiameter() == 12.0);
		REQUIRE(circ.getBBox().x == -1);
		REQUIRE(circ.getBBox().y == 4);
		REQUIRE(circ.getBBox().width == 12.0);
		REQUIRE(circ.getBBox().height == 12.0);
	}

	SECTION("setPos-Test-Circ")
	{
		Circle circ;
		circ.setPos(50,20);
		REQUIRE(circ.getPos().x == 50);
		REQUIRE(circ.getPos().y == 20);

		circ.setPos(-50,-20.5);
		REQUIRE(circ.getPos().x == -50);
		REQUIRE(circ.getPos().y == -20.5);
	}

	SECTION("setRadius-Test-Circ")
	{
		Circle circ;
		circ.setRadius(20);
		REQUIRE(circ.getRadius() == 20);

		circ.setRadius(-50.2);
		REQUIRE(circ.getRadius() == Approx(50.2));
	}

	SECTION("circumference-Test-Circ")
	{
		Circle circ{0,0,2};
		REQUIRE(circ.circumference() == Approx(12.5664));

		circ = Circle{0,0,4.5};
		REQUIRE(circ.circumference() == Approx(28.2743));
	}

	SECTION("is_inside-Test-Circ")
	{
		Circle circ{0,0,2};
		// Kreis mit Radius = 2 -> rechte obere Ecke maximal sqrt(2) = 1.41421
		float PointX = 1.45;
		float PointY = 1.45;
		REQUIRE(circ.is_inside(PointX,PointY) == false);
		REQUIRE(circ.is_inside(-PointX,-PointY) == false);
		REQUIRE(circ.is_inside(-PointX,PointY) == false);

		PointX = 1;
		PointY = 1;
		REQUIRE(circ.is_inside(PointX,PointY) == true);
		REQUIRE(circ.is_inside(-PointX,-PointY) == true);
		REQUIRE(circ.is_inside(PointX,-PointY) == true);
	}
}

TEST_CASE("Rectangle-Test", "[rectangle]")
{
	SECTION("Default-Constructor-Rect")
	{
		Rectangle rect;
		REQUIRE(rect.getPos().x == 0);
		REQUIRE(rect.getPos().y == 0);
		REQUIRE(rect.getWidth() == 0);
		REQUIRE(rect.getHeight() == 0);
		REQUIRE(rect.getDiagonal() == 0);
		REQUIRE(rect.getCircumCircle() == 0);
		REQUIRE(rect.getCenter().x == 0);
		REQUIRE(rect.getCenter().y == 0);
	}

	SECTION("User-Constructor-Rect")
	{
		Rectangle rect{10,20,8,4};
		REQUIRE(rect.getPos().x == 10);
		REQUIRE(rect.getPos().y == 20);
		REQUIRE(rect.getWidth() == 8);
		REQUIRE(rect.getHeight() == 4);
		REQUIRE(rect.getDiagonal() == Approx(8.94427));
		REQUIRE(rect.getCircumCircle() == Approx(4.47214));
		REQUIRE(rect.getCenter().x == 14);
		REQUIRE(rect.getCenter().y == 22);
	}

	SECTION("setPos-Test-Rect")
	{
		Rectangle rect;
		rect.setPos(10,15);
		REQUIRE(rect.getPos().x == 10);
		REQUIRE(rect.getPos().y == 15);

		rect.setPos(-10,20.123);
		REQUIRE(rect.getPos().x == -10);
		REQUIRE(rect.getPos().y == Approx(20.123));
	}

	SECTION("setScale-Test-Rect")
	{
		Rectangle rect;
		rect.setScale(20,40);
		REQUIRE(rect.getWidth() == 20);
		REQUIRE(rect.getHeight() == 40);

		rect.setScale(-10,15.123);
		REQUIRE(rect.getWidth() == 10);
		REQUIRE(rect.getHeight() == Approx(15.123));
	}

	SECTION("circumference-Test-Rect")
	{
		Rectangle rect{0,0,5,5};
		REQUIRE(rect.circumference() == 20);

		rect = Rectangle{0,0,2.5,10};
		REQUIRE(rect.circumference() == 25);
	}

	SECTION("is_inside-Test-Rect")
	{
		Rectangle rect{1,1,5,2};

		REQUIRE(rect.is_inside(3.1,3.1) == false);
		REQUIRE(rect.is_inside(4,0.95) == false);
		REQUIRE(rect.is_inside(6.1,2) == false);
		REQUIRE(rect.is_inside(0.9,2) == false);

		REQUIRE(rect.is_inside(1,2) == true);
		REQUIRE(rect.is_inside(2,3) == true);
		REQUIRE(rect.is_inside(6,2) == true);
		REQUIRE(rect.is_inside(3.5,2) == true);
	}
}

int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}
