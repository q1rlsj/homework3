#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    string name_;
    int price_;
public:
    Item(const string& name = "User", int price = 0)
        : name_(name), price_(price) {
    }

    void PrintInfo() const {
        cout << "[�̸�: " << name_ << ", ����: " << price_ << "G]" << endl;
    }
};

// ���ø� Ŭ���� Inventory<T>
template <typename T>
class Inventory {
private:
    T* pItems_;      // ���� �迭
    int capacity_;   // �ִ� �뷮
    int size_;       // ���� ����

public:
    // ������
    Inventory(int capacity = 10)
        : capacity_(capacity), size_(0)
    {
        if (capacity_ <= 0) capacity_ = 1;
        pItems_ = new T[capacity_];
    }

    // �Ҹ���
    ~Inventory() {
        delete[] pItems_;
        pItems_ = nullptr;
    }

    // ������ �߰�
    void AddItem(const T& item) {
        if (size_ < capacity_) {
            pItems_[size_] = item;
            size_++;
        }
        else {
            cout << "�κ��丮�� �� á���ϴ�!" << endl;
        }
    }

    // ������ ������ ���� ���� �޸𸮸� ����� ���� �ƴ�
    void RemoveLastItem() {
        if (size_ > 0) {
            size_--;
        }
        else {
            cout << "�κ��丮�� ����ֽ��ϴ�." << endl;
        }
    }

    // ���� ũ�� ��ȯ
    int GetSize() const {
        return size_;
    }

    // �뷮 ��ȯ
    int GetCapacity() const {
        return capacity_;
    }

    // ��ü ������ ���
    void PrintAllItems() const {
        if (size_ == 0) {
            cout << "(�������)" << endl;
            return;
        }
        for (int i = 0; i < size_; i++) {
            pItems_[i].PrintInfo();
        }
    }
};

int main() {
    Inventory<Item> inv(2);

    inv.AddItem(Item("��������", 50));
    inv.AddItem(Item("�Ķ�����", 200));
 //   inv.AddItem(Item("�Ͼ�����", 150));

    cout << "== ���� �κ��丮 ==" << endl;
    inv.PrintAllItems();

    cout << "\n������ ������ ����" << endl;
    inv.RemoveLastItem();

    cout << "== ���� �κ��丮 ==" << endl;
    inv.PrintAllItems();

    return 0;
}
