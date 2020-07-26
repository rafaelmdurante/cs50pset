import re

def main():
    print("Type your text: ", end="")
    text = input()
    index = readability(text)
    print(f"{index}")

def readability(text):
    # count words
    wordlist = text.split(' ')
    words = len(wordlist)

    # count letters
    letters = 0
    for word in wordlist:
        for letter in word:
            if re.match('[a-zA-Z]', letter):
                letters += 1

    # count sentences
    sentences = 0
    sentences += (text.count('.') + sentences + text.count('?') + text.count('!'))

    # apply index
    L = letters * 100 /  words
    S = sentences * 100 / words
    index = 0.0588 * L - 0.296 * S - 15.8

    result = ""

    if index > 16:
        result = 'Grade 16+'
    elif index < 1:
        result = 'Before Grade 1'
    else:
        result = 'Grade {}'.format(round(index))

    return result

main()