require './Bodyb.rb'

bodyb=Bodyb.new(0,0,0,1)
bodyb1=Bodyb.new(0,0,0,2)

bodyb.pump('tr')
bodyb.pump('tr')
bodyb.pump('bi')
bodyb.pump('bi')
bodyb.pump('de')
bodyb.pump('de')
bodyb.pump('de')

bodyb1.pump('tr')
bodyb1.pump('tr')
bodyb1.pump('tr')
bodyb1.pump('de')
bodyb1.pump('de')
bodyb1.pump('de')
bodyb1.pump('bi')
bodyb1.pump('bi')
bodyb1.pump('bi')

