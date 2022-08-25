class Module
    def hello
        puts 'hello'
    end
end

class Object
    def hello1
        puts 'hello1'
    end
end

class Animal 
    attr_accessor :name
    
    
    protected def set
        puts "#{self.class.name}"
    end
end

class Cat < Animal

    def set1
        set
    end

    def set2
        Cat.new.set
    end
end

Cat.new.set2

# cat = Cat

# p cat.object_id

# c = cat.new

#   Cat.hello1
# c = Cat.new
#  c.hello1
# p Cat.superclass.superclass.superclass.superclass

# p Cat.class.superclass

# p Animal.class

#  p Class.methods.grep /module/

#  p Module.superclass
# p Class.methods.grep /instance/

# 1 = Animal.new
# 2 = Animal.new
# 3 = Animal.new

#  Animal ?