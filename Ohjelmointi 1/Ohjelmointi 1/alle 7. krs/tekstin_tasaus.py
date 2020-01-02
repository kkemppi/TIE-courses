def input_words():
    rows = []
    word_list = []
    row = " "
    print("Enter text rows. Quit by entering an empty row.")
    while row != "":
        row = str(input())
        rows.append(row)
        words = row.split()
        for word in words:
            word = word.strip()
            word_list.append(word)
    return word_list


def min_width_with_spaces(list_of_words):
    # With spaces after every word, except last
    i = 0
    for index_of_word in range(len(list_of_words)):
        i += len(list_of_words[index_of_word])
        if index_of_word == len(list_of_words) - 1:
            return i
        i += 1
    return i


def length_of_words(list_of_words):
    # Length of words in a list
    i = 0
    for word in list_of_words:
        i += len(word)
    return i



def main():
    words = input_words()
    row_width = int(input("Enter the number of characters per line: "))
    row_spaced = []
    i = 0
    while i < len(words):
        # Lisätään sanoja riville kunnes rivi tulee täyteen
        if (min_width_with_spaces(row_spaced) + len(words[i]) + 1) <= row_width:
            row_spaced.append(words[i])
            i += 1
        elif len(row_spaced) > 1: # Kun rivillä on yli yksi sana

            # Rivin täyttämiseen tarvittavien välilyöntien määrä
            space_amount = row_width - length_of_words(row_spaced)

            # Kuinka monta välilyöntiä tulee jokaisen sanan väliin
            minimum_spacing_in_line = (space_amount // (len(row_spaced) - 1))

            # Jääkö tasaluvusta yli
            number_of_extra_spaces = (space_amount % (len(row_spaced) - 1))

            if number_of_extra_spaces == 0: # Jos välilyönnit menee tasan
                print((" " * minimum_spacing_in_line).join(row_spaced))

            else:
                x = 0
                while x < number_of_extra_spaces:
                    row_spaced[x] += " "
                    x += 1

                print((" " * minimum_spacing_in_line).join(row_spaced))

            row_spaced = []

        else:
            # Vain yksi sana rivillä
            print(row_spaced[0])
            row_spaced = []
    # Viimeisen rivin tulostus
    print(" ".join(row_spaced))

main()