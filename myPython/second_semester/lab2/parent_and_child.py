class MusicalInstruments:

    def __repr__(self):
        return ("I am a basic class for musical instruments")
    

class Drum(MusicalInstruments):
    
    def __repr__(self):
        return ("I am Drum")
    

class Tambourine(MusicalInstruments):
    
    def __repr__(self):
        return ("I am Tambourine")


class Trombone(MusicalInstruments):
    
    def __repr__(self):
        return ("I am Trombone")
    
    
class Flute(MusicalInstruments):
    
    def __repr__(self):
        return ("I am Flute")

    
class Organ(MusicalInstruments):
    
    def __repr__(self):
        return ("I am Organ")
    
    
class Harmonium(MusicalInstruments):
    
    def __repr__(self):
        return ("I am Harmonium")
    
    
class Bayan(MusicalInstruments):
    
    def __repr__(self):
        return ("I am Bayan")
        
        
class Piano(MusicalInstruments):
    
    def __repr__(self):
        return ("I am Piano")
        

class Percussion(Drum, Tambourine): 
    
    def __repr__(self):
        return ("type of Drum or Tambourine is Percussion")
    
    
    
class Wind(Trombone, Flute, Organ):
    
    def __repr__(self):
        return ("type of Trombone, Flute or Organ is Wind")
    
    
class Keyboard(Harmonium, Bayan, Piano):
    
    def __repr__(self):
        return ("type of Harmonium, Bayan or Piano is Keyboard")


musical_instruments = MusicalInstruments()

drum = Drum()
tambourine = Tambourine()
trombone = Trombone()
flute = Flute()
organ = Organ()
harmonium = Harmonium()
bayan = Bayan()
piano = Piano()

percussion = Percussion()
wind = Wind()
keyboard = Keyboard()
print(musical_instruments)
print(drum)
print(tambourine)
print(trombone)
print(flute)
print(organ)
print(harmonium)
print(bayan)
print(piano)

print(percussion)
print(wind)
print(keyboard)
