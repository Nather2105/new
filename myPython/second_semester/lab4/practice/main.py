import math
from tkinter import *
from tkinter.messagebox import askokcancel

def quit1():
    ans = askokcancel('Verify exit', "Really quit?")
    if ans: win.quit()
def cosinus():
    b_cos.config(state="disabled")
    b_sin.config(state="active")
    if 'sin_line' in globals():
        canvas.delete(sin_line)
    # 200x150 center
    array_of_cos = []
    array_of_y_for_cos = []

    for number in range(-10,11):
        array_of_cos.append(math.cos(number))
    for item in array_of_cos:
        array_of_y_for_cos.append(150 - (75 * item))

    global cos_line
    cos_line = canvas.create_line(array_of_x[0],array_of_y_for_cos[0], array_of_x[1],array_of_y_for_cos[1],
    array_of_x[2],array_of_y_for_cos[2], array_of_x[3],array_of_y_for_cos[3], array_of_x[4],array_of_y_for_cos[4], array_of_x[5],array_of_y_for_cos[5],
    array_of_x[6],array_of_y_for_cos[6], array_of_x[7],array_of_y_for_cos[7], array_of_x[8],array_of_y_for_cos[8], array_of_x[9],array_of_y_for_cos[9],
    array_of_x[10],array_of_y_for_cos[10], array_of_x[11],array_of_y_for_cos[11], array_of_x[12],array_of_y_for_cos[12], array_of_x[13],array_of_y_for_cos[13],
    array_of_x[14],array_of_y_for_cos[14], array_of_x[15],array_of_y_for_cos[15], array_of_x[16],array_of_y_for_cos[16], array_of_x[17],array_of_y_for_cos[17],
    array_of_x[18],array_of_y_for_cos[18],array_of_x[19],array_of_y_for_cos[19],array_of_x[20],array_of_y_for_cos[20])
    text.delete(1.0,END)

    text.insert(1.0, info_about_cos)
    text.tag_add('title','1.0','1.end')
    text.tag_config('title',font=('Times',14),foreground='red')
def sinus():
    b_sin.config(state="disabled")
    b_cos.config(state="active")
    if 'cos_line' in globals():
        canvas.delete(cos_line)
    # 200x150 center
    array_of_sin = []
    array_of_y_for_sin = []

    for number in range(-10,11):
        array_of_sin.append(math.sin(number))
    for item in array_of_sin:
        array_of_y_for_sin.append(150 - (75 * item))

    global sin_line
    sin_line = canvas.create_line(array_of_x[0],array_of_y_for_sin[0], array_of_x[1],array_of_y_for_sin[1],
    array_of_x[2],array_of_y_for_sin[2], array_of_x[3],array_of_y_for_sin[3], array_of_x[4],array_of_y_for_sin[4], array_of_x[5],array_of_y_for_sin[5],
    array_of_x[6],array_of_y_for_sin[6], array_of_x[7],array_of_y_for_sin[7], array_of_x[8],array_of_y_for_sin[8], array_of_x[9],array_of_y_for_sin[9],
    array_of_x[10],array_of_y_for_sin[10], array_of_x[11],array_of_y_for_sin[11], array_of_x[12],array_of_y_for_sin[12], array_of_x[13],array_of_y_for_sin[13],
    array_of_x[14],array_of_y_for_sin[14], array_of_x[15],array_of_y_for_sin[15], array_of_x[16],array_of_y_for_sin[16], array_of_x[17],array_of_y_for_sin[17],
    array_of_x[18],array_of_y_for_sin[18],array_of_x[19],array_of_y_for_sin[19],array_of_x[20],array_of_y_for_sin[20])
    text.delete(1.0,END)
    text.insert(1.0, info_about_sin)
    text.tag_add('title','1.0','1.end')
    text.tag_config('title',font=('Times',14),foreground='red')



info_about_sin = "Синус - тригонометрична функція кута. Визначення синусу гострого кута в контексті прямокутного трикутника: для заданого кута,є відношенням довжини катета, що є протилежним даному куту, до довжини найдовшої сторони трикутника (гіпотенузи)."
info_about_cos = "Косинус - тригонометрична функція, позначається cos. Для гострого кута прямокутного трикутника - відношення прилеглого до цього кута катета до гіпотенузи; дорівнює синусові другого гострого кута цього трикутника. "
win = Tk()
b_sin = Button(text="sin", width=15,command=sinus)
b_cos = Button(text="cos", width=15,command=cosinus)
widget = Button(text='Quit', width=15, command=quit1)
array_of_x = []
for i in range (-10,11):
    array_of_x.append(200 + 10*i)

canvas = Canvas(width=400,height=300,bg='white')
canvas.create_line((200,0,200,300))
canvas.create_line((0,150,400,150))
labelm10 = Label(text="-10", bg='white')
labelm10.place(x=120 + array_of_x[0],y=160)
labelm5 = Label(text="-5", bg='white')
labelm5.place(x=125 + array_of_x[5],y=160)
labelm1 = Label(text="-1", bg='white')
labelm1.place(x=120 + array_of_x[9],y=160)
label1 = Label(text="1", bg='white')
label1.place(x=133 + array_of_x[11],y=160)
label5 = Label(text="5", bg='white')
label5.place(x=125 + array_of_x[15],y=160)
label10 = Label(text="10", bg='white')
label10.place(x=125 + array_of_x[20],y=160)

labely = Label(text="1", bg='white')
labely.place(x=312, y=80)
labely1 = Label(text="-1", bg='white')
labely1.place(x=312,y=230)




text = Text(width=55,height=5,bg='#ffffff',wrap=WORD)
b_cos.grid(row=0,column=0)
b_sin.grid(row=1,column=0)
widget.grid(row=2,column=0)
canvas.grid(row=0,column=1,rowspan=10)
text.grid(row=11,column=1,rowspan=3)
win.mainloop()
