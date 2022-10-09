n=int(input('n: '))
c = 0 
i = 1 
while i < n:
    if n % i == 0:
        c = c+1
    i = i+1
if c == 1:
    print('prime')
else:
    print('not prime')
