# ask for a value
print("Height: ", end="")

# wait for user input
height = int(input())

for row in range(height):
    spaces = " " * (height - row - 1)
    blocks = "#" * (row + 1)
    print(f"{spaces}{blocks}  {blocks}")
