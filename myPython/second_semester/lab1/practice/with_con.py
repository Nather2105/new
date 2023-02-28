class Car:
    def __init__(self, name='unknown', model='unknown', year=0):
        self.name = name
        self.model = model
        self.year = year
        
    def __repr__(self):
        return (self.name + ' ' +  self.model + ' year of release is ' +  str(self.year))

    def horn(self):
        return "beeeeep"
    
        
    
car = Car('toyota', 'highlander', 2008)

print(car.name)
print(car.year)

print(car.horn())

print(car)
