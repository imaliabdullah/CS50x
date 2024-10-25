from cs50 import get_float


def main():
    # Ask how much change is owed
    while True:
        dollars = get_float("Change owed: ")
        if dollars >= 0:
            break

    # Convert dollars to cents
    cents = round(dollars * 100)

    # Calculate the number of quarters, dimes, nickels, and pennies
    quarters = cents // 25
    cents %= 25

    dimes = cents // 10
    cents %= 10

    nickels = cents // 5
    cents %= 5

    pennies = cents

    # Calculate total number of coins
    total_coins = quarters + dimes + nickels + pennies

    # Print the total number of coins
    print(total_coins)


if __name__ == "__main__":
    main()
