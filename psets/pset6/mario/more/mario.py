while True:
    # ask for a value
    print("Height: ", end="")

    # wait for user input
    height = input()

    if height.isdigit():
        height = int(height)
        if height >= 1 and height <= 8:
            break


# iterate over each row
for row in range(height):
    spaces = " " * (height - row - 1)
    blocks = "#" * (row + 1)
    print(f"{spaces}{blocks}  {blocks}")