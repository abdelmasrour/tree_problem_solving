
s = "u up up down left left right up up"
x=s[0]
l=[]
cmpt=1
for i in range(1,len(s),1):
        if (s[i]==x):
           cmpt+=1
        else :
              l.append([x,cmpt])
              x=s[i]
              cmpt=1              
print(l)