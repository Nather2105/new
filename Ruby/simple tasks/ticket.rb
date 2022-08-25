
tickets = {
    "ticket1" => {
        number: "1234",
        way: "kiev - lviv",
        passagger: "Sasha Dergunov",
        passport_code: "12 12 123412"
    },

    "ticket2" => {
        number: "12345",
        way:  "lviv - kiev",
        passagger: "Sasha Dergunov",
        passport_code: "12 12 123412"
    }
}
std = STDIN.gets.chomp.downcase.to_s

if tickets.key?(std)
    tickets[std].each do |key|
        puts "#{key}"
    end
    # puts tickets[std]
else
    puts "ERROR"
end
# tickets.each do |key|
#      key.each do |key1|
#         puts key1
#      end
# end