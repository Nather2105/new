$a = 1
b = 2

def method1
    c = 3
    if defined?($a)
        puts "yeap \'$a\'"
    else
        puts "nope \'$a\'"
    end
    if defined?(b)
        puts "yeap \'b\'"
    else
        puts "nope \'b\'"
    end   
    if defined?(c)
        puts "yeap \'c\'" 
    else
        puts "nope \'c\'"
    end     
end

method1
if defined?($a)
    puts "yeap \'$a\'"
else
    puts "nope \'$a\'"
end
if defined?(b)
    puts "yeap \'b\'"
else
    puts "nope \'b\'"
end   
if defined?(c)
    puts "yeap \'c\'" 
else
    puts "nope \'c\'"
end

