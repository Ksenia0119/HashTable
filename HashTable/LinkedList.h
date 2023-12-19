#pragma once
//@author Maltseva K.V.
#include"AbstractIterator.h"
#include <iostream>
using namespace std;
//����� ���� ������
template<class T>
class Node {
public:
    T data;//���� ������ ����
    Node<T>* next;//��������� �� ��������� ����
    Node<T>* prev;//��������� �� ���������� ����
    
    //����������� ������ � ����������
    Node(const T& data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
       
    }
};

//����� ����������� ������
template<class T>
class LinkedList /*:public Iterable<T>*/ {
private:
    Node<T>* head;//��������� �� ������ ������
    Node<T>* tail;//��������  �� ����� ������
    int size;
public:
    //����������� �� ���������
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void InsertHead(const T& data);                            // ������� � ������ ������
    void InsertTail(const T& data);                            // ������� � ����� ������
    void InsertAfter(const T& DataAfter, const T& data);       // ������� ���� ����� ������������� ��������
    void Print();                                              // ������ ������
    bool Search(const T& data);                                // ����� ���� �� ���������
    void Clear();                                              // �������� ������
    void Remove(const T& data);                                // �������� ����
    void Sort();                                               // ���������� ������� (������������ �������)
    void Update(const T& key, const T& newValue);              // ��������� ��������
    int Size() const ;                                               // ��������� ������� ������
    //����� ��������� ����������� ������
    template<class T>
    class ListIterator :public Iterator<T> {
    private:
        Node<T>* current;  // ��������� �� ������� ����
    public:
        //�����������
        ListIterator(Node<T>* node) : current(node) {}

        // �������� �������������-������� � ������
        T& operator*() const override {
            //���������� ������ �������� ����
            return current->data;
        }
        //�������� ����������
        ListIterator& operator++() override {
            //���� ������� �� ����� nullptr
            if (current != nullptr) {
                //��������� � ���������� ����
                current = current->next;
            }
            //���������� ������ �� ������� ������
            return *this;
        }
        // �������� ���������
        bool operator==(const Iterator<T>& other) const override {
            const ListIterator* otherIterator = dynamic_cast<const ListIterator*>(&other);
            return otherIterator && current == otherIterator->current;
        }
        // �������� �����������
        bool operator!=(const Iterator<T>& other) const override {
            return !(*this == other);
        }
        //// �������� ������ ������
        //ListIterator begin() const override {
        //    //���������� �������� ,������� ��������� �� �������� ���� ������
        //    return ListIterator(head);
        //}

        //// �������� ����� ������
        //ListIterator end() const override {
        //    //���������� ��������,������� ��������� �� ������� ����� ���������� ���� ������
        //    return ListIterator(nullptr);
        //}
      // �������� ������ ������


    };
    // �������� ������ ������
    ListIterator<T> begin() const {
        //���������� �������� ,������� ��������� �� �������� ���� ������
        return ListIterator<T>(head);
    }
    // �������� ������ ������
    ListIterator<T> end() const {
        //���������� �������� ,������� ��������� �� ������� ����� ���������� ���� ������
        return ListIterator<T>(nullptr);
    }


};


//���������� ������� ������ ����������� ������
//������� � ������ ������
template<class T>
void LinkedList<T>::InsertHead(const T& data) {
    //�������� ������ ����
    Node<T>* newNode = new Node<T>(data);
    // ���� ������ ������,����� ���� ���������� �������� � ���������
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    //�����
    else {
        //����������� ����� ���� � ������� ������
        newNode->next = head;
        // ������������� ������ �� ���������� ���� ��� ������� ������
        head->prev = newNode;
        // ����� ���� ���������� ��������
        head = newNode;
    }
    size++;
}
//������� � ����� ������
template<class T>
void LinkedList<T>::InsertTail(const T& data) {
    //�������� ������ ����
    Node<T>* newNode = new Node<T>(data);
    // ���� ������ ������,����� ���� ���������� �������� � ���������
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        // ����������� ����� ���� � �������� ������
        tail->next = newNode;
        // ������������� ������ �� ���������� ����
        newNode->prev = tail;
        // ����� ���� ���������� ���������
        tail = newNode;
    }

    size++;
}

//������� ���� � ������ ����� ������������� ��������
template<class T>
void LinkedList<T>::InsertAfter(const T& DataAfter, const T& data) {
    //�������� ������ ����
    Node<T>* newNode = new Node<T>(data);  //������� ���� ��������� �� ������
    Node<T>* current = head;
    //���� ������� �� ����� nullptr
    while (current != nullptr) {
        //���������� ������ � ������� ���� � �������� ������� 
        if (current->data == DataAfter) {
            //���� ������� ����� ������
            if (current == tail) {
                tail = newNode;  // ��������� ����� ������ , ���� ��������� ����� ���������� ����
            }
            // ������������� ������ �� ���������� ���� ��� ������ ����
            newNode->prev = current;
            // ������������� ������ �� ��������� ���� ��� ������ ����
            newNode->next = current->next;
            if (current->next != nullptr) {
                // ������������� ������ �� ���������� ���� ��� ���������� ����
                current->next->prev = newNode;
            }
            // ������������� ������ �� ��������� ���� ��� �������� ����
            current->next = newNode;
            return;
        }
        // ��������� � ���������� ����
        current = current->next;
    }

    size++;
}
//������ ������
template<class T>
void LinkedList<T>::Print() {
    // ��������� �������� ���� �� ������ ������
    Node<T>* current = head;
    while (current != nullptr) {
        // ������� ������ �������� ����
        cout << current->data << " ";
        // ��������� �� ��������� ����
        current = current->next;
    }
    cout << endl;
}
//����� ���� �� ���������
template<class T>
bool LinkedList<T>::Search(const T& data) {
    // ��������� �������� ���� �� ������ ������
    Node<T>* current = head;
    //���� ������� �� ����� nullptr
    while (current != nullptr) {
        //���� ������ � ������� ���� ����� �������
        if (current->data == data) {
            // ���������� true,���� ������� ������
            return true;
        }
        // ��������� � ���������� ����
        current = current->next;
    }
    // ���� ������� �� ������, ���������� false
    return false;
}
//�������� ������
template<class T>
void LinkedList<T>::Clear() {
    while (head != nullptr) {
        Node<T>* current = head;
        head = head->next;
        delete current;

    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}


template<class T>
void LinkedList<T>::Update(const T& key, const T& newValue) {
    // ��������� �������� ���� �� ������ ������
    Node<T>* current = head;
    // ����� ���� � ������ key
    while (current != nullptr) {
        if (current->data == key) {
            // ���������� �������� �����
            current->data = newValue;
            return;
        }
        current = current->next;
    }
}

//�������� ����
template<class T>
void LinkedList<T>::Remove(const T& data) {
    // ��������� �������� ���� �� ������ ������
    Node<T>* current = head;
    //���� ������� �� ����� nullptr
    while (current != nullptr) {
        //���� ������ � ������� ���� ����� �������
        if (current->data == data) {
            //���� ������� ���� ��������
            if (current == head) {
                // ��������� ������ ������,���� ��������� �������- �������� ����
                head = current->next;
            }
            //���� ������� ���� �����
            if (current == tail) {
                // ��������� ����� ������, ���� ��������� ������� - ��������� ����
                tail = current->prev;
            }
            //���� � �������� ���������� �� ����� nullptr
            if (current->prev != nullptr) {
                // ���������  ������ �� ��������� ���� ,��� ����������� ����
                current->prev->next = current->next;
            }
            //���� � �������� ����������� ����� nullptr
            if (current->next != nullptr) {
                // ��������� ������ �� ���������� ���� ��� ���������� ����
                current->next->prev = current->prev;
            }
            // ������� ������� ����
            delete current;
            size--;
            return;
        }
        // ��������� � ���������� ����
        current = current->next;
    }
   
}

// ���������� �������(������������ �������)
template<class T>
void LinkedList<T>::Sort() {
    // ��������� �������� ���� �� ������ ������
    Node<T>* current = head;
    //���� ������� �� ����� nullptr
    while (current != nullptr) {
        // ��������� ������������ ���� �� ������� ����
        Node<T>* minNode = current;
        // ��������� ���������� ��������� �� ��������� ����
        Node<T>* temp = current->next;
        //���� ��������� ���� �� ����� nullptr
        while (temp != nullptr) {
            if (temp->data < minNode->data) {
                // ���������� ������������ ����, ���� ������ ���� � ������� ���������
                minNode = temp;
            }
            // ������� � ���������� ����
            temp = temp->next;
        }
        if (minNode != current) {
            // ����� ���������� �����
            int tempData = current->data;
            current->data = minNode->data;
            minNode->data = tempData;
        }
        current = current->next;
    }
}
// ��������� ������� ������
template<class T>
int LinkedList<T>::Size() const {
    return size;
}