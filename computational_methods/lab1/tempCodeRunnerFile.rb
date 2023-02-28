while (true)
  puts "input k:"
  k = gets.chomp
  unless k.match(/^\d+\.{0,1}\d*$/)
    puts "k must be number and not 0"
    next
  end
  if k.to_f == 0 
    puts "k can`t be 0"
    next
  end
  break
end
while (true)
  puts "input n:"
  n = gets.chomp
  unless n.match(/^\d+$/)
    puts "n must be number and not 0"
    next
  end
  if n.to_f <= 0 
    puts "n can`t be 0"
    next
  end
  break
end
arr = []
n = n.to_i
(1..n).each do |x|
  arr << x
end

arr_reversed = arr.reverse
main_arr = []
main_arr << arr
main_arr << arr_reversed
main_arr.each do |a|
  sum = 0
  # sums = []
  # dodanku = []
  for x in a
    m = (1 / (x ** (1 / 3.to_f))).to_f
    sum += m
    # sums << sum
    # dodanku << m
  end
  # якщо є бажання подивитись на кожен із членів та на кожну суму цього виразу, розкоментуйте 39 40 44 45 48 49 50 51 стрічки 
  # puts "dodanku:"
  # p dodanku
  # puts "sums:"
  # p sums

  puts "final sum is #{sum}"
end

