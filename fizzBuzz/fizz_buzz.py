# Nathan Welch
# Kattis problem "Fizz Buzz"


s = raw_input()   # takes input, no evaluation
X, Y, last = [int(x) for x in s.split()]  # assigns

for num in range(1, last+1):
    if num % X is 0 and num % Y is 0:
        print("FizzBuzz")
    elif num % X is 0:
        print("Fizz")
    elif num % Y is 0:
        print("Buzz")
    else:
        print(num)

