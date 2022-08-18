class Movie < Products
    attr_accessor :year, :director
    
    def initialize(params)
        @year = params[:year]
        @director = params[:director]
        super
    end

    def to_s
        puts "name of book is #{name}, director #{director} cost = #{cost}, year of publication \"#{year}\", (#{count}) left"
    end

    def update(params)
        @year = params[:year] if params[:year]
        @director = params[:director] if params[:director]
        super
    end
    
end