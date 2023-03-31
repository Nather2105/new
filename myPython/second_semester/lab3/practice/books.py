import shelve

# початковий клас
class Book:
    def __init__(self, name_of_book = '', author='', year_of_realize = 0):
        self.name_of_book = name_of_book
        self.author = author
        self.year_of_realize = year_of_realize

    def __str__(self):
        return "%s(%s), author is %s" % (self.name_of_book, self.year_of_realize, self.author)

#  допоміжний клас для уникнення повторень
class Book_Helper(Book):
    def __init__(self, name_of_book = 'None', author='Noname', year_of_realize = 0, amount_of_readers = 0):
        super().__init__(name_of_book, author, year_of_realize)
        self.type_of_book = 'None'
        self.amount_of_readers = amount_of_readers
        
    def __str__(self):
        return "%s(%s), %s. Author is %s, readers(%s)" % (self.name_of_book, self.year_of_realize, self.type_of_book, self.author, self.amount_of_readers)
    
    def increase_of_readers(self, additional_readers):
        self.amount_of_readers += additional_readers
    
# три класи наслідники  
class Fantasy_Book(Book_Helper):
    def __init__(self, name_of_book = '', author='', year_of_realize = 0, amount_of_readers = 0):
        super().__init__(name_of_book, author, year_of_realize, amount_of_readers)
        self.type_of_book = 'Fantasy'
        
        
class Adventure_Book(Book_Helper):
    def __init__(self, name_of_book = '', author='', year_of_realize = 0, amount_of_readers = 0):
        super().__init__(name_of_book, author, year_of_realize, amount_of_readers)
        self.type_of_book = 'Adventure'

class Science_Book(Book_Helper):
    def __init__(self, name_of_book = '', author='', year_of_realize = 0, amount_of_readers = 0):
        super().__init__(name_of_book, author, year_of_realize, amount_of_readers)
        self.type_of_book = 'Science'
    
    
    
if __name__ == '__main__':    
    
    sasha = Book('New book', 'Sasha', 2023)
    # print(sasha)
    
    
    masha = Fantasy_Book('First try', 'Masha', 2022)
    masha.increase_of_readers(50)
    # print(masha)
    
    
    pasha = Adventure_Book('The edge of the world ', 'Pasha', 2004, 24000)
    # print(pasha)
    
    
    dasha = Science_Book('On my way', 'Dasha', 2019, 350)
    # print(dasha)
    
    db = shelve.open('booksdb') # ім‘я файлу у сховищі
     
    #  вписування в бд 
    for object in (sasha, masha, pasha, dasha): 
        db[object.name_of_book] = object 

    # вивід через бд
    for key in db: # Ітерації, витягання, виведення
        print(key, '=>', db[key])