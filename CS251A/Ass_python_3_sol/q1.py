from sys import argv
script, x, y =argv
num=0
i=0
minu=1
dot=0
inv=0
done=0
value={'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'A':10,'B':11,'C':12,'D':13,'E':14,'F':15,'G':16,'H':17,'I':18,'J':19,'K':20,'L':21,'M':22,'N':23,'O':24,'P':25,'Q':26,'R':27,'S':28,'T':29,'U':30,'V':31,'W':32,'X':33,'Y':34,'Z':35}
base={'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'10':10,'11':11,'12':12,'13':13,'14':14,'15':15,'16':16,'17':17,'18':18,'19':19,'20':20,'21':21,'22':22,'23':23,'24':24,'25':25,'26':26,'27':27,'28':28,'29':29,'30':30,'31':31,'32':32,'33':33,'34':34,'35':35,'36':36}
if y in base.keys():
    dod=base[y]
else:
    inv=1
if inv ==0:
    for val in x:
        if val=='.':
            dot+=1
        elif val=='-' and x[0]=='-' and minu==1:
            minu=-1
        elif val in value.keys() and value[val]<base[y] and dot==0:
            num=num*base[y]+value[val]
            done=1
        elif val in value.keys() and value[val]<base[y] and dot==1:
            num=num+1.0*value[val]/dod
            dod=dod*base[y]
            done =1
        else:
            inv=1
if inv != 0 or done==0 or num>9999999999:
    print ('Invalid input')
else:
    print (minu*num)
