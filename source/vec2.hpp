#ifndef VEC2_HPP
#define VEC2_HPP

class Vec2
{
	public:
		Vec2() : x(0), y(0) {};
		Vec2(float x, float y) : x(x), y(y) {};

		Vec2& operator+=(Vec2 const& v);
		Vec2& operator-=(Vec2 const& v);
		Vec2& operator*=(float v);
		Vec2& operator/=(float v);
		
		float x;
		float y;
};

// Freie Funktionen

Vec2 operator+(Vec2 const& u, Vec2 const& v);
Vec2 operator-(Vec2 const& u, Vec2 const& v);
Vec2 operator*(Vec2 const& v, float s);
Vec2 operator/(Vec2 const& v, float s);
Vec2 operator*(float s, Vec2 const& v);

/*
Zu 2.2:

Destruktor ist eine Funktion,
welche aufgerufen wird, sobald das Objekt,
welches auf dieser Klasse erstellt wurde, zertört/gelöscht wird!
Wenn man die Funktion manuell erstellen will,
muss man lediglich das Zeichen "~" vor den Klassennamen schreiben.
(Zum Beispiel: ~vec2();)

Die Klasse vec2 benötigt keinen Destruktor,
da dieser, wenn nicht von Benutzer angelegt,
durch den Compiler automatisch angelegt wird.

Desweiteren benötigt man nur einen Destruktor,
wenn man zum Beispiel beim Löschen des Objektes
eine Aktion ausführen will.
(Beispiel: std::cout << "Wurde gelöscht" << std::endl;)

*/

#endif