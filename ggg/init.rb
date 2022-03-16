require_relative 'menu.rb'
require_relative 'product.rb'
require_relative 'order.rb'
menu=Menu.new

product1=Product.new('pizza',100)
product2=Product.new('pasta',50)

menu.add_product(product1)
menu.add_product(product2)

menu.menu_print

p "your price of order is #{menu.price_of_order(STDIN.gets.chomp)}"

