hero=STDIN.gets.chomp.downcase

case hero
when "batman","бетмен"
  puts "Джокер!"
when "шерлок холмс","sherlock holms"
  puts "Профессор Мориарти"
when "буратино","buratino"
  puts "Карабас-Барабас"
else
  puts "Не удалось найти врага."
end