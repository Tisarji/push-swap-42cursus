import os

def gen(lsin, out):
    if (len(lsin) == 0):
        print(out)
        os.system(out + " | wc -l")
        return
    l = len(lsin)
    for i in range(l):
        tmp = lsin.copy()
        tmp2 = out[:]
        tmp2 = tmp2 + ' ' + str(tmp.pop(i))
        gen(tmp, tmp2)

ls = [1, 2, 3, 4, 5]
gen(ls, "./push_swap")
#os.system("../push_swap 1 3 2")
