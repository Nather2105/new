class Parent
    attr_accessor :name
    def initialize(name)
        @name = name
    end
    
    def obedient
        return true if self.class.name == 'Parent'
        return false
    end
end