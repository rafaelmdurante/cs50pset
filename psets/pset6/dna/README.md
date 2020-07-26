# DNA

A programme that identifies to whom a sequence of DNA belongs.

## Specification

- Open the CSV file and DNA sequence, read contents into memory.
  - First row of CSV file has `name` as the first `column`, and then STRs for each of the remaining columns.
  - Each remaining row corresponds to a person.
  - Python's `csv` module has a `reader` and `DictReader`.
  - Python's `sys` module gives you access to `sys.argv` for command-line args.
  - Once you've opened a text file `f` using `open(filename)`, use `f.read()`.
- For each STR, compute the longest run of consecutive repeats in the DNA sequence.
  - For each position in the sequence, compute how many times the STR repeats starting at that position.
  - For each position, keep checking successive substring until the STR repeats no longer.
  - `len(s)` in Python will get you the length of the string `s`.
  - `s[i:j]` in Python returns the substring, not including the `jth`.
- Compare the STR counts against each row in the CSV file.
  - Save STR counts in some data structure
  - For each row in the data, check if each STR count matches. If so, print out the person's name.'
  - `int(x)` takes the string and turns it into an integer
  - To confirm a match, you'll need to check every column other than the first one.
- If there is a match, print out the name otherwise "No match".

## Usage

Examples:

```bash
$ python dna.py databases/large.csv sequences/5.txt
# Lavender
```

```bash
$ python dna.py
Usage: python dna.py data.csv sequence.txt
```

```bash
$ python dna.py data.csv
Usage: python dna.py data.csv sequence.txt
```

## Tests

COMMAND                                            | EXPECTED OUTPUT
---------------------------------------------------|----------------
python dna.py databases/small.csv sequences/1.txt  | Bob
python dna.py databases/small.csv sequences/2.txt  | No match
python dna.py databases/small.csv sequences/3.txt  | No match
python dna.py databases/small.csv sequences/4.txt  | Alice
python dna.py databases/large.csv sequences/5.txt  | Lavender
python dna.py databases/large.csv sequences/6.txt  | Luna
python dna.py databases/large.csv sequences/7.txt  | Ron
python dna.py databases/large.csv sequences/8.txt  | Ginny
python dna.py databases/large.csv sequences/9.txt  | Draco
python dna.py databases/large.csv sequences/10.txt | Albus
python dna.py databases/large.csv sequences/11.txt | Hermione
python dna.py databases/large.csv sequences/12.txt | Lily
python dna.py databases/large.csv sequences/13.txt | No match
python dna.py databases/large.csv sequences/14.txt | Severus
python dna.py databases/large.csv sequences/15.txt | Sirius
python dna.py databases/large.csv sequences/16.txt | No match
python dna.py databases/large.csv sequences/17.txt | Harry
python dna.py databases/large.csv sequences/18.txt | No match
python dna.py databases/large.csv sequences/19.txt | Fred
python dna.py databases/large.csv sequences/20.txt | No match

## Submit

From CS50 IDE:

```bash
$ submit50 cs50/problems/2020/x/dna
```

