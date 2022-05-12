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
		default: cout << "�� ������ �� �������. ������ ����� ��� ����������? " << endl;
			flag = exitORnot();
		}
	}
	return flag;
}
void showWorkersAdmin(vector<Worker> v)// ���������� ���������� � ���������(���,�����,����,������) � �-���� ��������������
{
	int k = 0;
	system("cls");
	cout << "    || C��������� � �������� �������� ||" << endl;
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i).access == 0) {
			cout << "��� " << i + 1 << "-�� ������������: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
			cout << "�����: " << v.at(i).login << endl;
			cout << "����: " << v.at(i).role << endl;
			cout << "������: ������\n" << endl;
			k++;
		}
	}
	if (k == 0)cout << "����������� � �������� �������� ���!" << endl;
	cout << endl;
	cout << endl;
	cout << "    || C��������� � �������� �������� ||" << endl;
	cout << endl;
	k = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i).access == 1) {
			cout << "��� " << i + 1 << "-�� ������������: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
			cout << "�����: " << v.at(i).login << endl;
			cout << "����: " << v.at(i).role << endl;
			cout << "������: ������\n" << endl;
			k++;
		}
	}
	if (k == 0)cout << "����������� � �������� �������� ���!" << endl;
	cout << endl;
	cout << endl;
}
void showWorkerAdmin(vector<Worker> v, int i)// ���������� ���������� � ����������(���,�����,����,������) � �-���� ��������������
{
	cout << "��� " << i + 1 << "-�� ������������: " << v.at(i).fio.surname << " " << v.at(i).fio.name << " " << v.at(i).fio.patronymic << endl;
	cout << "�����: " << v.at(i).login << endl;
	cout << "����: " << v.at(i).role << endl;
	cout << "������: ";
	if (v.at(i).access == 0)
		cout << "������" << endl;
	else cout << "������" << endl;
	cout << endl;
	cout << endl;
}
void registrationAdmin(vector<Worker>& v)// �-��� ��� ����������� ������ ���������� ��������������� (������������ � ���� ��������������)
{
	system("cls");
	Worker temp;
	bool flag = true;
	temp.role = chooseRole();
	cout << "���������� �����(�� ����� 8-�� ��������): ";
	while (flag) {
		temp.login = imagenLogin();
		flag = checkIndividuality(v, temp.login);
	}
	regPassword(v, temp);
	temp.gender = getGender();
	cout << "�������: ";
	temp.fio.surname = checkLine();
	cout << "���: ";
	temp.fio.name = checkLine();
	cout << "��������: ";
	temp.fio.patronymic = checkLine();
	cout << endl;
	cout << "���� �������� " << endl;
	temp.birth.day = checkDay();
	temp.birth.month = checkMonth();
	temp.birth.year = checkYear();
	cout << "������ (1-������,0-������): ";
	int input;
	do {
		cin >> input;
		if (input != 1 && input != 0) cout << "�� ������ �� �������. 1 - �������, 0 - ������� " << endl;
	} while (input != 1 && input != 0);
	temp.access = input;
	regEmployee(v, temp);
	v.push_back(temp);

}
void del(vector<Worker>& v, int index)//�-��� ��� �������� ������������ ���������
{
	system("cls");
	showWorkersAdmin(v);
	cout << "������� ����� ����, ���� ������ �������: ";
	int index_delete = checkInput();
	if (index == index_delete) cout << "������������� �� ����� ������� ����" << endl;
	else {
		index_delete--;
		if (index_delete<0 || index_delete>v.size()) cout << "\n������ ���������� �� ����������!\n" << endl;
		else
		{
			v.erase(v.begin() + index_delete);
			cout << "\n�������� ������ �������!\n" << endl;
		}
	}
}
void confirmOrBlock(vector<Worker>& v, int index)//�-��� ��������/���������� ������� ������������ � ���� ��������������
{
	int in, k;
	bool flag = true;
	do {
		system("cls");
		cout << "| ����� ���������� �� ������ ��� ������� - 1 |     | ������� ���� ����������� - ����� ����� 1|    >> ";
		in = checkInput();
		if (in == 1) {
			findCoreAdmin(v, k, index);
			if (k == 0) {
				cout << "�� ������ �� �����. ������ ���������� ��� �����?" << endl;
				flag = exitORnot();
			}
			else flag = false;
		}
		else { showWorkersAdmin(v); flag = false; }
	} while (flag);
	int ind;
	cout << "\n\n������� ����� ����, ��� ������ �� ������ ��������: ";
	ind = checkInput();
	ind--;
	if (ind > v.size() || ind < 0) cout << "�� ������ �� �������" << endl;
	else if (ind == index)cout << "�� �� ������ �������� ������ ������ ����!" << endl;
	else {
		system("cls");
		showWorkerAdmin(v, ind);
		access(v, ind);
	}
	system("pause");
}
void access(vector<Worker>& v, int index)// �-��� ��� ��������� ������� ������������ � confirm_or_block(vector<Worker>& v)
{
	int input;
	cout << "������ ������� ������������ ";
	if (v.at(index).access == 0) {
		cout << "������" << endl;
		cout << endl;
		cout << "������ ������� ������? ���� ��,�� ������� 1 " << endl;
		cin >> input;
		if (input == 1) {
			v.at(index).access = 1;
			cout << "������ ������" << endl;
		}
		else cout << "������ ������� �������" << endl;
	}
	else {
		cout << "������" << endl;
		cout << endl;
		cout << "������ ������� ������? ���� ��,�� ������� 0" << endl;
		cin >> input;
		if (input == 0) {
			v.at(index).access = 0;
			cout << "������ ������" << endl;
		}
		else cout << "������ ������� �������" << endl;
	}
}
void findCoreAdmin(vector<Worker>v, int& k, int index) // ���� ������ ��������������
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
		default: cout << "�� ������ �� �������. ������ ����� � ���� ��� ����������?" << endl;
			flag = exitORnot();
		}
	} while (flag);
}
void regAdmin(vector<Worker>& v, Worker& temp) // ��������� �-��� registration(vector<Worker> v) � ������������ � ����� ��������������
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