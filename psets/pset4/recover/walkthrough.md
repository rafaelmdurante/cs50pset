# WALKTHROUHG

## JPEG

- begin with distinct header:
  0xff, 0xd8, 0xff, 0xe0..0xef

  ```c
  buffer[0] == 0xff
  buffer[1] == 0xd8
  buffer[2] == 0xff
  (buffer[3] & 0xf0) == 0xe0
  ```

- jpeg files need to be in sequence

  ```c
  // Filenames: ###.jpeg, starting at 000.jpg
  sprintf(filename, "%03i.jpg", 2);
  // output 002.jpg
  > FILE *img = fopen(filename, "w"); // write to file
  ```

  - function `sprintf()` prints to a string
  - `%03i` print an integer with 3 digits including zero
  - make sure filename has enough space to represent to full name

## MEMORY CARD

- does not start with jpeg, need to find the start
- jpegs stored back-to-back (one after another)
- each block is 512 bytes
- close block when reach another jpeg header

## OPEN FILES

Use function:

```c
FILE *f = fopen(filename, "r");
```

## READING FILES

Use function:

```c
fread(data, size, number, inputr)
```

- `data`:   pointer to where to store data you're reading
- `size`:   size of each element to read
- `number`: number of elements to read
- `inptr`:  FILE * to read from
- `fread()` returns the number of items of size "size" were read

## WRITING FILES

Use function:

```c
fwrite(data, size, number, outptr);
```

- `data`:   pointer to bytes that will be written to file
- `size`:   size of each element to write
- `number`: number of elements to write
- `outptr`: FILE * to write to

## PSEUDOCODE

- open memory card
- repeat until end of card:
  - read 512 bytes into a buffer
  - if start of new jpeg
    - if first jpeg ...
    - else ...
  - else
    - if already found jpeg
- close any remaining files