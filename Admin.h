#pragma once
#include"Main.h"
#include"Employee.h"

// ���� ��������������
bool coreForAdmin(vector<Worker>& v, int index);
// ���������� ���������� � ���������(���,�����,����,������) � �-���� ��������������
void showWorkersAdmin(vector<Worker> v);
// ���������� ���������� � ����������(���,�����,����,������) � �-���� ��������������
void showWorkerAdmin(vector<Worker> v, int i);
// �-��� ��� ����������� ������ ���������� ��������������� (������������ � ���� ��������������)
void registrationAdmin(vector<Worker>& v);
// ��������� �-��� registration(vector<Worker> v) � ������������ � ����� ��������������
void regAdmin(vector<Worker>& v, Worker& temp);
//�-��� ��� �������� ������������ ���������
void del(vector<Worker>& v, int index);
//�-��� ��������/���������� ������� ������������ � ���� ��������������
void confirmOrBlock(vector<Worker>& v, int index);
// �-��� ��� ��������� ������� ������������ � confirm_or_block(vector<Worker>& v)
void access(vector<Worker>& v, int index);
// ���� ������ ��������������
void findCoreAdmin(vector<Worker>v, int& k, int index);