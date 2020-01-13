import random
import os

x = 100000
for cnt in range(100):
    f = open("1.in","w")
    n = random.randint(1,10)
    k = random.randint(1,10)
    f.write(str(n) + " " + str(k) + "\n")
    for i in range(n):
        a = random.randint(1,10)
        b = random.randint(1,10)
        f.write(str(a) + " " + str(b) + "\n")
    f.close()
    os.system("sort.exe")
    os.system("sort1.exe")
    with open("1.out") as fo:
        fo = fo.read()
    with open("t1.out") as f:
        f = f.read()
    if int(f) == int(fo):
        print(cnt,"SAME!!!!!!")
    else:
        print(cnt,"WAWAWAWAWA")
        print("input is :")
        os.system("type 1.in")
        print("------")
        print("your :",fo)
        print("OJ   :",f)

