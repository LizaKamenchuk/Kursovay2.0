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
		default: cout << "�� ������ �� �������. ������ ����� ��� ����������? " << endl;
			flag = exitORnot();
		}
	}
	return flag;
}
void regEmployee(vector<Worker>& v, Worker& temp) // ��������� �-��� registration(vector<Worker> v) � ������������ � ����� ����������
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
void showWorkerHim(vector<Worker> v, int i)// ���������� ��������� ���������� � �� (���,�����,������,���� ��������) � �-���� ��� ��������������
{
	system("cls");
	cout << "1 - ��� : " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "2 - �����: " << v.at(i).login << endl;
	cout << "3 - ������: " << " ********    (���������� �������� � ������ ����� �� ��������� � ���������� ����������� ��������)" << endl;
	cout << "4 - ���� ��������: " << v[i].birth.day << "." << v[i].birth.month << "." << v[i].birth.year << endl;
	cout << "5 - ���: " << v[i].gender << endl;
	cout << endl;
	cout << endl;
}
void seeHimself(vector<Worker> v, int i) // ��������� ��������� ���������� � ��(���,�����,���� ��������,���������,���� ������)
{
	system("cls");
	cout << "��� : " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "�����: " << v.at(i).login << endl;
	cout << "���� ��������: " << v[i].birth.day << "." << v[i].birth.month << "." << v[i].birth.year << endl;
	cout << "���������: " << v[i].position << " ������ " << v[i].department << endl;
	if (v.at(i).start_work.day == 0) cout << "���� ������ ������ �� ���������!";
	else
	{
		showWorkExperience(v, i);
	}
	cout << endl;
	cout << endl;
}
void updateHimself(vector<Worker>& v, int index) // �-��� �������������� ������ ���������� (���,�����,������,���� ��������)
{
	system("cls");
	int input;
	bool flag = true;
	while (flag)
	{
		showWorkerHim(v, index);
		cout << "�������� ����� ���������� �� ������ �������������    >> ";
		input = checkInput();
		cout << endl;
		switch (input) {
		case 1:
			cout << " �������: ";
			v[index].fio.surname = checkString();
			cout << " ���: ";
			v[index].fio.name = checkString();
			cout << " ��������: ";
			v[index].fio.patronymic = checkString();
			break;
		case 2:cout << "�����: ";
			while (flag) {
				v[index].login = imagenLogin();
				flag = checkIndividuality(v, v[index].login);
			}
			break;
		case 3: updatePassword(v, index);
			break;
		case 4:cout << "���� �������� " << endl;
			v[index].birth.day = checkDay();
			v[index].birth.month = checkMonth();
			v[index].birth.year = checkYear();
			break;
		case 5: v[index].gender = getGender();
			break;
		default:cout << "�� ������ �� �������!" << endl;
		}
		cout << endl;
		cout << "���������� ������������� ��� ����� � ������� ����" << endl;
		flag = exitORnot();
		system("cls");
	}
}
void updatePassword(vector<Worker>& v, int index)// �-��� ��� ��������� ������
{
	string pass, pass1, salt;
	bool flag = true, flag1 = true;
	int k = 3, h = 3, s;
	do {
		system("cls");
		s = seeORnot();
		cout << "������� ������ ������: ";
		pass = checkPassword(s);
		if (hashPassword(pass, v.at(index).salt) == v.at(index).password) {
			do {
				cout << "������� ����� ������: ";
				pass = imagenPassword();
				s = seeORnot();
				cout << "\n����������� ������: ";
				pass1 = checkPassword(s);
				if (pass == pass1) {
					salt = generateSalt();
					pass = hashPassword(v[index].password, v[index].salt);
					cout << "������ ������!" << endl;
					flag = false;
					flag1 = false;
				}
				else {
					h--;
					if (h == 0) {
						cout << "������� �����������( ������ �� ������" << endl;
						flag = false;
						flag1 = false;
					}
					else {
						cout << "������ �� ���������!\n������ ���������� ��������� ��� �����?(�������� " << h << " �������)" << endl;
						flag = exitORnot();
						if (flag == false) flag1 = false;
					}
				}
			} while (flag);
		}
		else {
			k--;
			if (k == 0) {
				cout << "������� �����������(" << endl;
				flag1 = false;
			}
			else {
				cout << "�� ����� ������������ ������(\n������ ����������� ����� ��� �����?(�������� " << k << " �������)" << endl;
				flag1 = exitORnot();
			}
		}
	} while (flag1);
}