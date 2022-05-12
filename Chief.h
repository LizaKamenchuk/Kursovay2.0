#pragma once
#include "Main.h"
#include"Employee.h"

// меню начальника
bool coreForChief(vector<Worker>& v, int index);
//показывает информацию о работниках (‘»ќ,логин,роль,стаж) в ф-ци€х начальника
void showWorkersChief(vector<Worker> v);
//показывает информацию о работнике (‘»ќ,логин,роль,доступ,стаж) в ф-ци€х начальника
void showWorkerChief(vector<Worker> v, int i);
// дополн€ет ф-цию registration(vector<Worker> v) в соответствие с ролью начальника
void regChief(vector<Worker>& v, Worker& temp);
// ф-ци€ изменени€/дополнени€ информации(должность,отдел,дата начала работы) о работниках дл€ начальника
void updateForChief(vector<Worker>& v);
//возвращает возвраст сотрудника
int getAge(vector<Worker> v, int i);
//gказывает возраст
void showAge(int age);
// меню поиска начальника
void findCoreChief(vector<Worker>v, int& k, int index);
// меню сортировки начальника
void sortCoreChief(vector<Worker>& v);
// сортировка сотрудников по стажу
void sortWorkExperience(vector<Worker>& v);
// вывести сотрудников пенсионного возвраста
void showRetiree(vector<Worker> v);
