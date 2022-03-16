class Menu

  def initialize
      @menu=[]

   end
  def add_product(product)
       @menu.push(product)
  end


  def delete_product(product)
       @menu.delete(product)
  end
  def menu_print
    @menu.each{ |i| p i.name + " #{i.price}" }
  end
  def menu
    @menu
  end

  def price_of_order(order)
    @sum=0
    @order=order.split(" ")
    @menu.map{ |i| @sum+=i.price if @order.include? i.name }
    @sum
  end
end