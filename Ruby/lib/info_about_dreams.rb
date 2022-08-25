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

date = Date.today
must_be_true = []
will_be_true = []
# unless doc.elements.include?('dreams')
# e = doc.add_element 'dreams' unless doc.elements.find("dreams")
expense = doc.elements.each("dreams/dream") do |elem|
    if Date.parse(elem.attributes["date"]) < Date.today
        must_be_true << "#{elem.attributes["date"]} : #{elem.text}"
    else
        will_be_true << "#{elem.attributes["date"]} : #{elem.text}"
    end
end

puts "dreams, which came true:"
puts must_be_true
puts "dreams, which will come true:"
puts will_be_true