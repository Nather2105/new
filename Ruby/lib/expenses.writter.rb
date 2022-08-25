require "rexml/document"
require "date"

current_path = File.dirname(__FILE__)
file_name = current_path + "/my_expenses.xml"

abort "not found" unless File.exist?(file_name)

file = File.new(file_name, "r:UTF-8")
begin
doc = REXML::Document.new(file)
rescue REXML::ParseExceprion => e
    puts "smth wrong with xmlfile"
    abort e.message
end
file.close

puts "what is the reason of waste the money?"
expense_text = STDIN.gets.chomp

puts "how much"
expense_amount = STDIN.gets.chomp.to_i

puts "write date of waste d.m.y(if field is empty will be taken today's date)"
date_input = STDIN.gets.chomp

expense_date = nil 
if date_input == ''
    expense_date = Date.today
else
    expense_date = Date.parse(date_input)
end

puts "category of wasting?"
expense_category = STDIN.gets.chomp


expenses = doc.elements.find("expenses").first
expense = expenses.add_element 'expense', {
        'amount' => expense_amount,
        'category' => expense_category,
        'date' => expense_date.strftime("%Y.%m.%d")
}
expense.text = expense_text

file = File.new(file_name, "w:UTF-8")

doc.write(file, 2)
file.close 