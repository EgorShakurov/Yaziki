﻿#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;


int main() {


	setlocale(LC_ALL, "RU");


	ifstream fin("C:\\Users\\mayonezss\\Downloads\\file.txt"); //вставьте ваш путь
	if (!fin.is_open()) {
		cout << "Ошибка" << endl;
		return 1;
	}
	string s;
	ofstream fout("C:\\Users\\mayonezss\\Downloads\\res.txt"); //вставьте ваш путь
	while (getline(fin, s)) {
		fout << stoi(s) * 2 << endl;
	}
	fin.close();
	fout.close();
	return 0;
}