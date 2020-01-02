def is_the_list_in_order(lista):
    lista2 = sorted(lista)
    if lista2 == lista:
        return True
    else:
        return False
