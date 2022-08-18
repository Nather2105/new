require_relative 'Parent'
require_relative 'Child'

parent = Parent.new('Vasya')
child = Child.new('Sasha')

puts "is #{parent.name} obedient? #{parent.obedient}"
puts "is #{child.name} obedient? #{child.obedient}"