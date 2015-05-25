/// Отключение warning-оповещений
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <string>

/**
* \class Stack
Класс "Стек", реализованный с помощью массива
*/
class Stack {
    ///- Указатель на массив стека
    int *stack;
    ///- Размер стека
    int size;
 public:
    ///- Конструктор по-умолчанию
    Stack();
    ///- Деструктор
    ~Stack();
    ///- Метод, добавляющий в стек новый элемент
    void Add(int);
    ///- Метод, удаляющий элемент в конце стека
    void Delete();
    ///- Метод, выводящий содержимое стека на экран с последующим очищением памяти
    void Print();
};

/**
Реализация методов
*/

Stack::Stack() {
    stack = 0;
    size = 0;
};

Stack::~Stack() {
    delete[] stack;
}

void Stack::Add(int value) {
    ///- Создание стека при добавлении первого элемента
    if (!stack) {
        stack = new int[1];
        stack[0] = value;
        ++size;
        ///- Добавление элемента в конец стека, производится аналогично удалению
    } else {
        ++size;
        stack = (int*)realloc(stack, size*sizeof(int));
        stack[size - 1] = value;
    }
}

void Stack::Delete() {
    ///- При наличии элементов в стеке удаляем самый "верхний"
    if (size > 0) {
        --size;
        stack = (int*)realloc(stack, size*sizeof(int));
    } else {
        ///- В противном случае выводим ошибку
        std::cout << "Error: forbidden operation" << std::endl;
        return;
    }
}

void Stack::Print() {
    ///- Печать стека и очистка памяти
    for (int i = size - 1; i > -1; i--) {
        std::cout << stack[i] << " ";
        Delete();
    }
}

/**\return {0} - выход из функции
*/
/// Функция main() − точка входа в программу
int main() {
    ///> Алгоритм функции
    ///- Инициализируем переменные
    std::string message;
    int N, value;
    Stack stack;
    std::cout << "N: ";
    std::cin >> N;
    ///- Проверка: N > 0
    if (!N) {
        std::cout << "Error: N must be > 0" << std::endl;
        system("pause");
        return -1;
    }
    ///- Считывание N-го количества команд
    for (int i = 0; i < N; i++) {
        std::cin >> message;
        ///- Добавление/удаление элемента
        if (message == "add") {
            std::cin >> value;
            ///- Вызов метода Add()
            stack.Add(value);
        } else
            ///- Вызов метода Delete()
            stack.Delete();
    }
    ///- Вывод стека на экран
    stack.Print();

    system("pause");
    return 0;
}
