#!/usr/bin/python
import math
import sys
inp=[]
i=0
for x in sys.argv:
    if(i==0):
        i=1
    else:
        inp.append(int(x))
inp.sort()
l=len(inp)
h=1
maxe=1
while(l>maxe):
    maxe=maxe*2 +1
    h+=1
for level in range(0,h):
    for j in range(0,l):
        n=l
        index=j
        bias=0
        for i in range(0,level):
            bias_prev=(bias if index+1<=bias+int((n+1)/2) else bias+int((n+1)/2))
            n=(int((n-1)/2) if index+1<=bias+int((n+1)/2) else n-int((n+1)/2))
            bias=bias_prev
        if index+1-bias==int((n+1)/2):
            print inp[j],
        else:
            print " "*int(math.log(inp[j])/2.3+1),
    print
