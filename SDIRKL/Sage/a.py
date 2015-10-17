# This file was *autogenerated* from the file a.sage.
from sage.all_cmdline import *   # import sage library
_sage_const_3 = Integer(3); _sage_const_2 = Integer(2); _sage_const_1 = Integer(1); _sage_const_0 = Integer(0); _sage_const_544 = Integer(544); _sage_const_6 = Integer(6); _sage_const_5 = Integer(5); _sage_const_4 = Integer(4); _sage_const_24 = Integer(24); _sage_const_25 = Integer(25); _sage_const_137 = Integer(137); _sage_const_1360 = Integer(1360); _sage_const_48 = Integer(48); _sage_const_49 = Integer(49); _sage_const_371 = Integer(371); _sage_const_12 = Integer(12); _sage_const_17 = Integer(17); _sage_const_16 = Integer(16); _sage_const_15 = Integer(15); _sage_const_2720 = Integer(2720); _sage_const_18 = Integer(18); _sage_const_50 = Integer(50); _sage_const_125 = Integer(125); _sage_const_85 = Integer(85)
def outa(n,A):
    for i in range(_sage_const_0 ,n):
        for j in range(_sage_const_0 ,i+_sage_const_1 ):
            s="A["+str(i)+"]["+str(j)+"]="+str(A[i,j])+";"
            print(s)
def outb(n,b):
    for i in range(_sage_const_0 ,n):
        s="b["+str(i)+"]="+str(b[i])+";"
        print(s)
def sumline(n,A):
    for i in range(_sage_const_0 ,n):
        su=sum(A[i,j] for j in range(_sage_const_0 ,n))
        s="S["+str(i)+"]="+str(su.n())+";"
        print(s)
print("SDIRK,ordre 4")
n=_sage_const_5 
l1=[_sage_const_1 /_sage_const_4 ,_sage_const_0 ,_sage_const_0 ,_sage_const_0 ,_sage_const_0 ]
l2=[_sage_const_1 /_sage_const_2 ,_sage_const_1 /_sage_const_4 ,_sage_const_0 ,_sage_const_0 ,_sage_const_0 ]
l3=[_sage_const_17 /_sage_const_50 ,-_sage_const_1 /_sage_const_25 ,_sage_const_1 /_sage_const_4 ,_sage_const_0 ,_sage_const_0 ]
l4=[_sage_const_371 /_sage_const_1360 ,-_sage_const_137 /_sage_const_2720 ,_sage_const_15 /_sage_const_544 ,_sage_const_1 /_sage_const_4 ,_sage_const_0 ]
l5=[_sage_const_25 /_sage_const_24 ,-_sage_const_49 /_sage_const_48 ,_sage_const_125 /_sage_const_16 ,-_sage_const_85 /_sage_const_12 ,_sage_const_1 /_sage_const_4 ]
A=matrix([l1,l2,l3,l4,l5])
print(A)
outa(n,A.n())
sumline(n,A)
Ai=A.inverse()
#print(Ai)
b=vector(l5)
#print(b)
d=b*Ai;
print(b*Ai)
outb(_sage_const_5 ,d)
#-----
print("Crouzeix:")
n=_sage_const_3 
gamma=cos(pi/_sage_const_18 )/sqrt(_sage_const_3 )+_sage_const_1 /_sage_const_2 
print("gamma= ",gamma)
l1=[gamma,_sage_const_0 ,_sage_const_0 ]
l2=[_sage_const_1 /_sage_const_2 -gamma,gamma,_sage_const_0 ]
l3=[_sage_const_2 *gamma,_sage_const_1 -_sage_const_4 *gamma,gamma]
A=matrix([l1,l2,l3])
print(A)
outa(_sage_const_3 ,A.n())
sumline(n,A)

Ai=A.inverse()
delta=_sage_const_1 /_sage_const_6 /(_sage_const_2 *gamma-_sage_const_1 )**_sage_const_2 
b=vector([delta,_sage_const_1 -_sage_const_2 *delta,delta])
print(b)
d=b*Ai
print(d.n())
outb(_sage_const_3 ,d.n())
