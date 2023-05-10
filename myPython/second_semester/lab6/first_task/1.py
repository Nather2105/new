import docx
import re
doc = docx.Document("word.docx")

mas = []
for para in doc.paragraphs:
    
    mas1 = []
    
    if (para.text != ""):
        mas = para.text.split(" ")   
        for pa in mas:
            if(re.match("\d\d[/.-]?\d\d[/.-]?\d{4}", pa)):
                pa = pa.split(pa[2])            
                pa = '.'.join(pa)
                mas1.append(pa)
                
        mas1 = (' ').join(mas1)
        print(mas1) 
        para.text = mas1

doc.save("word_changed1.docx")