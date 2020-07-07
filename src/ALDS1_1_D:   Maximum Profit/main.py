# O(n)

n = int(input())
input_list = [int(input()) for i in range(n)]
min_value = input_list[0]
# 減少するケースを考え、入力される可能性がある最大のマイナス値に
profit = -1000000000
for i in input_list[1:]:

    if(profit < (i - min_value)):
        profit = i - min_value
    # print(min_value, i, profit)
    if (min_value > i):
        min_value = i
print(profit)
