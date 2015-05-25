/// Отключение warning-оповещений
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

/**
* \struct List
Структура "Список", реализованный с помощью линейного односвязного списка
*/
struct List {
    ///- Целочисленное значение элемента
    int value;
    ///- Указатель на следующий элемент
    List* pNext;
};

/**\param pFirst − указатель на первый элемент списка
* \param index − индекс позиции для нового элемента
* \param p − указатель на добавляемый элемент
* \return {void} - выход из функции
*/
/// Функция Add() − точка входа в функцию добавления элемента "p" на определённое место
void Add(List *&pFirst, int index, List *p) {
    ///> Алгоритм функции
    ///- Проверка на единичную размерность
    if (index == 1) {
        p->pNext = pFirst;
        pFirst = p;
        return;
    }
    ///- pPred - указатель на предыдущий перед элементом с номером index
    List *pPred = pFirst;
    int i = 1;
    if (!pPred->pNext) {
        pPred->pNext = p;
        return;
    }
    ///- Добавление элемента на место с номером index
    for (pPred; pPred->pNext; pPred = pPred->pNext, i++) {
        if (i + 1 == index) {
            p->pNext = pPred->pNext;
            pPred->pNext = p;
            return;
        }
    }
}

/**\param pFirst − указатель на первый элемент списка
* \param index − индекс позиции удаляемого элемента
* \return {void} - выход из функции
*/
/// Функция Delete() − точка входа в функцию удаления элемента с определенным индексом
void Delete(List *&pFirst, int index) {
    ///> Алгоритм функции
    int i = 1;
    ///- pPred - указатель на элемент, предшествующий элементу с номером index
    List *pPred = pFirst;
    ///- Проверка на единичную размерность
    if (index == 1) {
        pFirst = pFirst->pNext;
        return;
    }
    ///- Удаление элемента с индексом index
    while (pPred) {
        if (i + 1 == index) pPred->pNext = pPred->pNext->pNext;
        else i++;
        pPred = pPred->pNext;
        return;
    }
}

/**\return {0} - выход из функции
*/
/// Функция main() − точка входа в программу
int main() {
    ///> Алгоритм функции
    using std::cin;
    using std::cout;
    using std::string;

    int N, index, value;
    string message;
    List *pFirst = 0;
    cout << "N: ";
    cin >> N;
    ///- Считывание N-го количества команд
    for (int i(0); i < N; i++) {
        cin >> message;
        ///- Добавление/удаление элемента
        if (message == "add") {
            cin >> index;
            cin >> value;
            List *p = new List;
            p->value = value;
            p->pNext = NULL;
            Add(pFirst, index, p);
        } else {
            cin >> index;
            Delete(pFirst, index);
        }
    }
    ///- Вывод списка на экран
    for (List *p = pFirst; p; p = p->pNext) {
        cout << p->value << " ";
    }

    system("pause");
    return 0;
}

