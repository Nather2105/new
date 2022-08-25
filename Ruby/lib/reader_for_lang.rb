require 'json'

file = File.read("#{__dir__}/languages.json")
info_about_lang = JSON.parse(file)

info_about_lang.each do |k, v|
    if k == "PHP"
        puts "most popular lang is #{k} : #{v}"
        info_about_lang.delete(k) 
        break
    end
end 
puts "other ones:" 
info_about_lang.each do |k, v|
    puts "#{k} : #{v}"
end

