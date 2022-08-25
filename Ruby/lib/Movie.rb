class Movie < Products
    attr_accessor  :director, :name
    
    # def initialize(params = {})
    #     @year = params[:year]
    #     @director = params[:director]
    #     @name = params[:name]
    #     super
    # end

    def to_s
        puts "name of book is #{name}, director #{director} cost = #{cost}, (#{count}) left"
    end

    def update(params)
        @director = params[:director] 
        @name = params[:name]
    end
    
end