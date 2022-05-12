#include"Employee.h"

bool coreForEmployee(vector<Worker>& v, int index) {
	bool flag = true;
	while (flag)
	{
		system("cls");
		int item = menuForEmployee();
		switch (item)
		{
		case 1:seeHimself(v, index);
			system("pause");
			break;
		case 2:updateHimself(v, index);
			break;
		case 0: flag = false;
			break;
		default: cout << "Вы ничего не выбрали. Хотите выйти или продолжить? " << endl;
			flag = exitORnot();
		}
	}
	return flag;
}
void regEmployee(vector<Worker>& v, Worker& temp) // дополняет ф-цию registration(vector<Worker> v) в соответствие с ролью сотрудника
{
	SYSTEMTIME t;
	GetLocalTime(&t);
	temp.position = "---";
	temp.department = "---";
	temp.start_work.day = 0;
	temp.start_work.month = 0;
	temp.start_work.year = 0;
	temp.work_experience.day = t.wDay;
	temp.work_experience.month = t.wMonth;
	temp.work_experience.year = t.wYear;

}
void showWorkerHim(vector<Worker> v, int i)// показывает работнику информацию о нём (ФИО,логин,пароль,дата рождения) в ф-циях для редактирования
{
	system("cls");
	cout << "1 - ФИО : " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "2 - Логин: " << v.at(i).login << endl;
	cout << "3 - Пароль: " << " ********    (колтчество символов в пароле может не совпадать с выведенным количеством звёздочек)" << endl;
	cout << "4 - Дата рождения: " << v[i].birth.day << "." << v[i].birth.month << "." << v[i].birth.year << endl;
	cout << "5 - Пол: " << v[i].gender << endl;
	cout << endl;
	cout << endl;
}
void seeHimself(vector<Worker> v, int i) // показывае работнику информацию о нём(ФИО,логин,дата рождения,должность,опыт работы)
{
	system("cls");
	cout << "ФИО : " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "Логин: " << v.at(i).login << endl;
	cout << "Дата рождения: " << v[i].birth.day << "." << v[i].birth.month << "." << v[i].birth.year << endl;
	cout << "Должность: " << v[i].position << " отдела " << v[i].department << endl;
	if (v.at(i).start_work.day == 0) cout << "Дата начала работы не заполнена!";
	else
	{
		showWorkExperience(v, i);
	}
	cout << endl;
	cout << endl;
}
void updateHimself(vector<Worker>& v, int index) // ф-ция редактирования личной информации (ФИО,логин,пароль,дата рождения)
{
	system("cls");
	int input;
	bool flag = true;
	while (flag)
	{
		showWorkerHim(v, index);
		cout << "Выберите какую информацию вы хотите редактировать    >> ";
		input = checkInput();
		cout << endl;
		switch (input) {
		case 1:
			cout << " Фамилия: ";
			v[index].fio.surname = checkString();
			cout << " Имя: ";
			v[index].fio.name = checkString();
			cout << " Отчество: ";
			v[index].fio.patronymic = checkString();
			break;
		case 2:cout << "Логин: ";
			while (flag) {
				v[index].login = imagenLogin();
				flag = checkIndividuality(v, v[index].login);
			}
			break;
		case 3: updatePassword(v, index);
			break;
		case 4:cout << "Дата рождения " << endl;
			v[index].birth.day = checkDay();
			v[index].birth.month = checkMonth();
			v[index].birth.year = checkYear();
			break;
		case 5: v[index].gender = getGender();
			break;
		default:cout << "Вы ничего не выбрали!" << endl;
		}
		cout << endl;
		cout << "Продолжить редактировать или Выйти в главное меню" << endl;
		flag = exitORnot();
		system("cls");
	}
}
void updatePassword(vector<Worker>& v, int index)// ф-ция для изменения пароля
{
	string pass, pass1, salt;
	bool flag = true, flag1 = true;
	int k = 3, h = 3, s;
	do {
		system("cls");
		s = seeORnot();
		cout << "Введите старый пароль: ";
		pass = checkPassword(s);
		if (hashPassword(pass, v.at(index).salt) == v.at(index).password) {
			do {
				cout << "Введите новый пароль: ";
				pass = imagenPassword();
				s = seeORnot();
				cout << "\nПодтвердите пароль: ";
				pass1 = checkPassword(s);
				if (pass == pass1) {
					salt = generateSalt();
					pass = hashPassword(v[index].password, v[index].salt);
					cout << "Пароль изменён!" << endl;
					flag = false;
					flag1 = false;
				}
				else {
					h--;
					if (h == 0) {
						cout << "Попытки закончились( Пароль не изменён" << endl;
						flag = false;
						flag1 = false;
					}
					else {
						cout << "Пароли не совпадают!\nХотите продолжить изменение или выйти?(осталось " << h << " попытки)" << endl;
						flag = exitORnot();
						if (flag == false) flag1 = false;
					}
				}
			} while (flag);
		}
		else {
			k--;
			if (k == 0) {
				cout << "Попытки закончились(" << endl;
				flag1 = false;
			}
			else {
				cout << "Вы ввели неправильный пароль(\nХотите попробовать снова или выйти?(осталось " << k << " попытки)" << endl;
				flag1 = exitORnot();
			}
		}
	} while (flag1);
}