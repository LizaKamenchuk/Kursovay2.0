#include"Chief.h"

bool coreForChief(vector<Worker>& v, int index)
{
	int k;
	bool flag = true;
	while (flag)
	{
		system("cls");
		int item = menuForChief();
		switch (item)
		{
		case 1:system("cls");
			showWorkersChief(v);
			system("pause");
			break;
		case 2:updateForChief(v);
			break;
		case 3:showRetiree(v);
			break;
		case 4:findCoreChief(v, k, index);
			break;
		case 5:sortCoreChief(v);
			break;
		case 6: seeHimself(v, index);
			system("pause");
			break;
		case 7:updateHimself(v, index);
			break;
		case 0: flag = false;
			break;
		default: cout << "�� ������ �� �������. ������ ����� ��� ����������? " << endl;
			flag = exitORnot();
		}
	}
	return flag;
}
void showWorkersChief(vector<Worker> v)//���������� ���������� � ���������� (���,�����,����,����) � �-���� ����������
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << "��� " << i + 1 << "-�� ������������: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
		cout << "�����: " << v.at(i).login << endl;
		cout << "���������: " << v.at(i).position << " � ������ " << v.at(i).department << endl;
		if (v.at(i).start_work.day == 0) cout << "���� ������ ������ �� ���������!" << endl;
		else
		{
			showWorkExperience(v, i);
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
void showWorkerChief(vector<Worker> v, int i)//���������� ���������� � ��������� (���,�����,����,������,����) � �-���� ����������
{
	cout << "��� : " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "1 - ���������: " << v.at(i).position << endl;
	cout << "2 - ����� : " << v.at(i).department << endl;
	cout << "3 - ���� ������ ������ : ";
	if (v.at(i).start_work.day == 0) cout << "�� ���������.";
	else
	{
		cout << v.at(i).start_work.day << "." << v.at(i).start_work.month << "." << v.at(i).start_work.year;
	}
	cout << endl;
	cout << endl;
}
void updateForChief(vector<Worker>& v) // �-��� ���������/���������� ����������(���������,�����,���� ������ ������) � ���������� ��� ����������
{
	system("cls");
	int num, numeric = 0;
	bool flag = true;
	showWorkersChief(v);
	cout << "������� ����� ����������, �������� ������ �������������: " << endl;
	num = checkInput() - 1;
	if (num<0 || num>v.size()) cout << "\n������ ���������� �� ����������!\n" << endl;
	else {
		while (flag)
		{
			system("cls");
			showWorkerChief(v, num);
			cout << "������� ����� ����, ��� ������ �������������   >> ";
			numeric = checkInput();
			cout << endl;
			switch (numeric)
			{
			case 1:cout << "���������: ";
				v.at(num).position = checkLine();
				break;
			case 2:cout << "�����: ";
				v.at(num).department = checkLine();
				break;
			case 3:cout << "���� ������ ������ " << endl;
				v.at(num).start_work.day = checkDay();
				v.at(num).start_work.month = checkMonth();
				v.at(num).start_work.year = checkYear();
				break;
			default:cout << "�� ������ �� �������! " << endl;
			}

			cout << endl;
			cout << endl;
			cout << "���������� ������������� ��� ����� � ������� ����" << endl;
			cout << endl;
			flag = exitORnot();
		}
	}
}
int getAge(vector<Worker> v, int i) //���������� �������� ����������
{
	SYSTEMTIME t;
	GetLocalTime(&t);
	int check;
	int mon = t.wMonth - v.at(i).birth.month;
	int age = t.wYear - v.at(i).birth.year;
	if (mon < 0) {
		check = age * 12 + mon;
		age = check / 12;
	}
	return age;
}
void showAge(int age)
{
	if (age % 10 >= 5 || (age % 10 == 0 && age != 0) || (age <= 19 && age >= 11)) cout << age << " ��� ";
	else if (age % 10 == 1)cout << age << " ��� ";
	else if (age % 10 <= 4 && age % 10 >= 2)cout << age << " ���� ";
	cout << endl;
}
void findCoreChief(vector<Worker>v, int& k, int index) // ���� ������ ����������
{
	system("cls");
	bool flag = true;
	int a;
	do {
		a = findMenuChief();
		cout << endl;
		switch (a) {
		case 1: findSurname(v, k, index);
			flag = false;
			break;
		case 2:findDepartment(v, k);
			flag = false;
			break;
		case 0:flag = false;
			break;
		default: {cout << "�� ������ �� �������. ������ ����� � ���� ��� ����������?" << endl;
			flag = exitORnot(); }
		}

	} while (flag);
}
void sortCoreChief(vector<Worker>& v)// ���� ���������� ����������
{
	system("cls");
	bool flag = true;
	int a;
	do {
		a = sortMenuChief();
		cout << endl;
		switch (a) {
		case 1: sortWorkExperience(v);
			showWorkersChief(v);
			system("pause");
			flag = false;
			break;
		case 2:sort(v.begin(), v.end(), [](const Worker& a, const Worker& b) {return a.fio.surname < b.fio.surname; });
			showWorkersChief(v);
			system("pause");
			flag = false;
			break;
		case 0:flag = false;
			break;
		default:cout << "�� ������ �� �������. ������ ����� � ���� ��� ����������?" << endl;
			flag = exitORnot();
		}

	} while (flag);

}
void sortWorkExperience(vector<Worker>& v) // ���������� ����������� �� �����
{
	bool flag = true;
	int a;
	for (int i = 0; i < v.size(); i++) {
		getWorkExperience(v, i);
	}
	do {
		cout << " ������������� �� : 1 -  �������� �����     2 - ����������� �����     >>";
		a = checkInput();
		cout << endl;
		switch (a)
		{
		case 1:cout << "      || C��������� �� �������� ����� || " << endl;
			cout << endl;
			sort(v.begin(), v.end(), [](const Worker& a, const Worker& b) {return a.work_experience.day > b.work_experience.day; });
			sort(v.begin(), v.end(), [](const Worker& a, const Worker& b) { return a.work_experience.month > b.work_experience.month; });
			sort(v.begin(), v.end(), [](const Worker& a, const Worker& b) { return a.work_experience.year > b.work_experience.year; });
			flag = false;
			break;
		case 2:cout << "     || C�������� �� ����������� ����� ||  " << endl;
			cout << endl;
			sort(v.begin(), v.end(), [](const Worker& a, const Worker& b) {return a.work_experience.day < b.work_experience.day; });
			sort(v.begin(), v.end(), [](const Worker& a, const Worker& b) { return a.work_experience.month < b.work_experience.month; });
			sort(v.begin(), v.end(), [](const Worker& a, const Worker& b) { return a.work_experience.year < b.work_experience.year; });
			flag = false;
			break;
		default:cout << "�� ������ �� �������. ������ ����� � ���� ��� ����������?" << endl;
			flag = exitORnot();
			break;
		}
	} while (flag);
}
void showRetiree(vector<Worker> v) // ������� ����������� ����������� ���������
{
	system("cls");
	int age, k = 0;
	cout << "     || C��������� ����������� ��������� ||     " << endl;
	cout << endl;
	for (int i = 0; i < v.size(); i++) {
		age = getAge(v, i);
		if ((v[i].gender == "�������" && age >= 58) || (v[i].gender == "�������" && age >= 63))
		{
			cout << "������� ����������: "; showAge(age);
			showWorkerChief(v, i); k++;
		}
	}
	if (k == 0) cout << "C���������� ���������� ��������� ��� " << endl;;
	system("pause");
}
void regChief(vector<Worker>& v, Worker& temp) // ��������� �-��� registration(vector<Worker> v) � ������������ � ����� ����������
{

	temp.position = temp.role;
	cout << "������� �������� ������: ";
	temp.department = checkLine();
	cout << "���� ������ ������ " << endl;
	temp.start_work.day = checkDay();
	temp.start_work.month = checkMonth();
	temp.start_work.year = checkYear();
	temp.work_experience.day = 0;
	temp.work_experience.month = 0;
	temp.work_experience.year = 0;

}