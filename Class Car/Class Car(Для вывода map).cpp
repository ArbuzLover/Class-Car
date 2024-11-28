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
int main1() // для запуска убрать 1 и в конце ретурн
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
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

	for (const auto& entry : CarMap) {
		cout << "Марка: " << entry.first << "| Модели: ";
		for (const auto& model : entry.second) {
			cout << model << " ";
		}
		cout << endl;
	}
	return 0;
}