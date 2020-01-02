def are_all_members_same(lista):
    pituus = len(lista)
    i = 0
    j = i+1
    while i <= pituus:
        if i == pituus or j > pituus-1:
            return True
        else:
            eka = lista[i]
            toka = lista[j]
            if eka != toka:
                return False
            else:
                i += 1
                j += 1

