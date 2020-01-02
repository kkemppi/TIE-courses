def reverse_name(nimi):
    if nimi == "":
        return ""
    nimet = nimi.split(",")
    etu = nimet[1]
    suku = nimet[0]
    etunimi = etu.strip()
    sukunimi = suku.strip()
    valimerkki = " "
    if etunimi == "" or sukunimi == "":
        valimerkki = ""
    return str(etunimi + valimerkki + sukunimi)


