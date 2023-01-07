#ifndef CAR_H_
#define CAR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


enum car_transmission {
	AUTOMATIC,
	MANUAL
};

/*
* H�r �r Strukt som inneh�ller bilens Information.
*/
struct car
{
	const char* brand;
	const char* model;
	const char* color;
	unsigned int year_of_launch;
	enum car_transmission transmission;

	void (*change_color)(struct car*, char* new_colour);
	void (*change_transmission)(struct car*);
	void (*print)(struct car*, FILE* ostream);
};

/*
* H�r �r en funktion som inleder varje bil.
*/
void car_init(struct car* Self, char* brand, char* model, char* color, unsigned int year_of_launch, enum car_transmission transmission);


/*
* Funktion som L�ger till en ny Bil
*/
struct car* car_new(char* brand, char* model, char* color, unsigned int year_of_launch, enum car_transmission transmission);


/*
* Funktion som radera �nskad bil.
*/
void car_delete(struct car** Self);


/*
* Funktion som tar bort allt text
*/
void car_clear(struct car* Self);


/*
* Funktion som skriver ut inneh�llet f�r varje bil.
*/
void car_print(struct car* Self, FILE* ostream);


/*
* Funktion som �ndrar f�rg p� bilen.
*/
void car_change_color(struct car* Self, char* new_color);


/*
* Funktion som �ndra mellan manuell och automat v�xell�da p� bilen.
*/
void car_change_transmission(struct car* Self);


/*
* Funktion som l�ser text dockumenten ut i terminalen.
*/
void file_read(const char* filepath);

#endif /* CAR_H_ */