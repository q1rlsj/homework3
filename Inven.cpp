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
        cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
    }
};

// 템플릿 클래스 Inventory<T>
template <typename T>
class Inventory {
private:
    T* pItems_;      // 동적 배열
    int capacity_;   // 최대 용량
    int size_;       // 현재 개수

public:
    // 생성자
    Inventory(int capacity = 10)
        : capacity_(capacity), size_(0)
    {
        if (capacity_ <= 0) capacity_ = 1;
        pItems_ = new T[capacity_];
    }

    // 소멸자
    ~Inventory() {
        delete[] pItems_;
        pItems_ = nullptr;
    }

    // 아이템 추가
    void AddItem(const T& item) {
        if (size_ < capacity_) {
            pItems_[size_] = item;
            size_++;
        }
        else {
            cout << "인벤토리가 꽉 찼습니다!" << endl;
        }
    }

    // 마지막 아이템 제거 실제 메모리를 지우는 것이 아님
    void RemoveLastItem() {
        if (size_ > 0) {
            size_--;
        }
        else {
            cout << "인벤토리가 비어있습니다." << endl;
        }
    }

    // 현재 크기 반환
    int GetSize() const {
        return size_;
    }

    // 용량 반환
    int GetCapacity() const {
        return capacity_;
    }

    // 전체 아이템 출력
    void PrintAllItems() const {
        if (size_ == 0) {
            cout << "(비어있음)" << endl;
            return;
        }
        for (int i = 0; i < size_; i++) {
            pItems_[i].PrintInfo();
        }
    }
};

int main() {
    Inventory<Item> inv(2);

    inv.AddItem(Item("빨간포션", 50));
    inv.AddItem(Item("파란포션", 200));
 //   inv.AddItem(Item("하얀포션", 150));

    cout << "== 현재 인벤토리 ==" << endl;
    inv.PrintAllItems();

    cout << "\n마지막 아이템 제거" << endl;
    inv.RemoveLastItem();

    cout << "== 현재 인벤토리 ==" << endl;
    inv.PrintAllItems();

    return 0;
}
