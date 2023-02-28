class Car:
    name = ''
    model = ''
    year = ''
    def __repr__(self):
        return (self.name + ' ' +  self.model + ' year of release is ' +  str(self.year))

    def horn(self):
        return "beeeeep"
    
        
    
car = Car()

car.name = 'toyota'
car.model = 'highlander'
car.year = 2008


print(car.name)
print(car.year)

print(car.horn())

print(car)
