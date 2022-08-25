require "rexml/document"
require "date"

current_path = File.dirname(__FILE__)
file_name = current_path + "/my_dreams.xml"

abort "not found" unless File.exist?(file_name)

file = File.new(file_name, "r:UTF-8")
begin
doc = REXML::Document.new(file)
rescue REXML::ParseExceprion => e
    puts "smth wrong with xmlfile"
    abort e.message
end
file.close

puts "treasure with your dreams, puts your dream:"
expense_text = STDIN.gets.chomp

puts "write deadline for your dream d.m.y(if field is empty will be taken today's date)"
date_input = STDIN.gets.chomp

expense_date = nil 
if date_input == ''
    expense_date = Date.today
else
    expense_date = Date.parse(date_input)
end
# unless doc.elements.include?('dreams')
# e = doc.add_element 'dreams' unless doc.elements.find("dreams")
expense = doc.elements.first.add_element 'dream', {
        'date' => expense_date.strftime("%Y.%m.%d")
}
expense.text = expense_text

file = File.new(file_name, "w:UTF-8")

doc.write(file, 2)
file.close 