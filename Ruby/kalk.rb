begin
first = STDIN.gets.chomp.to_i
second = STDIN.gets.chomp.to_i
if first =~ //
end
operation = STDIN.gets.chomp.to_s
case operation
when '-'
    puts (first-second).to_s 
when '/'
    puts (first/second).to_s
when '+'
    puts (first+second).to_s
when '*'
    puts (first*second).to_s
end

rescue ZeroDivisionError
    puts 'imposible to div on zero'
rescue
    puts 'smth went wrong'
end