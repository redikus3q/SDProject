f1=open("C:/Users/Andu/Desktop/SDProject/date_medie_teste/test1.out")
f2=open("C:/Users/Andu/Desktop/SDProject/date_medie_teste/test2.out")
f3=open("C:/Users/Andu/Desktop/SDProject/date_medie_teste/test3.out")
f4=open("C:/Users/Andu/Desktop/SDProject/date_medie_teste/test4.out")
f5=open("C:/Users/Andu/Desktop/SDProject/date_medie_teste/test5.out")
f=open("C:/Users/Andu/Desktop/SDProject/date_medie_teste/average.out", "w")
rez=[[0, 0] for i in range(130)]
flist=[f1, f2, f3, f4, f5]
text=["\nTeste pentru un vector strict crescator de 1e4 elemente:\n",
"\nTeste pentru un vector strict descrescator de 1e4 elemente:\n",
"\nTeste pentru un vector constant de 1e4 elemente:\n",
"\nTeste pentru un vector de 1e4 elemente intre -1e4 si 1e4:\n",
"\nTeste pentru un vector de 1e4 elemente pozitive intre 0 si 1e8:\n",
"\nTeste pentru un vector de 1e4 elemente intre -1e8 si 1e8:\n",
"\nTeste pentru un vector de 1e4 elemente intre -1e16 si 1e16:\n",
"\nTeste pentru un vector de 1e6 elemente intre -1e4 si 1e4:\n",
"\nTeste pentru un vector de 1e6 elemente intre -1e8 si 1e8:\n",
"\nTeste pentru un vector de 1e6 elemente intre -1e16 si 1e16:\n",
"\nTeste pentru un vector de 1e7 elemente pozitive intre -1e16 si 1e16:\n",
"\nTeste pentru un vector de 1e7 elemente pozitive intre 0 si 1e16:\n",
"\nTeste pentru un vector de 1e5 elemente pozitive intre 0 si 1e3:\n"] 
sorturi=["bubble - ",
"merge - ",
"radix10 - ",
"radix2 - ",
"radix256 - ",
"count - ",
"quicklast - ",
"quick3 - ",
"quickrandom - ",
"stl - "]
f.write("0 = Nu s-au rulat teste pentru respectiva sortare.\n")
def read(f):
    j=0
    for i in f.readlines():
        x=float(i[:len(i)-1])
        if x!=0:
            rez[j][0]+=x
            rez[j][1]+=1
        j=j+1
for i in flist:
    read(i)
j=0
k=0
for i in rez:
    if j%10==0:
        f.write(text[k])
        k+=1
        j=0
    f.write(sorturi[j])
    if i[1]==0:
        f.write("0\n")
    else:
        f.write(str(round(i[0]/i[1], 6))+"s\n")
    j+=1
for i in flist:
    i.close()
f.close()
