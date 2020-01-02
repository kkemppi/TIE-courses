def count_abbas(string):
    string = str(string)
    viimeinen_indeksi = len(string) - 1
    abboja = 0
    i = 0
    while i <= viimeinen_indeksi - 2:
        if string[i] == "a":
            if string[i+1] == "b" and string[i+2] == "b":
                if string[i+3] == "a":
                    abboja += 1
        i += 1
    return abboja


