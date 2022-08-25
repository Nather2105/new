if File.exist? ('./2.txt')
  f=File.new('./2.txt')
  lines=f.readlines
  puts lines.sample.chomp
  f.close
else
  abort "ERROR"
end