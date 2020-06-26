# Filter

Function to apply filters to an image.

Most of functions were provided by the staff. Students were supposed to work on `helpers.c` only.

## Development

`VSCode`'s `tasks.json` file has all the commands to build the binary, 
based on `Makefile`, provided by the staff.

### Build

You must have `clang` installed to build the file!

From `VSCode`, open `helpers.c` and press `CTRL + SHIFT + B` to build the file.

That will output a file with no extensions named `filter` only. 

## Usage

From a terminal window, open the project's root folder:

  ```bash
  # apply grayscale
  $ ./filter -g infile.bmp outfile.bmp

  # apply rever
  $ ./filter -r infile.bmp outfile.bmp

  # apply blur
  $ ./filter -b infile.bmp outfile.bmp

  # apply edges
  $ ./filter -e infile.bmp outfile.bmp
  ```

That's it! =)