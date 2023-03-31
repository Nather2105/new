def gen_init(cls):
    def init(self):
        print('Entered', cls.__name__, "constructor")
        super(cls, self).__init__()
        print('Quit', cls.__name__, "constructor")
    cls.__init__ = init
    return cls
@gen_init
class A(object):  pass
@gen_init
class B(object):  pass
@gen_init
class C(A, B):  pass
@gen_init
class D(C, B):  pass
@gen_init
class E(D):  pass
print(E.__mro__)
obj = E()