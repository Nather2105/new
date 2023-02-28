class MyClass:
    def __init__(self):
        self.__private_attribute = 42
    def get_private(self):
        return self.__private_attribute
obj = MyClass()
print(obj.get_private())  # 42
# print(obj.__private_attribute)  # помилка
#  якщо додати нижніє підкреслення і назву класу, то можна достукатись до приватних атрибутів 
print(obj._MyClass__private_attribute)  # 42