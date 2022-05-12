#include "Admin.h"

bool coreForAdmin(vector<Worker>& v, int index)
{
	int k;
	bool flag = true;
	while (flag)
	{
		system("cls");
		int item = menuForAdmin();
		switch (item)
		{
		case 1:showWorkersAdmin(v);
			system("pause");
			break;
		case 2:registrationAdmin(v);
			break;
		case 3:confirmOrBlock(v, index);
			break;
		case 4:del(v, index);
			system("pause");
			break;
		case 5:findCoreAdmin(v, k, index);
			break;
		case 6:updateHimself(v, index);
			break;
		case 7:showWorkerHim(v, index);
			break;
		case 0: flag = false;
			break;
		default: cout << "Вы ничего не выбрали. Хотите выйти или продолжить? " << endl;
			flag = exitORnot();
		}
	}
	return flag;
}
void showWorkersAdmin(vector<Worker> v)// показывает информацию о работнике(ФИО,логин,роль,доступ) в ф-циях администратора
{
	int k = 0;
	system("cls");
	cout << "    || Cотрудники с ЗАКРЫТЫМ доступом ||" << endl;
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i).access == 0) {
			cout << "ФИО " << i + 1 << "-го пользователя: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
			cout << "Логин: " << v.at(i).login << endl;
			cout << "Роль: " << v.at(i).role << endl;
			cout << "Доступ: закрыт\n" << endl;
			k++;
		}
	}
	if (k == 0)cout << "Сотрудников с закрытым доступом нет!" << endl;
	cout << endl;
	cout << endl;
	cout << "    || Cотрудники с ОТКРЫТЫМ доступом ||" << endl;
	cout << endl;
	k = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i).access == 1) {
			cout << "ФИО " << i + 1 << "-го пользователя: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
			cout << "Логин: " << v.at(i).login << endl;
			cout << "Роль: " << v.at(i).role << endl;
			cout << "Доступ: открыт\n" << endl;
			k++;
		}
	}
	if (k == 0)cout << "Сотрудников с открытым доступом нет!" << endl;
	cout << endl;
	cout << endl;
}
void showWorkerAdmin(vector<Worker> v, int i)// показывает информацию о работниках(ФИО,логин,роль,доступ) в ф-циях администратора
{
	cout << "ФИО " << i + 1 << "-го пользователя: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "Логин: " << v.at(i).login << endl;
	cout << "Роль: " << v.at(i).role << endl;
	cout << "Доступ: ";
	if (v.at(i).access == 0)
		cout << "закрыт" << endl;
	else cout << "открыт" << endl;
	cout << endl;
	cout << endl;
}
void registrationAdmin(vector<Worker>& v)// ф-ция для регистрации нового сотрудника администратором (используется в меню администратора)
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
	temp.fio.surname = checkLine();
	cout << "Имя: ";
	temp.fio.name = checkLine();
	cout << "Отчество: ";
	temp.fio.patronymic = checkLine();
	cout << endl;
	cout << "Дата рождения " << endl;
	temp.birth.day = checkDay();
	temp.birth.month = checkMonth();
	temp.birth.year = checkYear();
	cout << "Доступ (1-открыт,0-закрыт): ";
	int input;
	do {
		cin >> input;
		if (input != 1 && input != 0) cout << "Вы ничего не выбрали. 1 - открыть, 0 - закрыть " << endl;
	} while (input != 1 && input != 0);
	temp.access = input;
	regEmployee(v, temp);
	v.push_back(temp);

}
void del(vector<Worker>& v, int index)//ф-ция для удаления определённого работника
{
	system("cls");
	showWorkersAdmin(v);
	cout << "Введите номер того, кого хотите удалить: ";
	int index_delete = checkInput();
	if (index == index_delete) cout << "Администратор не может удалить себя" << endl;
	else {
		index_delete--;
		if (index_delete<0 || index_delete>v.size()) cout << "\nТакого сотрудника не существует!\n" << endl;
		else
		{
			v.erase(v.begin() + index_delete);
			cout << "\nУдаление прошло успешно!\n" << endl;
		}
	}
}
void confirmOrBlock(vector<Worker>& v, int index)//ф-ция открытия/блокировки доступа используется в меню администратора
{
	int in, k;
	bool flag = true;
	do {
		system("cls");
		cout << "| Найти сотрудника по логину или фамилии - 1 |     | Увидеть всех сотрудников - число кроме 1|    >> ";
		in = checkInput();
		if (in == 1) {
			findCoreAdmin(v, k, index);
			if (k == 0) {
				cout << "Вы никого не нашли. Хотите продолжить или выйти?" << endl;
				flag = exitORnot();
			}
			else flag = false;
		}
		else { showWorkersAdmin(v); flag = false; }
	} while (flag);
	int ind;
	cout << "\n\nВведите номер того, чей доступ вы хотите изменить: ";
	ind = checkInput();
	ind--;
	if (ind > v.size() || ind < 0) cout << "Вы никого не выбрали" << endl;
	else if (ind == index)cout << "Вы не можете изменить доступ самому себе!" << endl;
	else {
		system("cls");
		showWorkerAdmin(v, ind);
		access(v, ind);
	}
	system("pause");
}
void access(vector<Worker>& v, int index)// ф-ция для изменения доступа испрльзуется в confirm_or_block(vector<Worker>& v)
{
	int input;
	cout << "Доступ данного пользователя ";
	if (v.at(index).access == 0) {
		cout << "закрыт" << endl;
		cout << endl;
		cout << "Хотите открыть доступ? Если да,то нажмите 1 " << endl;
		cin >> input;
		if (input == 1) {
			v.at(index).access = 1;
			cout << "Доступ открыт" << endl;
		}
		else cout << "Доступ остался прежним" << endl;
	}
	else {
		cout << "открыт" << endl;
		cout << endl;
		cout << "Хотите закрыть доступ? Если да,то нажмите 0" << endl;
		cin >> input;
		if (input == 0) {
			v.at(index).access = 0;
			cout << "Доступ закрыт" << endl;
		}
		else cout << "Доступ остался прежним" << endl;
	}
}
void findCoreAdmin(vector<Worker>v, int& k, int index) // меню поиска администратора
{
	system("cls");
	bool flag = true;
	int a;
	do {
		a = findMenuAdmin();
		cout << endl;
		switch (a) {
		case 1: findSurname(v, k, index);
			flag = false;
			break;
		case 2:findLogin(v, k);
			flag = false;
			break;
		case 0:flag = false;
			break;
		default: cout << "Вы ничего не выбрали. Хотите выйти в меню или продолжить?" << endl;
			flag = exitORnot();
		}
	} while (flag);
}
void regAdmin(vector<Worker>& v, Worker& temp) // дополняет ф-цию registration(vector<Worker> v) в соответствие с ролью администратора
{
	SYSTEMTIME t;
	GetLocalTime(&t);
	temp.position = temp.role;
	temp.department = "---";
	temp.start_work.day = 0;
	temp.start_work.month = 0;
	temp.start_work.year = 0;
	temp.work_experience.day = t.wDay;
	temp.work_experience.month = t.wMonth;
	temp.work_experience.year = t.wYear;

}