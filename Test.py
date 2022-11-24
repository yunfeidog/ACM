import random
x=random.randint(1,3)
n=int(input("请你猜一个数字(1-3):"))
if n==x:
    print("你赢了")
else:
    print("你输了,我想要的是："+x)




