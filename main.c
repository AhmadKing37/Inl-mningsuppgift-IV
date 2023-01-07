#include "car.h"
/*
main: H�r skapas en struckt till en bil med f�ljande information:
	  -Brand
	  -Model
	  -Colour
	  -Year_of_launch
	  -Transmission
*/
int main(void)
{
	/*
	Antalet bilar som l�ggs i en array
	*/
	struct car car1, car2, car3;
	struct car* cars[] = { &car1, &car2, &car3 };

	/*
	F�rklarar lite om varje Bil
	*/
	car_init(&car1, "Volvo", "V70", "Black", 1995, MANUAL);
	car_init(&car2, "BMW", "Z3", "Blue", 2001, AUTOMATIC);
	car_init(&car3, "Skoda", "Octavia RS", "White", 2003, MANUAL);

	/*
	H�r �ppnas en textfil till Bilen
	*/
	FILE* ostream = fopen("cars.txt", "a");

	
	for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++)
	{
		car_print(cars[i], ostream);

	}

	/* 
	H�r �ndras Bil 3 f�rg samt v�xell�da, och ett text document l�ggs till.
	*/
	car3.change_color(&car3, "Red"); // �ndrar bilens f�rg till r�d.
	car3.change_transmission(&car3); // �ndrar bilens v�xell�da.
	car3.print(&car3, ostream);
	fclose(ostream);

	/*
	H�r l�ses textfilen av och skriver ut i terminalen
	*/
	file_read("cars.txt");

	return 0;
}