#include <iostream>
#include <string>
using namespace std;

// ====== 封装示例 ======
class BankAccount {
private:                    // 🔒 私有：外部无法直接访问
    double balance;

public:                     // 🔓 公开：对外提供的接口
    BankAccount(double initial) : balance(initial) {}

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;       // 余额不足，拒绝操作
    }

    double getBalance() const { return balance; }
};

// ====== 继承示例 ======
class Animal {
protected:                  // 子类可访问，外部不可
    string name;
public:
    Animal(string n) : name(n) {}
    void eat() { cout << name << " is eating.\n"; }
    virtual void speak() { cout << name << " makes a sound.\n"; }
};

class Dog : public Animal { // 🐕 Dog 继承 Animal
public:
    Dog(string n) : Animal(n) {}

    void speak() override { // 覆盖父类方法
        cout << name << " says: Woof!\n";
    }

    void fetch() {          // 新增方法
        cout << name << " fetches the ball!\n";
    }
};

int main() {
    // 封装：只能通过方法操作余额
    BankAccount acc(100);
    acc.deposit(50);
    acc.withdraw(30);
    cout << "Balance: " << acc.getBalance() << "\n"; // 120
    // acc.balance = 999999;  ❌ 编译错误！私有成员不可访问

    // 继承：Dog 拥有 Animal 的能力 + 自己的能力
    Dog dog("Rex");
    dog.eat();    // 继承自 Animal
    dog.speak();  // Dog 自己的版本
    dog.fetch();  // Dog 新增的
}