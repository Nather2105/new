# input1 = STDIN.gets.chomp

# if input1 =~ /^[a-z\d_+.\-]+@[a-z\d\-]+(\.[a-z\d\-]+)*\.[a-z]+$/i
#     puts 'yes'
# else
#     puts 'nope'
# end
#  puts input1

 input1 = STDIN.gets
  
 if input1.scan(/#[a-z\_-]+[.,?! \n]*/i) != []
    puts p
 else
    puts '0 heshes'
 end

#   input1.split("#").each do |exp|
#     if  exp =~ /./
#         p = exp =~ /./
#         puts p
#         puts exp[0..p]
#     end
#   end



 

  
