require_relative 'Products'
require_relative 'Book'
require_relative 'Movie'
require_relative 'methods'
require "rexml/document"
require "date"


 p = Products.read
 infos(p)
order = []
puts "there is our products, make your order"  
puts "put x for end the offer"

 while true
  checker = STDIN.gets.chomp
  if checker == "Приключения Тома Сойера"
    order << how_much(p[0])
    infos(p)
  elsif checker == "Великий Лебовскі"
    order << how_much(p[1])
    infos(p)
  elsif checker == "Дивні справи"
    order << how_much(p[2])
    infos(p)
  elsif checker == "вкрадено"
    order << how_much(p[3])
    infos(p)
  elsif checker == "Навіщо"
    order << how_much(p[4])
    infos(p)
  elsif checker == 'x'
    ending = order.each do |ord|
      puts "#{ord.to_s}"
    end
    abort "your order is accepted"
  end
 end
# book = Book.new(cost: 123, count: 10,  type: 'novela', author: 'John Do', name: 'journey')
# movie = Movie.new(cost: 1234, count: 100, year: 1998, director: 'Di Do', name: 'Big Lebovski')

# puts book.inspect
# puts movie.inspect
# current_path = File.dirname(__FILE__)
# begin
#     Products.from_file(current_path + '/data/films/01.txt')
#   rescue NotImplementedError
#     puts 'Метод класса Product.from_file не реализован'
#   end