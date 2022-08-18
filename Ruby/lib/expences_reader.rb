require "rexml/document"
require "date"

current_path = File.dirname(__FILE__)
file_name = current_path + "/my_expenses.xml"

abort "not found" unless File.exist?(file_name)

file = File.new(file_name)

doc = REXML::Document.new(file)

amount_by_day = Hash.new

doc.elements.each("expenses/expense") do |item|
    loss_sum = item.attributes["amount"].to_i
    loss_data = Date.parse(item.attributes["date"])

    amount_by_day[loss_data] ||= 0
    amount_by_day[loss_data] += loss_sum
end

file.close

sum_by_mouth = Hash.new

current_month = amount_by_day.keys.sort[0].strftime("%B %Y")

amount_by_day.keys.sort.each do |key|
    sum_by_mouth[key.strftime("%B %Y")] ||= 0
    sum_by_mouth[key.strftime("%B %Y")] += amount_by_day[key]
end

puts "#{current_month}, spent #{sum_by_mouth[current_month]}"

amount_by_day.keys.sort.each do |key|
    unless key.strftime("%B %Y") == current_month 
        current_month = key.strftime("%B %Y")
        puts "#{current_month}, spent #{sum_by_mouth[current_month]}"
    end
    puts "#{key.day}: #{amount_by_day[key]}"
end