class Products
    attr_accessor :cost, :count, :name
    
    def initialize(params)
        @cost = params[:cost]
        @count = params[:count]
        @name = params[:name]
    end

    def to_s
    end

    def update(params)
        @cost = params[:cost] if params[:cost]
        @count = params[:count] if params[:count]
        @name = params[:name] if params[:name]
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