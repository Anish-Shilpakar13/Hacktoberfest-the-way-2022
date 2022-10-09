
n = int (input ("Enter a number to find Factorial:"))
factorial = 1
if n >= 1:
    for i in range (1, n+1):
        factorial = factorial *i

print ("Factorial of the given number is: ", factorial)
