require './Film.rb'
require './Name.rb'

name1=Name.new('petya','vasilyovich',30)
name2=Name.new('petya1','vasilyovich1',31)
name3=Name.new('petya2','vasilyovich2',32)

name1.film=Film.new('Guy Reachi','GENTM')
name2.film=Film.new('Guy Reachi','GENTM1')
name3.film=Film.new('Guy Reachi','GENTM2')

puts name1.full
puts "favourite film is " + name1.film.n_f
puts

puts name2.full
puts "favourite film is " + name2.film.n_f
puts

puts name3.full
puts "favourite film is " + name3.film.n_f
puts
