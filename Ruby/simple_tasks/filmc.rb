if File.exist? ('./1.txt')
  f=File.new('./1.txt')
  lines=f.readlines
  b = (rand(8)+1)*2 -2
  puts lines[b] + lines[b+1].chomp
  f.close
else
  abort "ERROR"
end