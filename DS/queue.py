queue = [None]*5
n = 5
front = 0
rear = -1

def enqueue(item):
    global front
    global rear
    if(rear >= n-1):
        return "Queue overflow"
    else:
        rear += 1
        queue[rear] = item
        print("element inserted!")
        


def dequeue():
    global rear
    global front
    if(front > rear):
        return "Queue Underflow"
    else:
        x = queue[front]
        front += 1
        print("element deleted : ", x)

def display():
    print(" Queue elements:")
    for i in range(front, rear + 1):
        print(queue[i])




enqueue(10)
enqueue(20)
enqueue(30)
enqueue(40)

dequeue()
dequeue()

display()