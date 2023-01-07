#include "car.h"
/*
main: Här skapas en struckt till en bil med följande information:
	  -Brand
	  -Model
	  -Colour
	  -Year_of_launch
	  -Transmission
*/
int main(void)
{
	/*
	Antalet bilar som läggs i en array
	*/
	struct car car1, car2, car3;
	struct car* cars[] = { &car1, &car2, &car3 };

	/*
	Förklarar lite om varje Bil
	*/
	car_init(&car1, "Volvo", "V70", "Black", 1995, MANUAL);
	car_init(&car2, "BMW", "Z3", "Blue", 2001, AUTOMATIC);
	car_init(&car3, "Skoda", "Octavia RS", "White", 2003, MANUAL);

	/*
	Här öppnas en textfil till Bilen
	*/
	FILE* ostream = fopen("cars.txt", "a");

	
	for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++)
	{
		car_print(cars[i], ostream);

	}

	/* 
	Här ändras Bil 3 färg samt växellåda, och ett text document läggs till.
	*/
	car3.change_color(&car3, "Red"); // Ändrar bilens färg till röd.
	car3.change_transmission(&car3); // Ändrar bilens växellåda.
	car3.print(&car3, ostream);
	fclose(ostream);

	/*
	Här läses textfilen av och skriver ut i terminalen
	*/
	file_read("cars.txt");

	return 0;
}