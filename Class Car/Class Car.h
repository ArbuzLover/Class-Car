#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <vector>
#include<fstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <sstream>
using namespace std;

class Car
{
private:
	string marka;
	string model;
	string color;
	int year;
	int power;
	int speed;

public:
	Car(string, string, string, int, int, int);
	void SetCarColor(string);
	void Vivod();
	void Vivod_map();
};
Car::Car(string _marka, string _model, string _color, int _year, int _power, int _speed)
{

	map<string, vector<string>> CarMap;
	ifstream marka_File("marka_lst.txt");
	ifstream model_File("model_lst.txt");

	string marka_;
	while (getline(marka_File, marka_)) {
		string model_txt;
		if (getline(model_File, model_txt)) {
			istringstream iss(model_txt); // из библиотеки sstream, нужно для записи всех строк из файла в строки 
			string model_;
			vector<string> models;

			// Чтение моделей из строки
			while (iss >> model_) {
				models.push_back(model_);
			}

			// Добавление в словарь
			CarMap[marka_] = models;
		}
	}

	marka_File.close();
	model_File.close();

	auto marka_find = CarMap.find(_marka);
	if (marka_find != CarMap.end())
	{
		marka = _marka;
		auto vect_model = marka_find->second;
		auto model_find = find(vect_model.begin(), vect_model.end(), _model);
		if (model_find != vect_model.end())
		{
			model = _model;
		}
		else 
		{
			model = _model + "(такой модели нету в файле)";
		}

	}
	else
	{
		marka = _marka + "(такой марки нету в файле)";
		model = _model + "(Ну раз нету марки, то точно нету модели)";

	}


	string color_lst[] = { "Чёрный", "Белый", "Красный", "Синий", "Зелёный", "Жёлтый", "Серый" };
	for (size_t i = 0; i < size(color_lst); i++)
	{
		if (_color == color_lst[i])
		{
			color = _color;
			break;
		}
		else
		{ 
			color = "(New)" + _color; 
		}
	}
	if (_year > 1980 && _year < 2025)
	{
		year = _year;
	}
	else { year = 0; }


	if (_power > 60 && _power < 800)
	{
		power = _power;
	}
	else { power = 0; }


	if (_speed > 90 && _speed < 250)
	{
		speed = _speed;
	}
	else { speed = 0; }
}



void Car::SetCarColor(string col)
{
	color = col;
}
void Car::Vivod()
{
	cout << marka << " " << model << " " << color << " " << year << " " << power << " " << speed << endl;
}
