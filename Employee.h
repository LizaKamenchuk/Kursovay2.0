#pragma once
#include "Main.h"

// ���� ����������
bool coreForEmployee(vector<Worker>& v, int index);
// ���������� ��������� ���������� � �� (���,�����,������,���� ��������) � �-���� ��� ��������������
void showWorkerHim(vector<Worker> v, int i);
// ��������� ��������� ���������� � ��(���,�����,���� ��������,���������,���� ������)
void seeHimself(vector<Worker> v, int i);
// ��������� �-��� registration(vector<Worker> v) � ������������ � ����� ����������
void regEmployee(vector<Worker>& v, Worker& temp);
// �-��� �������������� ������ ���������� (���,�����,������,���� ��������)
void updateHimself(vector<Worker>& v, int index);
// �-��� ��� ��������� ������
void updatePassword(vector<Worker>& v, int index);
