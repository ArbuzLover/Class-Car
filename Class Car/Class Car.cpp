#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include "C:\Users\Arbuz\Downloads\Class Car.h"




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Car Lada("Lada", "Kalina", "Белый", 2020, 110, 180);
	Lada.Vivod();
	Lada.SetCarColor("Чорни");
	Lada.Vivod();
	Car Audi("Audi", "A1", "Серый", 2020, 150, 200);
	Audi.Vivod();
	Car BMW("BMW", "Mini", "Серый", 2020, 150, 200);
	BMW.Vivod();
	

}

