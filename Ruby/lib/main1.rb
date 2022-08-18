require_relative 'Products'
require_relative 'Book'
require_relative 'Movie'

products1 = []
products1 << book = Book.new(cost: 123, count: 10,  type: 'novela', author: 'John Do', name: 'journey')
products1 << movie = Movie.new(cost: 1234, count: 100, year: 1998, director: 'Di Do', name: 'Big Lebovski')

book.cost = 10
movie.update(count: 12, year: 1993)
products1.each do |cl|
    cl.to_s
end
# puts book.inspect
# puts movie.inspect

begin
    Product.from_file(current_path + '/data/films/01.txt')
  rescue NotImplementedError
    puts 'Метод класса Product.from_file не реализован'
  end