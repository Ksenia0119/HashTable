//@author Maltseva K.V.

#pragma once
#include<vector>
#include"LinkedList.h"
using namespace std;

//Хеш - таблица, реализованная по методу цепочек
template<class T>
class HashTable {
private:
    using hashFunc = unsigned long (*)(const T& key);


    //количество блоков(размер таблицы)
    int numBuckets;
    // вектор из списков блоков
    vector<LinkedList<T>> buckets;
    //указатель на функцию хеширования
    hashFunc hf;

    public:
    // конструктор с параметрами
    HashTable(int numBuckets, hashFunc hashFunction)
        : numBuckets(numBuckets), buckets(numBuckets), hf(hashFunction) {}

    //вычисление индекса блока
    int GetIndex(const T& key) const {
        return hf(key) % numBuckets;
    }
    //вставка в таблицу
  void Insert(const T& key) {
      //вычисление индекса
      int index = GetIndex(key);
      //вставка в список блока
      buckets[index].InsertTail(key);
    }
  //удаление из таблицы
  void Delete(const T& key) {
      //вычисление индекса
      int index = GetIndex(key);
      //удаление из списка блока
      buckets[index].Remove(key);
  }
  //печать
  void Print() {
  
      /*for (auto bucket : buckets) {
          bucket.Print();
        
      }*/

      for (int i = 0; i < numBuckets; i++) {
          cout << "Блок" << i << ": ";
          buckets[i].Print();
          cout << endl;
      }
   
  }

 //поиск элемента
  bool Search(const T& key) {
      //вычисление индекса
      int index = GetIndex(key);
      return buckets[index].Search(key);
  }
  //очистка
   void Clear() {
       for (auto& bucket : buckets) {
           // Очистка каждого  списка
           bucket.Clear();
       }
   }
   // изменение значения на новое
   void Update(const T& key, const T& newValue) {
       int indexOld = GetIndex(key);
       int indexNew = GetIndex(newValue);
       // если ключи находятся в одном списке, то заменям
       if (indexOld == indexNew) {
           buckets[indexOld].Update(key, newValue);
       }
       // если в разных - удаляем старый и вставляем новый в соответсвующих списках
       else {
           buckets[indexOld].Remove(key);
           buckets[indexNew].InsertTail(newValue);
       }

   }
   //размер таблицы
  int GetSize() const {
      return numBuckets;
  }
  //подсчет фактического числа элементов в таблице
  int CountElements() const
  {
      int count = 0;
      /// суммируем размеры списков в таблице
      for (int i = 0; i < numBuckets; ++i)
      {
          count += buckets[i].Size();
      }
      return count;
  }
  
};

//хеш функции
//ДЖБ2
unsigned long HashFunction(const string& key) {
    //начальное значение хеша
    unsigned long hash = 5381;
    // хранение числового значения каждого символа строки key
    int c;
   //итерируемся по каждому символу в строке key
    for (char ch : key) {
        //запись текущего числового значения символа
        c = ch;
        //обновляем хеш-значение
        hash = ((hash << 5) + hash) + c; 
    }

    return hash;
}

//unsigned long HashFunction(const int& key) {
//
//    return  key;
//}
//Метод сложения и сдвига 
unsigned long HashFunction(const int& key) {
    unsigned long hash = static_cast<unsigned long>(key);
    hash ^= (hash << 13);
    hash ^= (hash >> 17);
    hash ^= (hash << 5);
    return hash;
}


