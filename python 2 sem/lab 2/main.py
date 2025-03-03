def task1(s):
    same=1
    new_s=s[0]
    for i in range(1,len(s)):
        if s[i-1]==s[i]:
            same+=1
        else:
            if same!=1:
                new_s+=str(same)
                same=1
                new_s+=s[i]
            else:
                new_s+=s[i]
    return new_s
def task1_1(s):
    new_s=""
    for i in range(len(s)):
        if s[i].isdigit():
            new_s+=s[i-1]*(int(s[i])-1)
        else:
            new_s+=s[i]
    return new_s

def task2(s):
    uniq=set(s)
    cnt={}
    for i in uniq:
        cnt[i]=0
    for i in s:
        cnt[i]+=1
    cnt=sorted(cnt.items(), key=lambda item:item[1],reverse=True)
    return cnt[0][0]+" "+cnt[1][0]+" "+cnt[2][0]

def task3(n):
    if n == 1000:
        print("тысяча")
    else:
        units = ['', 'один', 'два', 'три', 'четыре', 'пять', 'шесть', 'семь', 'восемь', 'девять',
                 'десять', 'одиннадцать', 'двенадцать', 'тринадцать', 'четырнадцать', 'пятнадцать',
                 'шестнадцать', 'семнадцать', 'восемнадцать', 'девятнадцать']
        tens = ['', '', 'двадцать', 'тридцать', 'сорок', 'пятьдесят', 'шестьдесят',
                'семьдесят', 'восемьдесят', 'девяносто']
        hundreds = ['', 'сто', 'двести', 'триста', 'четыреста', 'пятьсот', 'шестьсот',
                    'семьсот', 'восемьсот', 'девятьсот']
        h = n // 100
        remainder = n % 100
        t = remainder // 10
        u = remainder % 10

        parts = []
        if h > 0:
            parts.append(hundreds[h])

        if 10 <= remainder <= 19:
            parts.append(units[remainder])
        else:
            if t > 0:
                parts.append(tens[t])
            if u > 0:
                parts.append(units[u])

        print(' '.join(parts))

def main():
    task3(52)

main()