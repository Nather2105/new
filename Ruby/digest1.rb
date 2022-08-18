require 'digest'

puts "put what you want to encrypt "

encrypt = STDIN.gets.chomp

encrypted = Digest::MD5.hexdigest encrypt
encrypted1 = Digest::SHA1.hexdigest encrypt

puts encrypted
puts "\n"
puts encrypted1

