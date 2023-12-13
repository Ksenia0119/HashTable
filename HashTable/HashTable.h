//@author Maltseva K.V.

#pragma once
#include<vector>
#include"LinkedList.h"
using namespace std;
//��� - �������, ������������� �� ������ �������
template<class T>
class HashTable:public LinkedList<T> {
private:
    //���������� ������(������ �������)
    int numBuckets;
    // ������ �� ������� ������
    vector<LinkedList<T>> buckets;
    //��������� �� ������� �����������
    unsigned long (*hf)(const T& key);

    public:
    // ����������� � �����������
    HashTable(int numBuckets, unsigned long (*hashFunction)(const T& key))
        : numBuckets(numBuckets), buckets(numBuckets), hf(hashFunction) {}

    //���������� ������� �����
    int GetIndex(const T& key) const {
        return hf(key) % numBuckets;
    }
    //������� � �������
  void Insert(const T& key) {
      //���������� �������
      int index = GetIndex(key);
      //������� � ������ �����
      buckets[index].InsertTail(key);
    }
  //�������� �� �������
  void Delete(const T& key) {
      //���������� �������
      int index = GetIndex(key);
      //�������� �� ������ �����
      buckets[index].Remove(key);
  }
  //������
  void Print() const {
      for (auto bucket : buckets) {
          bucket.Print();
      }
  }

 //����� ��������
  bool Search(const T& key) {
      //���������� �������
      int index = GetIndex(key);
      return buckets[index].Search(key);
  }
  //�������
   void Clear() {
       for (auto bucket : buckets) {
           // ������� �������  ������
           bucket.Clear();
       }
   }
   // ��������� �������� �� �����
   void Update(const T& key, const T& newValue) {
       int index = GetIndex(key);
       buckets[index].Update(key, newValue);
   }
   //������ �������
  int GetSize() const {
      return numBuckets;
  }
  
};

//��� �������
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