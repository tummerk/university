from math import factorial

def task_1():
    mx,mn=0,0
    a=int(input())
    b = int(input())
    c = int(input())
    if a<b:
        tmp=b
        b =a
        a=tmp
    if a>=c:
        mx=a
    else:
        mx=c
    if b<=c:
        mn=b
    else:
        mn=c
    print(mx,mn)

def task_2():
    n=int(input())
    string=""
    for i in range(1,n+1):
        string+=str(i)
    print(string)
    for i in range(n,1,-1):
        string=string[:-(len(str(i)))]
        print(string)
def task_21mod():
    n = int(input())
    length=len(str(n))
    string = ""
    for i in range(1, n + 1):
        string += (str(i)+(length-len(str(i+1)))*" ")
    print(string)
    for i in range(n,1,-1):
        string=string[:-length]
        print(string)

def task_22mod():
    n = int(input())
    length=len(str(n))
    string = ""
    extraspace=""
    for i in range(n,1,-1):
        string += (str(i)+(length-len(str(i)))*" ")
    string+="1"
    string+=(string[:-1])[::-1]
    print(string)
    for i in range(n):
        extraspace+=(" "*length)
        string=string[length:-length]
        print(extraspace+string)

def task_3():
    n = int(input())
    string=""
    for i in range(n+1):
        string+=(str(int(factorial(n)/(factorial(i)*factorial(n-i))))+" ")
    print(string)



def main():
    task_1()
    task_21mod()
    task_22mod()
    task_3()
main()
