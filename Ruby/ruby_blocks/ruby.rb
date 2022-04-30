class Order


    attr_accessor :email, :total, :state, :status

    def initialize(email, total, state, status = :pending)  
        @email = email
        @total = total
        @state = state
        @status = status
    end

    def to_s
        "#{@email} #{state} : #{total} - #{status}" 
    end
end