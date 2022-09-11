require 'pony'
require 'io/console'
my_email = "qwftg2004@gmail.com"
puts "Введите пароль от вашей почты #{my_email} для отправки письма:"
password = STDIN.noecho(&:gets).chomp

puts "Кому отправить письмо? Введите адрес:"
send_to = STDIN.gets.chomp

puts "Что написать в письме?"
body = STDIN.gets.chomp

Pony.mail({
            :body => body,
            :to => send_to,
            :from => my_email,

            :via => :smtp,
            :via_options => {
              :address              => 'smtp.gmail.com',
              :port                 => '587',
              :enable_starttls_auto => true,
              :user_name            => my_email,
              :password             => password,
              :authentication       => :plain, # :plain, :login, :cram_md5, no auth by default
              :domain               => "localhost.localdomain" # the HELO domain provided by the client to the server
            }
          })

puts "SMS is sent"