class MyClass:
   def __init__(self):
        self.password = None
   def __getattribute__(self, item):
    # Метод __getattribute__ викливають при отриманні атрибутів
        # Якщо поле-запит secret_field і пароль правильний
        if item == 'secret_field' and self.password == '9ea)fc':
            # то повертаємо значення
            return 'secret value'
        else:
        # инакше викликаємо метод __getattribute__ класу object
            return object.__getattribute__(self, item)
obj = MyClass()# Створення екземпляру класу
# Розблокування секретного поля
obj.password = '9ea)fc'
# Виведення значення secret field.
# Значення буде отримано, якщо  розкоментувати попередній
# рядок  програмного коду, інакш отримаємо помилку


print(obj.secret_field)