#1 задание
dc = dict

dc={'Hello' : 'Hi', 'Bye' : 'Goodbye', 'List' : 'Array'}

def input(key):
    return dc[key]

print(input('Bye'))
#2 задание

def findKey(value):
    for i,v in dc.items():
        if v==value:
            return i
print(findKey('Goodbye'))

#4 задание
def biggest(s):
    count_dict = {}
    for char in s:
        num = int(char)
        if num in count_dict:
            count_dict[num] += 1
        else:
            count_dict[num] = 1
    count_dict = sorted(count_dict.items(), key=lambda x: (-x[1], x[0]))
    top_three = count_dict[:3]
    return dict(top_three)

print(biggest("124637863128972322132121111"))