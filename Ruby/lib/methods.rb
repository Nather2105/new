def how_much(product)
    puts "write how much"
  while true
    count = STDIN.gets.chomp.to_i
    if product.count < count
      puts "we haven't that much as you wish, try again"
    else
        product.count-= count
        puts "added to order (#{count} pieses of #{product.name}"
        break
    end
  end
  return "#{product.name}(#{count})"
end

def infos(p)
    p.each do |instanse|
        puts instanse.to_s
       end
end
