mass=[1,2,3,4,5,6,7,8,9,10,11]
p mass
puts "how much should i cut? "
n= gets.chomp.to_i
if (n>=11)
  abort "ERROR"
end
mass1=mass.slice(0...n)
p mass1