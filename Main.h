#pragma once
#include<stdio.h>
#include<fstream>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include<ctime>
#include"validation.h"
#include "menu.h"


//��������� ���
struct FIO {
	string surname;
	string name;
	string patronymic;
};
//��������� ����
struct Date {
	int day;
	int month;
	int year;
};
//��������� ���������
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

//�������� ����
void core(vector<Worker>& v);

//(�-��� ��� ������ ����) ������� ���� 
string chooseRole();
//(�-��� ��� ������ ����) ������� ���
string getGender();


//��������� ���������� �� ����� � ������
void readWorkersFromFile(vector<Worker>& v);
//���������� ���������� �� ������� � ����
void writeWorkersInFile(vector<Worker>v);

//�-��� ��� ���������� �����
void getWorkExperience(vector<Worker>& v, int i);
//���������� ���� ����������
void showWorkExperience(vector<Worker>v, int i);

//�-��� ����������� ������������(���������� ������ ������������ � �������)
int authorization(vector<Worker> v);
// �-��� "�����" (������������ ��������� �� ������� ����)
void entrance(vector<Worker>& v);

//�-��� "������������������" (�������� ������ �������� ������� Worker)
void registration(vector<Worker>& v);
//�������� ������ ��� �����������
void regPassword(vector<Worker>& v, Worker& temp);


// ����� ���������� �� �������
void findSurname(vector<Worker>v, int& k, int index);
// ����� ���������� �� ������
void findLogin(vector<Worker>v, int& k);
//����� ���������� �� ������
void findDepartment(vector<Worker>v, int& k);


// c������ ���-�� ����� � �����(������ �������)
int getStucturesInFile();
//�������� ������������ ������
bool checkIndividuality(vector<Worker> v, string log);
//�-��� ����/����� (���������� boll)
bool exitORnot();
