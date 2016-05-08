#define _USE_MATH_DEFINES
#include "window.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include <utility>
#include <cmath>
#include <iostream>

using namespace std;


void drawComponents(Window const& w, int sec, int min, int secTotal);


int main(int argc, char* argv[])
{
	Window w{std::make_pair(800,800)};

	// show "tick" "tack" in console?
	bool showTickTack = false;
	
	int secTotal, winTime, winTimeBefore, minutes;

	// default start settings
	winTime = winTimeBefore = secTotal = minutes = 0;

	// example starting with specific time
	/*
	secTotal = 6*(60*60);		// set start hours like: 9*(60*60), for 9 o-clock
	minutes = 15;				// set the minutes from 0 to 59
	secTotal += minutes * 60;
	winTime = winTimeBefore = 0;
	*/

	while (!w.should_close()) {
		if (w.is_key_pressed(GLFW_KEY_ESCAPE)) {
			w.close();
		}

		winTime = w.get_time();
		
		if (winTime > 0 && winTime != winTimeBefore) {
			if (showTickTack) { cout << ((winTime % 2 == 0) ? ">> Tack" : ">> Tick") << endl; }
			winTimeBefore = winTime;
			secTotal += 1;

			if (winTime % 60 == 0) {
				if (minutes < 60) { minutes += 1; }
				else {
					minutes = 0;
					//hours = ( (hours < 60) ? (hours + 1) : (0) );
				}
			}
		}

		// draw components
		drawComponents(w, winTime, minutes, secTotal);

		// update the frame
		w.update();
	}

	return 0;
}


void drawComponents(Window const& w, int sec, int min, int secTotal)
{
	float center = 0.5f;
	float radius = 0.4f;
	float innerRadius = 0.01f;
	float secLength = 0.8f;
	float minLength = 0.65f;
	float hourLength = 0.5f;		// how long is the hour line in percentage of the radius
	float hourLineLength = 0.05f;	// length of the hour line on the outer circle
	float minLineLength = 0.025f;
	Color c{0,0,0};					// min, hour - line color, default color
	Color hourColor{0.8,0.0,0.0};	// hour line color

	// center circle
	Circle cC{center,center,innerRadius};
	cC.draw(w,false);

	// main Circle of the clock
	Circle cMain{center,center,0.4};
	cMain.draw(w,false);

	// outline Circle
	Circle olC{center,center,0.45};
	olC.draw(w,false);
	Circle olC2{center,center,0.46};
	olC2.draw(w,false);

	// make time lines
	for (int i = 0; i < 60; ++i) {
		float length = ( (i % 5 == 0) ? hourLineLength : minLineLength );
		float cPos = ((float) i / (float) 60) * 2 * M_PI;
		w.draw_line(center + (float) (radius * cos(cPos)),
					center + (float) (radius * sin(cPos)),
					center + (float) ((radius-length) * cos(cPos)),
					center + (float) ((radius-length) * sin(cPos)),
					c.r,c.g,c.b);
	}

	// draw sec line
	// * -1 , in Uhrzeigersinn rotieren, PI/2 damit bei 12 Uhr gestartet wird
	float rad = (M_PI/2.0f) + (((float) sec / 60.0f) * 2 * M_PI * -1);
	w.draw_line(center + (float) (innerRadius * cos(rad)),
				center + (float) (innerRadius * sin(rad)),
				center + (float) (secLength * radius * cos(rad)),
				center + (float) (secLength * radius * sin(rad)),
				c.r, c.g, c.b);

	// draw min line
	rad = (M_PI/2.0f) + (((float) min / 60.0f) * 2 * M_PI * -1);
	w.draw_line(center + (float) (innerRadius * cos(rad)),
				center + (float) (innerRadius * sin(rad)),
				center + (float) (minLength * radius * cos(rad)),
				center + (float) (minLength * radius * sin(rad)),
				c.r, c.g, c.b);

	// draw hour line
	// 60 sec * 60 min * 12 hours => 43200 seconds for 12 hours
	rad = (M_PI/2.0f) + (((float) secTotal / 43200.0f) * 2 * M_PI * -1);
	w.draw_line(center + (float) (innerRadius * cos(rad)),
				center + (float) (innerRadius * sin(rad)),
				center + (float) (hourLength * radius * cos(rad)),
				center + (float) (hourLength * radius * sin(rad)),
				hourColor.r, hourColor.g, hourColor.b);
}