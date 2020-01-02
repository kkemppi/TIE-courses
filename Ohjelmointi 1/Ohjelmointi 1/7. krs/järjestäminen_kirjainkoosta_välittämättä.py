def sort_neglecting_case(list):
    list_sorted = sorted(list, key = lambda list: list.lower())
    return list_sorted