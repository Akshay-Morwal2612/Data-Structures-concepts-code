n = 5
queue = [None] * n
front = -1
rear = -1

def enqueue(item):
    global front
    global rear
    if (rear +1)%n == front:
        return "Queue overflow"
    else:
        if(front == -1):
            front = 0
            rear = 0
        else:
            rear = (rear+1) % n
        queue[rear] = item
    print("Element inserted:", item)

def dequeue():
    global front
    global rear
    if(front == -1):
        return "Queue Underflow"
    else:
        x = queue[front]
        if(front == rear):
            front = -1
            rear = -1
        else:
            front = (front + 1) % n
        print("Element deleted:", x)


def display():
    if front == -1:
        print("Queue is empty")
    else:
        print("Queue elements:")
        i = front
        while True:
            print(queue[i])
            if i == rear:
                break
            i = (i + 1) % n



enqueue(10)
enqueue(20)
enqueue(30)
enqueue(40)
enqueue(50)



dequeue()
dequeue()
dequeue()
dequeue()

enqueue(60)
enqueue(70)
enqueue(80)

display()