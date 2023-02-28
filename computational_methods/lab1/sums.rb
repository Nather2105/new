while (true)
  puts "input n:"
  n = gets.chomp
  unless n.match(/^\d+$/)
    puts "n must be number and not 0"
    next
  end
  if n.to_f == 0 
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
  for k in a
    m = (1 / (k ** (1 / 3.to_f))).to_f
    sum += m
    # sums << sum
    # dodanku << m
  end
  # якщо є бажання подивитись на кожен із членів та на кожну суму цього виразу, розкоментуйте 26 27 35 36 37 38 стрічки 
  # puts "dodanku:"
  # p dodanku
  # puts "sums:"
  # p sums

  puts "final sum is #{sum}"
end

