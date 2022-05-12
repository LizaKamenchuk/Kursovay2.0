#pragma once
#include"Main.h"
#include"Employee.h"

// меню администратора
bool coreForAdmin(vector<Worker>& v, int index);
// показывает информацию о работнике(ФИО,логин,роль,доступ) в ф-циях администратора
void showWorkersAdmin(vector<Worker> v);
// показывает информацию о работниках(ФИО,логин,роль,доступ) в ф-циях администратора
void showWorkerAdmin(vector<Worker> v, int i);
// ф-ция для регистрации нового сотрудника администратором (используется в меню администратора)
void registrationAdmin(vector<Worker>& v);
// дополняет ф-цию registration(vector<Worker> v) в соответствие с ролью администратора
void regAdmin(vector<Worker>& v, Worker& temp);
//ф-ция для удаления определённого работника
void del(vector<Worker>& v, int index);
//ф-ция открытия/блокировки доступа используется в меню администратора
void confirmOrBlock(vector<Worker>& v, int index);
// ф-ция для изменения доступа испрльзуется в confirm_or_block(vector<Worker>& v)
void access(vector<Worker>& v, int index);
// меню поиска администратора
void findCoreAdmin(vector<Worker>v, int& k, int index);