class Products
    attr_accessor :cost, :count
    
    def initialize(cost, count)
        @cost = cost
        @count = count
        
    end

    def to_s
        # "cost is #{@cost}, left: #{@count}"
    end

    def update(params)
    end
    
    def self.read        
        current_path = File.dirname(__FILE__)
        file_name = current_path + "/movies_and_films.xml"

        abort "not found" unless File.exist?(file_name)

        file = File.new(file_name, "r:UTF-8")

        doc = REXML::Document.new(file)
        file.close

        result = []
        product = nil

        doc.elements.each("products/product") do |item|
            cost = item.attributes["cost"].to_i
            count = item.attributes["count"].to_i

            item.each_element("book") do |book_node| 
            product = Book.new(cost, count)
            product.update(
                author: book_node.attributes["author"],
                name: book_node.attributes["name"]
            )
            end

            item.each_element("movie") do |movie| 
            product = Movie.new(cost, count)
            product.update(
                name: movie.attributes["name"],
                director: movie.attributes["director"]
            )
            end
            result << product
        end
        return result
    end

    # class << self
    #     attr_accessor :all
    #     def new(params)
    #         super
    #         Products.all = []
    #         Products.all << self
    #     end
    # end
end