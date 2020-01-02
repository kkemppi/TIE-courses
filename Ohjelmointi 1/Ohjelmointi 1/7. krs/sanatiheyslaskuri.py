def main():
    print("Enter rows of text for word counting. Empty row to quit.")
    row = " "
    counter = {}
    while row != "":
        row = input()
        words = row.split()
        for word in words:
            word = word.lower()
            if word in counter:
                counter[word] += 1
            elif word not in counter:
                counter[word] = 1
    for word in sorted(counter):
        print(word, ":", counter[word], "times")

main()
