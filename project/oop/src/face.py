# ======= 封装示例 =======
class BankAccount:
    def __init__(self, initial: float):
        self.__balance = initial      # 🔒 双下划线 = 私有

    def deposit(self, amount: float):
        if amount > 0:
            self.__balance += amount

    def withdraw(self, amount: float) -> bool:
        if 0 < amount <= self.__balance:
            self.__balance -= amount
            return True
        return False

    def get_balance(self) -> float:
        return self.__balance


# ====== 继承示例 ======
class Animal:
    def __init__(self, name: str):
        self.name = name

    def eat(self):
        print(f"{self.name} is eating.")

    def speak(self):
        print(f"{self.name} makes a sound.")


class Dog(Animal):              # 🐕 Dog 继承 Animal
    def speak(self):            # 覆盖父类方法
        print(f"{self.name} says: Woof!")

    def fetch(self):            # 新增方法
        print(f"{self.name} fetches the ball!")


if __name__ == "__main__":
    # 封装
    acc = BankAccount(100)
    acc.deposit(50)
    acc.withdraw(30)
    print(f"Balance: {acc.get_balance()}")  # 120
    # print(acc.__balance)  ❌ AttributeError! 私有属性不可访问

    # 继承
    dog = Dog("Rex")
    dog.eat()     # 继承自 Animal
    dog.speak()   # Dog 自己的版本
    dog.fetch()   # Dog 新增的
    