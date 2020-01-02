def print_in_accordance_of_values(eng_esp):
    esp_eng = sorted(eng_esp, key=lambda word: eng_esp[word])
    for word in esp_eng:
        print(eng_esp[word], word)
