#pragma once
//@author Maltseva K.V.

#include <cassert>
#include"HashTable.h"

//создание таблицы из строк
HashTable<string> CreateHashList() {
	HashTable<string> h(32, HashFunction);
	h.Insert("Антон");
	h.Insert("Степан");
	h.Insert("Борис");
	h.Insert("Анна");
	h.Insert("Юлия");
	return h;
}

//создание таблицы из чисел
HashTable<int> CreateHashIntList() {
	HashTable<int> h(100, HashFunction);
	h.Insert(5);
	h.Insert(120);
	h.Insert(15);
	h.Insert(57);
	h.Insert(1);
	h.Insert(99);
	h.Insert(11);
	return h;
}

//Тестирование вставки
void TestInsert() {
	//создаем таблицу
	HashTable<string> h = CreateHashList();
	//проверяем размер ,переданный в конструктор
	assert(h.GetSize() == 32);
	//фактическое количество элементов
	assert(h.CountElements() == 5);
	//проверяем , есть ли ожидаемые элементы в таблице
	assert(h.Search("Антон") == true);
	assert(h.Search("Степан") == true);
	assert(h.Search("Борис") == true);
	assert(h.Search("Анна") == true); 
	assert(h.Search("Юлия") == true);

	//проверяем несуществующие элементы в таблице
	assert(h.Search("Юлий") == false);
	assert(h.Search("Филипп") == false);

	//создаем таблицу
	HashTable<int> h1 = CreateHashIntList();

	//проверяем размер ,переданный в конструктор
	assert(h1.GetSize() == 100);
	//фактическое количество элементов
	assert(h1.CountElements() == 7);
	//проверяем , есть ли ожидаемые элементы в таблице
	assert(h1.Search(11) == true);
	assert(h1.Search(1) == true);
	assert(h1.Search(99) == true);
	assert(h1.Search(120) == true);
	assert(h1.Search(57) == true);

	//проверяем несуществующие элементы в таблице
	assert(h1.Search(77) == false);
	assert(h1.Search(456) == false);

	cout << "Тест вставки пройден" << endl;
}
//Тестирование удаления 
void TestDelete() {
	//создаем таблицу
	HashTable<string> h = CreateHashList();
	//фактическое количество элементов
	assert(h.CountElements() == 5);
	//удаляем два элемента
	h.Delete("Анна");
	h.Delete("Борис");
	//проверяем , что количество элементов в таблице уменьшилось
	assert(h.CountElements() == 3);
	//проверяем , что удалились ожидаемые элементы
	assert(h.Search("Анна") == false);
	assert(h.Search("Борис") == false);

	//создаем таблицу
	HashTable<int> h1 = CreateHashIntList();
	//фактическое количество элементов
	assert(h1.CountElements() == 7);
	//удаляем два элемента
	h1.Delete(11);
	h1.Delete(1);
	//проверяем , что количество элементов в таблице уменьшилось
	assert(h1.CountElements() == 5);
	//проверяем , что удалились ожидаемые элементы
	assert(h1.Search(1) == false);
	assert(h1.Search(11) == false);

	cout<< "Тест удаления пройден" << endl;

}

//Тестирование очистки
void TestClear() {
	//создаем таблицу
	HashTable<string> h = CreateHashList();
	//фактическое количество элементов
	assert(h.CountElements() == 5);
	//очищаем таблицу
	h.Clear();
	//проверяем , что таблица пуста
    assert(h.CountElements() == 0);
	//проверяем , что ожидаемых элементов нет в таблице
	assert(h.Search("Антон") == false);
	assert(h.Search("Степан") == false);
	assert(h.Search("Борис") == false);
	assert(h.Search("Анна") == false);
	assert(h.Search("Юлия") == false);

	//создаем таблицу
	HashTable<int> h1 = CreateHashIntList();
	//фактическое количество элементов
	assert(h1.CountElements() == 7);
	//очищаем таблицу
	h1.Clear();
	//проверяем , что таблица пуста
	assert(h1.CountElements() == 0);
	//проверяем , что ожидаемых элементов нет в таблице
	assert(h1.Search(1) == false);
	assert(h1.Search(11) == false);
	assert(h1.Search(5) == false);
	assert(h1.Search(120) == false);
	assert(h1.Search(57) == false);
	assert(h1.Search(99) == false);
	assert(h1.Search(15) == false);
	cout << "Тест очистки пройден" << endl;
}
//Тестирование изменения
void TestUpdate() {
	//создаем таблицу
	HashTable<string> h = CreateHashList();
	//заменяем одно значение на другое
	h.Update("Борис", "Лика");
	//проверяем , что количество элементов не поменялось
	assert(h.CountElements() == 5);
	//проверяем ожидаемый результат
	assert(h.Search("Борис") == false);
	assert(h.Search("Лика") == true); 

	//создаем таблицу
	HashTable<int> h1 = CreateHashIntList();
	assert(h1.CountElements() == 7);
	//заменяем одно значение на другое
	h1.Update(1, 20);
	h1.Update(120, 400);
	//проверяем , что количество элементов не поменялось
	assert(h1.CountElements() == 7);
	//проверяем ожидаемый результат
	assert(h1.Search(1) == false);
	assert(h1.Search(20) == true);
	assert(h1.Search(120) == false);
	assert(h1.Search(400) == true);
	cout << "Тест изменения пройден" << endl;
}
