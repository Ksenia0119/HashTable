//@author Maltseva K.V.

#include <iostream>
#include"HashTable.h"
#include "HashTableTest.h"

int main() {
    setlocale(LC_ALL, "ru");


    HashTable<string> hashtable(32, HashFunction); 
   
    // Добавление элементов
    hashtable.Insert("Иван");
    hashtable.Insert("Андрей");
    hashtable.Insert("Петр");

    // Вывод содержимого хеш-таблицы
    hashtable.Print();
    cout << "Хеш-таблица после изменений " << endl;
    // Удаление элемента
    hashtable.Delete("Андрей");
    hashtable.Update("Петр", "Савелий");
    hashtable.Insert("Ян");
    hashtable.Insert("Бартоломей");
 
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

   cout << "Тесты" << endl;
   TestInsert();
   TestDelete();
   TestClear();
   TestUpdate();
    return 0;
}