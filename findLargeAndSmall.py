list_in = [2,1,3]
max = list_in[0]
min = list_in[0]
i = 1 
while i < 3:
    if list_in[i] > max:
        max = list_in[i]
    if list_in[i] < min:
        min = list_in[i]
    i = i +1;
print(f'Max: {max}')
print(f'Min: {min}')
