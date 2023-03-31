class A():
    def __call__(self): return 'Student '
class C(A):
    def __call__(self): return 'Chloe '
class B(A):
    def __call__(self): return 'Bob '
class P(A):
    def __call__(self): return 'Piter '
    
class D(B,C):
    def __init__(self):
        self.name='Denis'
        print(A().__call__()+super().__call__()+'('+super(B,self).__call__()+')' +' like '+self.name)

class E(C,P,B):
    def __init__(self):
        self.name='Eelay'
        print(A().__call__()+super().__call__()+'('+super(C,self).__call__() + super(P,self).__call__()+')'+' like '+self.name)
        
class F(P,B):
    def __init__(self):
        self.name='Forth'
        print(A().__call__()+super().__call__()+'('+super(P,self).__call__()+')' +' like '+self.name)
        
I1=D() 
I2=E()
I3=F()