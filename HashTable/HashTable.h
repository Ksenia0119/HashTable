//@author Maltseva K.V.

#pragma once
#include<vector>
#include"LinkedList.h"
using namespace std;
//Хеш - таблица, реализованная по методу цепочек
template<class T>
class HashTable:public LinkedList<T> {
private:
    //количество блоков(размер таблицы)
    int numBuckets;
    // вектор из списков блоков
    vector<LinkedList<T>> buckets;
    //указатель на функцию хеширования
    unsigned long (*hf)(const T& key);

    public:
    // конструктор с параметрами
    HashTable(int numBuckets, unsigned long (*hashFunction)(const T& key))
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
  void Print() const {
      for (auto bucket : buckets) {
          bucket.Print();
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
       for (auto bucket : buckets) {
           // Очистка каждого  списка
           bucket.Clear();
       }
   }
   // изменение значения на новое
   void Update(const T& key, const T& newValue) {
       int index = GetIndex(key);
       buckets[index].Update(key, newValue);
   }
   //размер таблицы
  int GetSize() const {
      return numBuckets;
  }
  
};

//хеш функции
unsigned long HashFunction(const std::string& key) {
   
    return  key.length() ;
}

unsigned long HashFunction(const int& key) {

    return  key;
}
template <class T>
class HashTableIterator : public Iterator<T> {
private:
    HashTable<T>* HashTable;

    int currentBusket;
    LinkedList<T>* curr;

public:
 
};