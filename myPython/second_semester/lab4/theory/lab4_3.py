from tkinter import *
from lab4_2 import Quitter
def fetch():
    print ('Input => "%s"' % ent.get())
    
root = Tk()
root.configure(background='blue')
ent = Entry(root)
ent.insert(0, 'Have a cigar')
ent.pack(side=LEFT)
ent.focus()
ent.bind('<Return>', (lambda event: fetch()))
btn = Button(root, text='Fetch', command=fetch)
btn.pack(side=LEFT)
Quitter(root).pack(side=RIGHT)
root.mainloop()