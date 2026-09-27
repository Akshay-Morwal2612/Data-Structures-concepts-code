stack = []* 10
n = 10 
top = -1

def push(item):
    global top
    if(top >= n-1):
        return "stack overflow"
    
    else:
        top += 1
        stack[top] = item
        print("element pushed")

def pop():
    global top
    if top == -1:
        return "stack underflow"
    else:
        x = stack[top]
        top -=1
        print("element poped",x)


def display():
    if top == -1:
        print("stack is empty!")
    else:
        print("stack elements:")
        for i in range (top, -1, -1):
            print(stack[i])

push(10)
push(20)
push(30)

pop()
pop()

display()