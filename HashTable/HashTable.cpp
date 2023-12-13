//@author Maltseva K.V.

#include <iostream>
#include"HashTable.h"

int main() {
    setlocale(LC_ALL, "ru");


    HashTable<std::string> hashtable(10, HashFunction); 
   
    // Добавление элементов
    hashtable.Insert("Иван");
    hashtable.Insert("Андрей");
    hashtable.Insert("Петр");

    // Вывод содержимого хеш-таблицы
    hashtable.Print();

    // Удаление элемента
    hashtable.Delete("Иван");
    hashtable.Update("Петр", "Савелий");
    // Вывод содержимого хеш-таблицы
    hashtable.Print();

    // Проверка наличия элемента в хеш-таблице
   cout << "Содержит 'Иван': " << (hashtable.Search("Иван") ? "true" : "false") << endl;
   cout << "Содержит 'Петр': " << (hashtable.Search("Петр") ? "true" : "false") << endl;

   //HashTable<int> hashtable(10, HashFunction);

   //hashtable.Insert(4);
   //hashtable.Insert(6);
   //hashtable.Insert(7);
   //hashtable.Insert(44);
    return 0;
}