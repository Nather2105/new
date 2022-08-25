class Book < Products
    attr_accessor  :author, :name
    
    # def initialize(params = {})
    #     @type = params[:type]
    #     @author = params[:author]
    #     @name = params[:name]
    #     super
    # end

    # def self.from_file(file_path)
    #     lines = File.readlines(file_path).map { |l| l.chomp }
    
    #     self.new(
    #       name: lines[0],
    #       type: lines[1],
    #       author: lines[2],
    #       cost: lines[3].to_i,
    #       count: lines[4].to_i
    #     )
    #   end

    def to_s
         puts "name of book is #{name}, author #{author} cost = #{cost}, #{count} left"
    end

    def update(params)
        @author = params[:author] 
        @name = params[:name]
    end
end