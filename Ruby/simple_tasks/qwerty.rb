temp = ARGV[0].to_i
por =ARGV[1].to_i
fl=0
p temp
p por
if (temp==por && por==0)
  while (fl==0)
  puts "temp now is?"
  temp=STDIN.gets.chomp.to_i
  puts "por year is? " +" 1-spring 2-summer 3-aut 4-winter"
  por=STDIN.gets.chomp.to_i
  if( por>=1 && por<=4)
    fl=1
  end
  end
end
  if ((por==1 && temp>=15 && temp<=35) || (por>=2 && temp>=22 && temp<= 30))
    puts "go to a park, they are singing"
  else
    puts " silence around"
  end

