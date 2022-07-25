require_relative 'main'
# album_data = File.read('album')
# group_data = File.read('group')

# puts Oj.load(album_data)
# puts Oj.load(group_data)

album = Album.new 'album'
group = Group.new 'group'

# Oj.load(album_data).each do |method, value|
#     # album.send "#{method}=", value
#     album.instance_variable_set :"@#{method}", value
# end

 puts album.inspect
 puts group.inspect

 puts "=" * 20

 puts album.title
 puts group.title