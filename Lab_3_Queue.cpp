/// Отключение warning-оповещений
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

/**
* \struct Queue
Структура "Очередь", реализованная с помощью кольцевого списка
*/
struct Queue {
    ///- Целочисленное значение элемента
    int value;
    ///- Указатель на следующий элемент
    Queue *pNext;
};

/**\param pFirst − указатель на первый элемент очереди
* \param p − указатель на добавляемый элемент
*/
/// Функция Add() − точка входа в функцию добавления элемента "p" в конец очереди
void Add(Queue *&pFirst, Queue *p) {
    ///- Проверка на наличие первого элемента
    if (!pFirst)
        p->pNext = pFirst = p;
    ///- Добавление элемента в конец очереди
    else {
        Queue *pE = pFirst;
        while (pE->pNext != pFirst) pE = pE->pNext;
        pE->pNext = p;
        p->pNext = pFirst;
    }
}

/**\param pFirst − указатель на первый элемент очереди
* \param p − указатель на добавляемый элемент
*/
/// Функция Delete() − точка входа в функцию удаления первого элемента из очереди
void Delete(Queue *&pFirst) {
    if (!pFirst) {
        std::cout << "Error: forbidden operation" << std::endl;
        return;
    }

    Queue *pE = pFirst;
    ///- Проход очереди до последнего элемента
    while (pE->pNext != pFirst) pE = pE->pNext;
    ///- Проверка на единичную размерность и удаление
    if (pFirst->pNext != pFirst) {
        pE->pNext = pFirst->pNext;
        delete pFirst;
        pFirst = pE->pNext;
    }
    else pFirst = 0;
}

/**\param pFirst − указатель на первый элемент очереди
*/
/// Функция Print() − точка входа в функцию печати очереди и очистки памяти
void Print(Queue *&pFirst) {
    Queue *pE = pFirst;
    ///- Проверка очереди на наличие элементов
    if (!pFirst)
        std::cout << "Empty queue" << std::endl;
    ///- Вывод очереди на экран и очистка памяти
    else {
        while (pE->pNext != pFirst) {
            std::cout << pE->value << " ";
            pE = pE->pNext;
            Delete(pFirst);
        }
        std::cout << pE->value << " ";
        Delete(pFirst);
    }
}

/**\return {0} - выход из функции
*/
/// Функция main() − точка входа в программу
int main() {
    ///> Алгоритм функции
    ///- Инициализируем переменные
    int N, value;
    std::string message;
    std::cout << "N: ";
    std::cin >> N;
    ///- Проверка: N > 0
    if (!N) {
        std::cout << "Error: N must be > 0" << std::endl;
        system("pause");
        return -1;
    }
    Queue *pFirst = 0, *p;
    ///- Считывание N-го количества команд
    for (int i = 0; i < N; i++) {
        std::cin >> message;
        /// Добавление/удаление элемента соответственно в начало/конце очереди
        if (message == "add") {
            std::cin >> value;
            p = new Queue;
            p->value = value;
            p->pNext = NULL;
            ///- Вызов функции Add()
            Add(pFirst, p);
        } else
            ///- Вызов функции Delete()
            Delete(pFirst);
    }
    /// Вывод очереди на экран
    Print(pFirst);
    system("pause");
    return 0;
}

