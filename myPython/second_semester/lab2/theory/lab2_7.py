class Base:
  attr = 'Base attribute'
  def method(self):
    print('Base method, current class is', self.__class__.__name__)
    
class Child(Base):
  attr = 'Redefined attribute'
  @staticmethod
  def get_superclass_attr():
      return Base.attr  # отримання атрибуту класа Base

  def method(self):  # перевизначення методу
    Base.method(self)  # вызов метода суперкласса
    print('Child method, current class is', self.__class__.__name__)


print('Base:')
print(Base.attr)
base_instance = Base()
base_instance.method()

print() 

print('Child:')
print(Child.attr)
print(Child.get_superclass_attr())
child_instance = Child()
child_instance.method()
