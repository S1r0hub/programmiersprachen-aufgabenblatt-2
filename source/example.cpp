#include "window.hpp"
#include <utility>
#include <cmath>

// Tests Aufgaben 2.11, 2.12
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"

// AUfgabe 2.13
#include <vector>

int main(int argc, char* argv[])
{
  // Aufgabe 2.13
  // define Circles
  Circle c1{0.2,0.8,0.1, Color{0.0,1.0,0.0}};
  Circle c2{0.8,0.8,0.1, Color{1.0,0.5,1.0}};
  std::vector<Circle> circles {c1,c2};

  // define Rectangles
  Rectangle r1{0.25,0.1,0.5,0.2, Color{1.0,0.0,0.0}};
  Rectangle r2{0.45,0.4,0.1,0.3, Color{0.0,1.0,1.0}};
  std::vector<Rectangle> rectangles {r1,r2};

  rectangles.push_back(r1);
  rectangles.push_back(r2);

  // Window setup
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.is_key_pressed(GLFW_KEY_ESCAPE)) {
      win.close();
    }

    /*
    auto t = win.get_time();
    float x1{0.5f + 0.5f * std::sin(t)};
    float y1{0.5f + 0.5f * std::cos(t)};

    float x2{0.5f + 0.5f * std::sin(2.0f*t)};
    float y2{0.5f + 0.5f * std::cos(2.0f*t)};

    float x3{0.5f + 0.5f * std::sin(t-10.f)};
    float y3{0.5f + 0.5f * std::cos(t-10.f)};

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);
    */

    auto m = win.mouse_position();
    //win.draw_line(0.1f, 0.1f, 0.8f,0.1f, 1.0,0.0,0.0);

    win.draw_line(0.0f, m.second, 0.01f, m.second, 0.0, 0.0, 0.0);
    win.draw_line(0.99f, m.second,1.0f, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0.0f, m.first, 0.01f, 1.0, 0.0, 0.0);
    win.draw_line(m.first, 0.99f,m.first, 1.0f, 1.0, 0.0, 0.0);

// Tests Aufgaben 2.11, 2.12 ------------>

    // Kreis zeichnen
    //Circle circ{0.5,0.5,0.1};
    //circ.draw(win, false);

    // Kreis mit bestimmter Farbe zeichnen
    //Circle circ{0.5,0.5,0.1};
    //circ.draw(win, Color{1,0.2,0.2}, false);

    // Rechteck zeichnen
    //Rectangle rect{0.2,0.2,0.6,0.2};
    //rect.draw(win, false);

    // Rechteck mit bestimmter Farbe zeichen
    //Rectangle rect{0.2,0.2,0.6,0.2};
    //rect.draw(win, Color{0.5,0.5,1}, false);

// <-------- END Tests Aufgaben 2.11, 2.12


// Tests Aufgabe 2.13 ------------>

    bool fillObjects = false;

    for (unsigned int i = 0; i < circles.size(); ++i) {
    	if (circles[i].is_inside(m.first,m.second)) {
    		circles[i].draw(win, Color{0.0,0.0,1.0}, fillObjects);
    	}
    	else {
    		circles[i].draw(win, fillObjects);
    	}
    }

    for (unsigned int i = 0; i < rectangles.size(); ++i) {
    	if (rectangles[i].is_inside(m.first,m.second)) {
    		rectangles[i].draw(win, Color{0.0,0.0,1.0}, fillObjects);
    	}
    	else {
    		rectangles[i].draw(win, fillObjects);
    	}
    }

// <-------- END Tests Aufgabe 2.13

    win.update();
  }

  return 0;
}
