#pragma once
//@author Maltseva K.V.

#include <cassert>
#include"HashTable.h"

//�������� ������� �� �����
HashTable<string> CreateHashList() {
	HashTable<string> h(32, HashFunction);
	h.Insert("�����");
	h.Insert("������");
	h.Insert("�����");
	h.Insert("����");
	h.Insert("����");
	return h;
}

//�������� ������� �� �����
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

//������������ �������
void TestInsert() {
	//������� �������
	HashTable<string> h = CreateHashList();
	//��������� ������ ,���������� � �����������
	assert(h.GetSize() == 32);
	//����������� ���������� ���������
	assert(h.CountElements() == 5);
	//��������� , ���� �� ��������� �������� � �������
	assert(h.Search("�����") == true);
	assert(h.Search("������") == true);
	assert(h.Search("�����") == true);
	assert(h.Search("����") == true); 
	assert(h.Search("����") == true);

	//��������� �������������� �������� � �������
	assert(h.Search("����") == false);
	assert(h.Search("������") == false);

	//������� �������
	HashTable<int> h1 = CreateHashIntList();

	//��������� ������ ,���������� � �����������
	assert(h1.GetSize() == 100);
	//����������� ���������� ���������
	assert(h1.CountElements() == 7);
	//��������� , ���� �� ��������� �������� � �������
	assert(h1.Search(11) == true);
	assert(h1.Search(1) == true);
	assert(h1.Search(99) == true);
	assert(h1.Search(120) == true);
	assert(h1.Search(57) == true);

	//��������� �������������� �������� � �������
	assert(h1.Search(77) == false);
	assert(h1.Search(456) == false);

	cout << "���� ������� �������" << endl;
}
//������������ �������� 
void TestDelete() {
	//������� �������
	HashTable<string> h = CreateHashList();
	//����������� ���������� ���������
	assert(h.CountElements() == 5);
	//������� ��� ��������
	h.Delete("����");
	h.Delete("�����");
	//��������� , ��� ���������� ��������� � ������� �����������
	assert(h.CountElements() == 3);
	//��������� , ��� ��������� ��������� ��������
	assert(h.Search("����") == false);
	assert(h.Search("�����") == false);

	//������� �������
	HashTable<int> h1 = CreateHashIntList();
	//����������� ���������� ���������
	assert(h1.CountElements() == 7);
	//������� ��� ��������
	h1.Delete(11);
	h1.Delete(1);
	//��������� , ��� ���������� ��������� � ������� �����������
	assert(h1.CountElements() == 5);
	//��������� , ��� ��������� ��������� ��������
	assert(h1.Search(1) == false);
	assert(h1.Search(11) == false);

	cout<< "���� �������� �������" << endl;

}

//������������ �������
void TestClear() {
	//������� �������
	HashTable<string> h = CreateHashList();
	//����������� ���������� ���������
	assert(h.CountElements() == 5);
	//������� �������
	h.Clear();
	//��������� , ��� ������� �����
    assert(h.CountElements() == 0);
	//��������� , ��� ��������� ��������� ��� � �������
	assert(h.Search("�����") == false);
	assert(h.Search("������") == false);
	assert(h.Search("�����") == false);
	assert(h.Search("����") == false);
	assert(h.Search("����") == false);

	//������� �������
	HashTable<int> h1 = CreateHashIntList();
	//����������� ���������� ���������
	assert(h1.CountElements() == 7);
	//������� �������
	h1.Clear();
	//��������� , ��� ������� �����
	assert(h1.CountElements() == 0);
	//��������� , ��� ��������� ��������� ��� � �������
	assert(h1.Search(1) == false);
	assert(h1.Search(11) == false);
	assert(h1.Search(5) == false);
	assert(h1.Search(120) == false);
	assert(h1.Search(57) == false);
	assert(h1.Search(99) == false);
	assert(h1.Search(15) == false);
	cout << "���� ������� �������" << endl;
}
//������������ ���������
void TestUpdate() {
	//������� �������
	HashTable<string> h = CreateHashList();
	//�������� ���� �������� �� ������
	h.Update("�����", "����");
	//��������� , ��� ���������� ��������� �� ����������
	assert(h.CountElements() == 5);
	//��������� ��������� ���������
	assert(h.Search("�����") == false);
	assert(h.Search("����") == true); 

	//������� �������
	HashTable<int> h1 = CreateHashIntList();
	assert(h1.CountElements() == 7);
	//�������� ���� �������� �� ������
	h1.Update(1, 20);
	h1.Update(120, 400);
	//��������� , ��� ���������� ��������� �� ����������
	assert(h1.CountElements() == 7);
	//��������� ��������� ���������
	assert(h1.Search(1) == false);
	assert(h1.Search(20) == true);
	assert(h1.Search(120) == false);
	assert(h1.Search(400) == true);
	cout << "���� ��������� �������" << endl;
}
