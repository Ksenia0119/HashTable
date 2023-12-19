//@author Maltseva K.V.

#pragma once
#include<vector>
#include"LinkedList.h"
using namespace std;

//��� - �������, ������������� �� ������ �������
template<class T>
class HashTable {
private:
    using hashFunc = unsigned long (*)(const T& key);


    //���������� ������(������ �������)
    int numBuckets;
    // ������ �� ������� ������
    vector<LinkedList<T>> buckets;
    //��������� �� ������� �����������
    hashFunc hf;

    public:
    // ����������� � �����������
    HashTable(int numBuckets, hashFunc hashFunction)
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
  void Print() {
  
      /*for (auto bucket : buckets) {
          bucket.Print();
        
      }*/

      for (int i = 0; i < numBuckets; i++) {
          cout << "����" << i << ": ";
          buckets[i].Print();
          cout << endl;
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
       for (auto& bucket : buckets) {
           // ������� �������  ������
           bucket.Clear();
       }
   }
   // ��������� �������� �� �����
   void Update(const T& key, const T& newValue) {
       int indexOld = GetIndex(key);
       int indexNew = GetIndex(newValue);
       // ���� ����� ��������� � ����� ������, �� �������
       if (indexOld == indexNew) {
           buckets[indexOld].Update(key, newValue);
       }
       // ���� � ������ - ������� ������ � ��������� ����� � �������������� �������
       else {
           buckets[indexOld].Remove(key);
           buckets[indexNew].InsertTail(newValue);
       }

   }
   //������ �������
  int GetSize() const {
      return numBuckets;
  }
  //������� ������������ ����� ��������� � �������
  int CountElements() const
  {
      int count = 0;
      /// ��������� ������� ������� � �������
      for (int i = 0; i < numBuckets; ++i)
      {
          count += buckets[i].Size();
      }
      return count;
  }
  
};

//��� �������
//���2
unsigned long HashFunction(const string& key) {
    //��������� �������� ����
    unsigned long hash = 5381;
    // �������� ��������� �������� ������� ������� ������ key
    int c;
   //����������� �� ������� ������� � ������ key
    for (char ch : key) {
        //������ �������� ��������� �������� �������
        c = ch;
        //��������� ���-��������
        hash = ((hash << 5) + hash) + c; 
    }

    return hash;
}

//unsigned long HashFunction(const int& key) {
//
//    return  key;
//}
//����� �������� � ������ 
unsigned long HashFunction(const int& key) {
    unsigned long hash = static_cast<unsigned long>(key);
    hash ^= (hash << 13);
    hash ^= (hash >> 17);
    hash ^= (hash << 5);
    return hash;
}


