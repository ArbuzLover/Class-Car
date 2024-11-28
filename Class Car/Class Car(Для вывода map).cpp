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
int main1() // ��� ������� ������ 1 � � ����� ������
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
			istringstream iss(model_txt); // �� ���������� sstream, ����� ��� ������ ���� ����� �� ����� � ������ 
			string model_;
			vector<string> models;

			// ������ ������� �� ������
			while (iss >> model_) {
				models.push_back(model_);
			}

			// ���������� � �������
			CarMap[marka_] = models;
		}
	}

	marka_File.close();
	model_File.close();

	for (const auto& entry : CarMap) {
		cout << "�����: " << entry.first << "| ������: ";
		for (const auto& model : entry.second) {
			cout << model << " ";
		}
		cout << endl;
	}
	return 0;
}