T=4
left=2
for i in range(1,100):
    right=left+T*i
    print(left,'->' ,right)
    left+=T*i+1