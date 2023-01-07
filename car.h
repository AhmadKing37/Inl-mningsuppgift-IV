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
* Här är Strukt som innehåller bilens Information.
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
* Här är en funktion som inleder varje bil.
*/
void car_init(struct car* Self, char* brand, char* model, char* color, unsigned int year_of_launch, enum car_transmission transmission);


/*
* Funktion som Läger till en ny Bil
*/
struct car* car_new(char* brand, char* model, char* color, unsigned int year_of_launch, enum car_transmission transmission);


/*
* Funktion som radera önskad bil.
*/
void car_delete(struct car** Self);


/*
* Funktion som tar bort allt text
*/
void car_clear(struct car* Self);


/*
* Funktion som skriver ut innehållet för varje bil.
*/
void car_print(struct car* Self, FILE* ostream);


/*
* Funktion som ändrar färg på bilen.
*/
void car_change_color(struct car* Self, char* new_color);


/*
* Funktion som ändra mellan manuell och automat växellåda på bilen.
*/
void car_change_transmission(struct car* Self);


/*
* Funktion som läser text dockumenten ut i terminalen.
*/
void file_read(const char* filepath);

#endif /* CAR_H_ */