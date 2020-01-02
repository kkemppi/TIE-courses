def longest_substring_in_order(string):
    string1 = ""
    strings = []
    pituus = len(string)
    viimeinen_indeksi = pituus - 1
    indeksi = 0
    if pituus == 1 or string == "":
        return string
    else:
        for letter in string:
            if string1 == "":
                string1 = letter
            elif string1[-1] < letter:
                string1 += letter
                if viimeinen_indeksi == indeksi:
                    strings.append(string1)
                    return max(strings, key=len)
                print(string1)
            elif string1[-1] > letter:
                strings.append(string1)
                string1 = letter
            indeksi += 1
        print(strings)
        return max(strings, key=len)




