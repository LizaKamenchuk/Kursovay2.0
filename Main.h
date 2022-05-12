#pragma once
#include<stdio.h>
#include<fstream>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include<ctime>
#include"validation.h"
#include "menu.h"


//структура фио
struct FIO {
	string surname;
	string name;
	string patronymic;
};
//структора дата
struct Date {
	int day;
	int month;
	int year;
};
//структура сотрудник
struct Worker {
	string login;
	string role;
	string password;
	string salt;
	string gender;
	int access;
	FIO fio;
	Date birth;
	string department;
	string position;
	Date start_work;
	Date work_experience;
};

const string FILE_WORKERS = "Data.txt";

//основное меню
void core(vector<Worker>& v);

//(ф-ци€ дл€ выбора роли) передаЄт роль 
string chooseRole();
//(ф-ци€ дл€ выбора пола) передаЄь пол
string getGender();


//считывает информацию из файла в вектор
void readWorkersFromFile(vector<Worker>& v);
//записывает информацию из вектора в файл
void writeWorkersInFile(vector<Worker>v);

//ф-ци€ дл€ вычислени€ стажа
void getWorkExperience(vector<Worker>& v, int i);
//показывает стаж сотрудника
void showWorkExperience(vector<Worker>v, int i);

//ф-ци€ авторизации пользовател€(возвращает индекс пользовател€ в векторе)
int authorization(vector<Worker> v);
// ф-ци€ "¬ќ…“»" (обеспечивает навигацию по ролевым меню)
void entrance(vector<Worker>& v);

//ф-ци€ "«ј–≈√»—“–»–ќ¬ј“№—я" (создание нового элемента вектора Worker)
void registration(vector<Worker>& v);
//создание парол€ при регистрации
void regPassword(vector<Worker>& v, Worker& temp);


// поиск сотрудника по фамилии
void findSurname(vector<Worker>v, int& k, int index);
// поиск сотрудника по логину
void findLogin(vector<Worker>v, int& k);
//поиск сотрудника по отделу
void findDepartment(vector<Worker>v, int& k);


// cчитает кол-во строк в файле(размер вектора)
int getStucturesInFile();
//проверка уникальности логина
bool checkIndividuality(vector<Worker> v, string log);
//ф-ци€ вход/выход (возвращает boll)
bool exitORnot();
