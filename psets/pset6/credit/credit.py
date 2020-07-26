# prompt credit card number
print("Enter Card Number: ", end="")
card = input()

# validate the luhn's algorithm
def checksum(cardnum):
    # total sum
    total = 0;

    # multiply every other digit by 2, starting with second-to-last digit
    backwards = cardnum[-2::-2]
    for i in range(len(backwards)):
        product = int(backwards[i]) * 2
        # add those products' digits together
        total += product if product <= 9 else product - 9

    # add the sum to the sum of the digits that weren't multiplied by 2
    forwards = cardnum[-1::-2]
    for j in range(len(forwards)):
        total += int(forwards[j])

    valid = False
    # if the total's last digit is 0, number is valid
    if total % 10 == 0:
        valid = True

    # sets a default value for company
    company = 'INVALID'
    # gets the length of the cardnumber
    length = len(cardnum)
    # gets the first two digits
    digits = int(cardnum[:2:1])

    # find the company if the card number is valid
    if valid:
        if length == 15 and (digits == 34 or digits == 37):
            company = 'AMEX'
        if length == 16 and digits >= 51 and digits <= 55:
            company = 'MASTERCARD'
        if length >= 13 and length <= 16 and digits >= 40 and digits <= 49:
            company = 'VISA'

    print(company)

checksum(card)