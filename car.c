#include "car.h"

void car_init(struct car* Self, char* brand, char* model, char* color, unsigned int year_of_launch, enum car_transmission transmission)
{
	Self->brand = brand;
	Self->model = model;
	Self->color = color;
	Self->year_of_launch = year_of_launch;
	Self->transmission = transmission;

	Self->change_color = car_change_color;
	Self->change_transmission = car_change_transmission;
	Self->print = car_print;
}

void car_clear(struct car* Self)
{
	Self->brand = 0;
	Self->model = 0;
	Self->color = 0;
	Self->year_of_launch = 0;
	Self->transmission = AUTOMATIC;
}


void car_delete(struct car** Self)
{
	
	if (*Self == NULL)
	{
		return;
	}

	free(*Self);

	*Self = NULL;
	return;
}


struct car* car_new(char* brand, char* model, char* color, unsigned int year_of_launch, enum car_transmission transmission)
{
	struct car* Self = malloc(sizeof(struct car));

	if (!Self) return 0;

	car_init(Self, brand, model, color, year_of_launch, transmission);

	return Self;
}


void car_print(struct car* Self, FILE* ostream)
{
	if (!ostream) ostream = stdout;

	fprintf(ostream, "--------------------------------------------------------------------------------\n");
	fprintf(ostream, "Brand: %s\n", Self->brand);
	fprintf(ostream, "Model: %s\n", Self->model);
	fprintf(ostream, "Color: %s\n", Self->color);
	fprintf(ostream, "Year of Launch: %u\n", Self->year_of_launch);
	if (Self->transmission == 1) {

		fprintf(ostream, "Transmission: MANUAL\n");
	}

	else if (Self->transmission == 0) {

		fprintf(ostream, "Transmission: AUTOMATIC\n");
	}
	fprintf(ostream, "--------------------------------------------------------------------------------\n\n");
}


static void car_change_transmission(struct car* Self)
{
	if (Self->transmission == AUTOMATIC) {
		Self->transmission = MANUAL;
	}
	else {
		Self->transmission = AUTOMATIC;
	}
}


static void car_change_color(struct car* Self, char* new_color)
{
	Self->color = new_color;
}


void file_read(const char* filepath)
{
	FILE* f = fopen(filepath, "r");
	if (!f) return;
	char s[100] = { '\0' };

	while (fgets(s, sizeof(s), f))
	{
		printf("%s", s);
	}

	fclose(f);
	return;
}