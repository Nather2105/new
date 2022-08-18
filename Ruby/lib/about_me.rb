require "rexml/document"
require "date"

current_path = File.dirname(__FILE__)
file_name = current_path + "/about.xml"

abort "not found" unless File.exist?(file_name)

file = File.new(file_name)

doc = REXML::Document.new(file)

about = Hash.new

doc.elements.each("about/about_person") do |item|
    puts about[:name] = item.attributes["name"]
    puts about[:surname] = item.attributes["surname"]
    puts about[:midname] = item.attributes["midname"]
    puts about[:phone] = item.attributes["phone"]
    puts about[:mail] = item.attributes["mail"]
    # loss_data = Date.parse(item.attributes["date"])
end
 about.values.each do |v|
    puts "#{v}"
end
file.close
