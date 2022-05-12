#pragma once
#include<string>
#include<iostream>
#include<conio.h>
#include"sha256.h"
using namespace std;

//�������� ����� ���� int (���������� ����� ���� int)
int checkInput();
//�������� ����� ������ 
int checkDay();
//�������� ������ 
int checkMonth();
//�������� ����
int checkYear();
//�-��� ��� �������� ������ (���������� ����� ���� string)
string imagenLogin();
// �������� ��o�� ������(��������� ����� � ������� "@", "-", "_", ".")
string checkLogin();
//����� ����� ������ ��� ����� ��� ���
int seeORnot();
//�-��� ��� ����� ������ (���������� ������ ���� string)
string checkPassword(int v);
// �-��� ��� �������� ������ (���������� ������ ���� string)
string imagenPassword();
// �������� ��� ����� ��� (���������� string)
string checkString();
//�������� ����� ������� ����
string checkLine();
// ������� ��������� ����
string generateSalt(); 
// ������� ������������ ������ ��������
string getSymbolsForSalt(); 
//�-��� �������� ������������� ������
string hashPassword(string& password, string salt);