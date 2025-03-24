def task_0(list):
    output=[]
    for i in range(1,len(list)):
        if list[i-1]<list[i]:
            output.append(list[i])
    return output

def task_1(list):
    mx=list.index(max(list))
    mn=list.index(min(list))
    tmp=list[mx]
    list[mx]=list[mn]
    list[mn]=tmp
    return list

def task_2(list1,list2):
    n=0
    for i in list1:
        if i in list2:
            n+=1
    return n

def task_3(list):
    lib={}
    for i in list:
        if lib.get(i)==None:
            lib[i] = 0
        lib[i]+=1


    return lib


def main():
    lst=[1,2,3,3,5,2,3,5,6,4,8]
    print(task_3(lst))
    print(task_0(lst))
    print(task_2([231132,543,324,22,0,2],[543,2319,0,0,54,4]))
    print(task_1([231132,543,324,22,0,2]))


main()