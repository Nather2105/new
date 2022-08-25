require 'json'
file = File.read("#{__dir__}/info.json")
info = JSON.parse(file)

puts "#{info["name"]} #{info["midname"]} #{info["second_name"]}"
puts "#{info["some_info"]}"
puts "#{info["phone"]}"
puts "#{info["email"]}"
