#1 задание
f=open("input1.txt")
text1 = f.readline()
arr = list(map(int, text1.split(" ")))
mult=1

for i in arr:
    mult*=i

f=open("output1.txt","w")
f.write(str(mult))

#2 задание
f=open("input2.txt")
arr = f.readlines()
arr=list(map(int,arr))
arr.sort()
arr.reverse()

f=open("output2.txt","w")
f.write(str(arr))

#3 задание
f=open("input3.txt",encoding='utf-8')
arr3 = f.readlines()
group=list()

array=[]

for i in arr3:
    i=i.split(" ")
    i[2]=int(i[2])
    array.append(i)
array=sorted(array,key=lambda x:x[2])
fOld=open("outputOldest.txt","w",encoding='utf-8')
fYoung=open("outputYoungest.txt","w",encoding='utf-8')

fOld.write(str(array[len(array)-1]))
fYoung.write(str(array[0]))