from cs50 import SQL

import sys
import csv

if __name__ == "__main__":

    # check command-line arguments
    if len(sys.argv) != 2:
        print("Usage: python import.py <file>.csv")
        sys.exit(1)

    # get database
    db = SQL("sqlite:///students.db")

    # open csv file given by command-line argument
    with open(sys.argv[1], "r") as file:

        # open reader
        reader = csv.DictReader(file)

        # work on each row
        for row in reader:

            # parse name
            name = row['name'].split(' ')
            first = name[0]
            middle = name[1] if len(name) == 3 else None
            last = name[-1]

            house = row['house']
            birth = row['birth']

            # insert each student into the students table of students.db
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", first, middle, last, house, birth)
