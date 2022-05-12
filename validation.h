#pragma once
#include<string>
#include<iostream>
#include<conio.h>
#include"sha256.h"
using namespace std;

//проверка ввода типа int (возвращает число типа int)
int checkInput();
//проверка числа месяца 
int checkDay();
//проверка месяца 
int checkMonth();
//проверка года
int checkYear();
//ф-ция для создания логина (возвращает логин типа string)
string imagenLogin();
// проверка ввoда логина(латинские буквы и символы "@", "-", "_", ".")
string checkLogin();
//выбор видно пароль при вводе или нет
int seeORnot();
//ф-ция для ввода пароля (возвращает пароль типа string)
string checkPassword(int v);
// ф-ция для создания пароля (возвращает пароль типа string)
string imagenPassword();
// проверка при вводе ФИО (возвращает string)
string checkString();
//проверка ввода русских букв
string checkLine();
// функция генерации соли
string generateSalt(); 
// функция формирования набора символов
string getSymbolsForSalt(); 
//ф-ция создания хэшированного пароля
string hashPassword(string& password, string salt);