variable1 = nil

class MyClass
    attr_accessor :variable
    def initialize
        @variable = 1
        check
    end

    def check
        if defined?(@variable)
            puts 'yeap'
        else
            puts 'nope'
        end
        if defined?(variable1)
            puts 'yeap'
        else
            puts 'nope'
        end        
    end
end

my = MyClass.new


if defined?(@variable)
    puts 'yeap'
else
    puts 'nope'
end
if defined?(variable1)
    puts 'yeap'
else
    puts 'nope'
end   