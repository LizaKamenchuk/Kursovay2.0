#pragma once
#include "Main.h"
#include"Employee.h"

// ���� ����������
bool coreForChief(vector<Worker>& v, int index);
//���������� ���������� � ���������� (���,�����,����,����) � �-���� ����������
void showWorkersChief(vector<Worker> v);
//���������� ���������� � ��������� (���,�����,����,������,����) � �-���� ����������
void showWorkerChief(vector<Worker> v, int i);
// ��������� �-��� registration(vector<Worker> v) � ������������ � ����� ����������
void regChief(vector<Worker>& v, Worker& temp);
// �-��� ���������/���������� ����������(���������,�����,���� ������ ������) � ���������� ��� ����������
void updateForChief(vector<Worker>& v);
//���������� �������� ����������
int getAge(vector<Worker> v, int i);
//g�������� �������
void showAge(int age);
// ���� ������ ����������
void findCoreChief(vector<Worker>v, int& k, int index);
// ���� ���������� ����������
void sortCoreChief(vector<Worker>& v);
// ���������� ����������� �� �����
void sortWorkExperience(vector<Worker>& v);
// ������� ����������� ����������� ���������
void showRetiree(vector<Worker> v);
