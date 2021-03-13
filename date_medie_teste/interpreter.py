f1=open("C:/Users/Andu/Desktop/SDProject/date_medie_teste/1.out")
f2=open("C:/Users/Andu/Desktop/SDProject/date_medie_teste/2.out")
f3=open("C:/Users/Andu/Desktop/SDProject/date_medie_teste/3.out")
f4=open("C:/Users/Andu/Desktop/SDProject/date_medie_teste/4.out")
f5=open("C:/Users/Andu/Desktop/SDProject/date_medie_teste/5.out")
f=open("C:/Users/Andu/Desktop/SDProject/date_medie_teste/average.out", "w")
rez=[[0, 0] for i in range(108)]
def read(f):
    j=0
    for i in f.readlines():
        x=float(i[:len(i)-1])
        if x!=0:
            rez[j][0]+=x
            rez[j][1]+=1
        j=j+1
read(f1)
read(f2)
read(f3)
read(f4)
read(f5)
j=1
for i in rez:
    if i[1]==0:
        f.write("0\n")
    else:
        f.write(str(round(i[0]/i[1], 6))+"\n")
    if j%9==0:
        f.write("----\n")
    j+=1
f1.close()
f2.close()
f3.close()
f4.close()
f5.close()
f.close()
