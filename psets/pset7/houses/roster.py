from cs50 import SQL
import sys


def main():

    # check command-line arguments
    if len(sys.argv) != 2:
        print("Usage: python roster.py <house>")
        sys.exit(1)

    # open database
    db = SQL("sqlite:///students.db")

    # query database for all students in house
    # students should be sorted alphabetically by last name, then first name
    house = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last, first", sys.argv[1])

    # print out each student's full name and birth year
    for student in house:
        # get name from three columns
        name = parse_name(student['first'], student['middle'], student['last'])

        # print message
        print(f"{name}, born {student['birth']}")


# helper method to parse name
def parse_name(first, middle, last):
    name = first

    # include middle name only if necessary
    if middle != None:
        name += ' ' + middle

    # add last name
    name += ' ' + last

    # return name
    return name


main()