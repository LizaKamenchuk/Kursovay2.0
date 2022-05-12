#include"Admin.h"
#include"Chief.h"

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	vector<Worker> v;
	n = getStucturesInFile()+1;
	v.reserve(n);

	readWorkersFromFile(v);
    core(v);
	writeWorkersInFile(v);
}

void core(vector<Worker>& v) { 
	int input;
	bool flag = true;

	while (flag)
	{
		system("cls");
		input = menu();
		switch (input)
		{
		case 1:entrance(v);
			break;
		case 2:registration(v);
			exitORnot();
			break;
		case 0:flag = false;
			break;
		default: cout << "Вы ничего не выбрали. Хотите выйти или продолжить? " << endl;
			flag = exitORnot();
		}
	}
}

string chooseRole()  //(ф-ция для выбора роли) передаёт роль 
{
	int rol;
	string role;
	cout << "Выберите роль: 1 - администратор, 2 - cотрудник, 3 - начальник " << endl;
	do {
		cout << "Введите: ";
	    rol = checkInput();
		if (rol != 2 && rol != 1 && rol != 3) cout << "Введите 1, или 2, или 3" << endl;
	} while (rol != 2 && rol != 1 && rol != 3);
	if (rol == 1)role = "администратор";
	if (rol == 2)role = "сотрудник";
	if (rol == 3)role = "начальник";
	cout << endl;
	return role;
}
string getGender(){
	int g;
	string gender;
	cout << "Ваш пол: 1 - женщина    2 - мужчина  " << endl;
	do {
		cout << "Введите: ";
		g = checkInput();
	} while (g != 2 && g != 1);
	if (g == 1) gender = "женщина";
	if (g == 2) gender = "мужчина";
	cout << endl;
	return gender;
}

void readWorkersFromFile(vector<Worker>& v)//считывает информацию из файла в вектор
{
	int i = 0;
	ifstream fin(FILE_WORKERS, ios::in);
	if (!fin.is_open())
	{
		Worker temp;
		temp.login = "admin_admin";
		temp.role = "администратор";
		temp.gender = "---";
		temp.salt = generateSalt();
		temp.password = "1";
		temp.password =	hashPassword(temp.password, temp.salt);
		temp.access = 1;
		temp.fio.surname = "--- "; temp.fio.name = " --- "; temp.fio.patronymic = " ---";
		temp.birth.day = 0; temp.birth.month = 0; temp.birth.year = 0;
		temp.position = temp.role; temp.department = " ---";
		temp.start_work.day = 0; temp.start_work.month = 0; temp.start_work.year = 0;
		temp.work_experience.day = 0; temp.work_experience.month = 0; temp.work_experience.month = 0;
		v.push_back(temp);
		writeWorkersInFile(v);
	}

	else
	{
		while (!fin.eof())
		{
			Worker temp;
			fin >> temp.login;
			fin >> temp.role;
			fin >> temp.gender;
			fin >> temp.password;
			fin >> temp.salt;
			fin >> temp.access;
			fin >> temp.fio.surname >> temp.fio.name >> temp.fio.patronymic;
			fin >> temp.birth.day >> temp.birth.month >> temp.birth.year;
			fin >> temp.position >> temp.department;
			fin >> temp.start_work.day >> temp.start_work.month >> temp.start_work.year;
			v.push_back(temp);
		}
	}
	fin.close();
}
void writeWorkersInFile(vector<Worker>v)//записывает информацию из вектора в файл
{
	ofstream fout(FILE_WORKERS, ios::out);
	for (int i = 0; i < v.size(); i++)
	{
		fout << v.at(i).login << " "
			<< v.at(i).role << " "
			<< v.at(i).gender << " "
			<< v.at(i).password << " "
			<< v.at(i).salt << " "
			<< v.at(i).access << " "
			<< v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << " "
			<< v.at(i).birth.day << " " << v.at(i).birth.month << " " << v.at(i).birth.year
			<< v.at(i).position << " " << v.at(i).department << " "
			<< v.at(i).start_work.day << " " << v.at(i).start_work.month << " " << v.at(i).start_work.year;

		if (i < v.size() - 1) // не переставляет на новую строку,если это последняя запись
		{
			fout << endl;
		}
	}
	fout.close();
}

void getWorkExperience(vector<Worker>& v, int i) //ф-ция для вычисления стажа используется в меню начальника
{
	SYSTEMTIME t;
	GetLocalTime(&t);
	int check;
	int Month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = t.wDay - v.at(i).start_work.day;
	int mon = t.wMonth - v.at(i).start_work.month;
	int year = t.wYear - v.at(i).start_work.year;
	int mon_num = 0;
	if (mon < 0) {
		check = year * 12 + mon;
		year = check / 12;
		mon = check % 12;
	}
	if (day < 0) {
		mon = mon - 1;
		day = t.wDay + (Month[t.wMonth - 1] - v.at(i).start_work.day);
	}
	v.at(i).work_experience.day = day;
	v.at(i).work_experience.month = mon;
	v.at(i).work_experience.year = year;
}
void showWorkExperience(vector<Worker>v, int i) {
	getWorkExperience(v, i);
	int day = v.at(i).work_experience.day;
	int mon = v.at(i).work_experience.month;
	int year = v.at(i).work_experience.year;

	cout << "Стаж: ";
	if (year % 10 >= 5 || (year % 10 == 0 && year != 0) || (year <= 19 && year >= 11)) cout << year << " лет ";
	else if (year % 10 == 1)cout << year << " год ";
	else if (year % 10 <= 4 && year % 10 >= 2)cout << year << " года ";

	if (mon == 1)cout << mon << " месяц ";
	if (mon <= 4 && mon >= 2) cout << mon << " месяца ";
	if (mon <= 12 && mon >= 5)cout << mon << " месяцев ";

	if (day % 10 >= 5 || (day % 10 == 0 && day != 0) || (day <= 19 && day >= 11)) cout << day << " дней " << endl;
	else if (day % 10 == 1)cout << day << " день" << endl;
	else if (day % 10 <= 4 && day % 10 >= 2)cout << day << " дня " << endl;
}

int authorization(vector<Worker> v)//ф-ция авторизации пользователя(возвращает индекс пользователя в векторе)
{
	string login, pass;
	int index = -1, k = 0;
	int input,s;
	do {
		cout << "Введите ваш логин: ";
		login = checkLogin();
		int s = seeORnot();
		cout << "Введите пароль: ";
		pass = checkPassword(s);
		for (int i = 0; i < v.size(); i++){
			if (login == v.at(i).login && hashPassword(pass, v.at(i).salt) == v.at(i).password)
			{
				index = i;
				k++;
				input = 0;
			}
        }
		if (k == 0)
		{
			cout << "\nВы ввели неверный логин или пароль.\nНажмите 0 - выйти в главное меню. Другую цифру - попробовать снова." << endl;
			input=checkInput();
			system("cls");
		}
	} while (input != 0);
	return index;
}
void entrance(vector<Worker>& v)// ф-ция "ВОЙТИ" (обеспечивает навигацию по ролевым меню) 
{
	system("cls");
	int index = authorization(v);
	bool flag = true;
	if (index == -1) {
		cout << "Вы не авторизовались " << endl; 
		system("pause");
		flag = false;
	}
	system("cls");
	while (flag)
	{
		if (v.at(index).access == 0) {
			cout << "У вас нет доступа. Подождите, пожалуйста, пока администратор открое его" << endl;
			system("pause");
			flag = false;
		}
		else
		{
			if (v.at(index).role == "администратор")
			{
				flag = coreForAdmin(v, index);
			}
			else if (v.at(index).role == "начальник")
			{
				flag = coreForChief(v, index);
			}
			else if (v.at(index).role == "сотрудник")
			{
				flag = coreForEmployee(v, index);
			}
		}
	}
}

void registration(vector<Worker>& v)//ф-ция "ЗАРЕГИСТРИРОВАТЬСЯ" (создание нового элемента вектора Worker)
{
	system("cls");
	Worker temp;
	bool flag = true;
	temp.role = chooseRole();
	cout << "Придумайте логин(не менее 8-ми символов): ";
	while (flag) {
		temp.login = imagenLogin();
		flag = checkIndividuality(v, temp.login);
	}
	regPassword(v, temp);
	temp.gender = getGender();
	cout << "Фамилия: ";
	temp.fio.surname = checkString();
	cout << "Имя: ";
	temp.fio.name = checkString();
	cout << "Отчество: ";
	temp.fio.patronymic = checkString();
	cout << endl;
	cout << "Дата рождения " << endl;
	temp.birth.day = checkDay();
	temp.birth.month = checkMonth();
	temp.birth.year = checkYear();
	cout << endl;
	if (temp.role == "администратор")
	{
		regAdmin(v, temp);
	}
	else if (temp.role == "сотрудник")
	{
		regEmployee(v, temp);
	}
	else if (temp.role == "начальник")
	{
		regChief(v, temp);
    }
	temp.access = 0;
	v.push_back(temp);
	cout << "Ваши данные записаны, подождите пока администратор открое вам доступ " << endl;
}
void regPassword(vector<Worker>& v, Worker& temp) //создание пароля при регистрации
{
	string pass, pass1;
	int s;
	bool flag = true;
	do {
		cout << "Придумайте пароль: ";
		pass = imagenPassword();
		s = seeORnot();
		cout << "\nПодтвердите пароль: ";
		pass1 = checkPassword(s);
		if (pass == pass1) {
			temp.salt = generateSalt();
			temp.password = hashPassword(pass, temp.salt);
			cout << "Пароль подтверждён!" << endl;
			cout << endl;
			flag = false;
		}
		else {
			cout << "Пароли не совпали( Попробуйте ещё раз" << endl;
			cout << endl;
		}
	} while (flag);
}

void findSurname (vector<Worker>v,int&k,int index)// поиск сотрудника по фамилии 
{
	string surname;
	bool flag = true;
    do{
		int i = 0;
	    k = 0;
		system("cls");
		cout << "Введите фамилию или её начало : ";
		surname = checkString();
		cout << endl;
		for (i = 0; i < v.size(); i++) {
			if (v[i].fio.surname.find(surname) == 0)// поиск строки surname и если она с 0 символа, то true 
			{
				cout << "Номер работника в списке " << i + 1 << endl;
				if (v[index].role == "начальник") showWorkerChief(v, i);
				else showWorkerAdmin(v, i);
				k++;
			}
		}
		if (k != 0) {
			system("pause"); flag = false;
		}
		if (k == 0) {
			cout << "Никого не найдено!" << endl;
			cout << "\nХотите продолжить поиск или выйти в меню?" << endl;
			flag = exitORnot();
		}
	} while (flag);
}
void findLogin(vector<Worker>v,int&k) // поиск сотрудника по логину
{
	string log;
	bool flag = true;

	do {
		k = 0;
		system("cls");
		cout << "Введите логин или его начало : ";
		log = checkLogin();
		cout << endl;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].login.find(log) == 0)// поиск строки log и если она с 0 символа, то true 
			{
				cout << "Номер работника в списке " << i + 1 << endl;
				showWorkerAdmin(v, i);
				k++;
			}
		}
		if (k != 0) {
			system("pause"); flag = false;
		}
		if (k == 0) {
			cout << "Никого не найдено!" << endl;
			cout << "\nХотите продолжить поиск или выйти в меню?" << endl;
			flag = exitORnot();
		}
	} while (flag);
}
void findDepartment(vector<Worker>v,int&k) //поиск сотрудника по отделу
{
	string dep;
	bool flag = true;

	do {
		k = 0;
		system("cls");
		cout << "Введите логин или его начало : ";
		dep = checkLine();
		cout << endl;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].department.find(dep) == 0)// поиск строки log и если она с 0 символа, то true 
			{
				cout << "Номер работника в списке " << i + 1 << endl;
				showWorkerChief(v, i);
				k++;
			}
		}
		if (k != 0)
		{
			system("pause"); flag = false;
		}
		if (k == 0) {
			cout << "Никого не найдено!" << endl;
			cout << "\nХотите продолжить поиск или выйти в меню?" << endl;
			flag = exitORnot();
		}
	} while (flag);
}

int getStucturesInFile() {
	ofstream fadd(FILE_WORKERS, ios::app);
	if (!fadd.is_open()) fadd << "";
	fadd.close();

	ifstream file(FILE_WORKERS, ios::in);
	int number_of_strings = 0;
	if (file.is_open()) {

		while (file.ignore(256, '\n'))
			number_of_strings++;

	}
	file.close();
	return number_of_strings;
}
bool checkIndividuality(vector<Worker> v, string log) //проверка уникальности логина
{
	bool flag = false;
	for (int j = 0; j < v.size(); j++) {
		if (log == v.at(j).login) {
			cout << "Пользователь с таким логином уже существует. Придумайте другой логин: ";
			flag = true;
		}
	}
	return flag;
}
bool exitORnot()//ф-ция вход/выход (возвращает boll)
{
	int num;
	cout << "1 - ПРОДОЛЖИТЬ              0 - ВЫХОД" << endl;
	cout << "Введите 0 или 1: ";
	num = checkInput();
	cout << endl;
	do {
		switch (num)
		{
		case 1:system("cls"); return true;
			break;
		case 0: system("cls"); return false;
			break;
		}
	} while (num != 1 && num != 0);
}