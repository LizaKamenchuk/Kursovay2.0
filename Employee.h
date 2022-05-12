#pragma once
#include "Main.h"

// меню сотрудника
bool coreForEmployee(vector<Worker>& v, int index);
// показывает работнику информацию о нём (ФИО,логин,пароль,дата рождения) в ф-циях для редактирования
void showWorkerHim(vector<Worker> v, int i);
// показывае работнику информацию о нём(ФИО,логин,дата рождения,должность,опыт работы)
void seeHimself(vector<Worker> v, int i);
// дополняет ф-цию registration(vector<Worker> v) в соответствие с ролью сотрудника
void regEmployee(vector<Worker>& v, Worker& temp);
// ф-ция редактирования личной информации (ФИО,логин,пароль,дата рождения)
void updateHimself(vector<Worker>& v, int index);
// ф-ция для изменения пароля
void updatePassword(vector<Worker>& v, int index);
