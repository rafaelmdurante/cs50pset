# Harvard-X CS50

Collection of problem sets for [Harvard's CS50](https://cs50.harvard.edu/x/2020/) online course.

They are written in `C Language`, on `VS Code` IDE.

## Disclaimers

The purpose of this repository is to store my solutions for personal reference only.

As I learn `C` better, I might get back to these files and rewrite them.

Not all problems have an executable file, nor `VS Code` tasks.

## Requirements

In order to compile the code locally you will need [CS50's library](https://cs50.readthedocs.io/libraries/cs50/c/).

Also, a `C` compiler, like `clang` - also in the documentation above.

### VS Code

- When creating `VSCode` tasks, always include `-lcs50` in the argument in `.vscode/tasks.json` as
  in the example below.

  ```json
  {
    "version": "2.0.0",
    "tasks": [
      {
        "args": [
          "-lcs50"
        ],
  }
  ```

