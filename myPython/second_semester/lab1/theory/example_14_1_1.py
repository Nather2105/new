class MyClass:  pass
obj = MyClass()
# Объект obj - це екземпляр класу MyClass,
# (він має тип MyClass)
print(type(obj))  # <class '__main__.MyClass'>
# MyClass – це клас, він є  об'єктом, екземпляром метакласу type
# який є абстракцією поняття типу даних
print(type(MyClass))  # <class 'type'>
# Тому з класами можна виконувати операції як із об'єктами
# наприклад, копиювання
AnotherClass = MyClass
print(type(AnotherClass))
# тепер AnotherClass – це те ж саме, що і MyClass,
# і obj є екземпляром класу AnotherClass
print(isinstance(obj, AnotherClass))  # True
