def main():
    # set height to zero
    height = 0

    # ask for height between 1 to 8
    while height < 1 or height > 8:
        # ash for height
        print('Height (between 1 and 8): ', end='')
        height = input()

    for line in range(height):
        spaces = ' ' * (height - line)
        blocks = '#' * (line + 1)
        print(f"{spaces}{blocks}")

main()
