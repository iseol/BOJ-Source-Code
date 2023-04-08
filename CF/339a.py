s = input()
lst = []
lst = s.split('+')

last = len(lst)

lst.sort()
for idx, num in enumerate(lst):
    if idx != last-1:
        print(num, end="+")
    else:
        print(num)