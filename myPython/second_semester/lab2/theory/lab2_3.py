class Figure(object):
    def __init__(self, side):
        self.side = side

class Square(Figure):
    def draw(self):
        for i in range(self.side):
            print('*' * self.side)
        
class Triangle(Figure):
    def draw(self):
        for i in range(self.side):
            print('*' * i)

square = Square(10)
square.draw()
print()
triangle = Triangle(5)
triangle.draw()
