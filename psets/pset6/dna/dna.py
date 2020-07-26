# handle system args
import sys
# handle csv files
import csv


def main():
    # validate args
    validate_args(sys.argv)
    # calculate short tandem repetitions
    match = find_match(sys.argv[1], sys.argv[2])
    # print match
    print(match)


def validate_args(args):
    # validate amount of args
    if len(args) < 3:
        print('Usage: python dna.py data.csv sequence.txt')
        sys.exit(1)


def find_match(database_file, sequence_file):
    # get list of dicts as database
    database = get_database(database_file)
    # extract the short tandem repetitions based on the first dict
    # since they all have the same keys
    strs = get_strs(database[0])
    # count strs inside a sequence
    strscounter = countstrs(strs, sequence_file)
    # find match
    for person in database:
        matchcounter = 0
        for key in person:
            if key != 'name' and strscounter[key] == int(person[key]):
                matchcounter += 1
        if matchcounter == len(strs):
            return person['name']
    return 'No match'


def get_database(file):
    # open file
    with open(file) as f:
        # open file as a dictionary
        reader = csv.DictReader(f)
        # start a list named database
        database = []
        # iterate over the csv file
        for row in reader:
            database.append(row)
        return database


def get_strs(dictionary):
    strs = []
    for key in dictionary:
        if key != 'name' and key not in strs:
            strs.append(key)
    return strs


def countstrs(strslist, sequence_file):
    # get sequence
    sequence = get_sequence(sequence_file)
    strsdict = {}

    for combination in strslist:
        # counter line
        counter = [0] * len(sequence)

        for i in range(len(sequence) - len(combination), -1, -1):
            j = i + len(combination)

            if sequence[i:j] == combination:
                if j >= len(sequence):
                    counter[i] = 1
                else:
                    counter[i] = counter[j] + 1

        strsdict[combination] = max(counter)

    return strsdict


def get_sequence(file):
    # open file
    with open(file) as f:
        # get sequence and replace newline to nothing so it stores a string
        sequence = f.read().replace('\n', '')
        # return the sequence
        return sequence


main()
