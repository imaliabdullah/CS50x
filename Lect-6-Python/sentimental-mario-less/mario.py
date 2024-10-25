def print_row(total_bricks, row_number):
    # Print spaces before the bricks
    for i in range(total_bricks - row_number):
        print(" ", end="")

    # Print bricks
    for i in range(row_number):
        print("#", end='')

    print()


def main():
    # Prompt the user for the pyramid's height
    while True:
        try:
            n = int(input("Height: "))
            if 1 <= n <= 8:
                break
            else:
                print('Height must be between 1 and 8')
        except ValueError:
            print("Invalid input. Please enter an integer")

    for i in range(n):
        print_row(n, i + 1)


if __name__ == "__main__":
    main()
