class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
# Queue(큐)
# First In First Out
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
class Queue:
    def __init__(self):
        self.head = None
        self.tail = None
        self.cnt = 0 # 큐의 크기를 저장하는 변수

    def push(self, data):
        new_node = Node(data)
        
        if self.head==None:
            self.head = new_node
            self.tail = new_node      
            self.cnt+=1
        else : 
            current =new_node
            self.tail.next = current
            self.tail = current
            self.cnt+=1

    def empty(self):
        return self.head is None

    def pop(self):
        if self.empty():
            self.tail = None
            self.cnt =0
            return -1
            
        current =self.head
        self.head = current.next
        self.cnt-=1
        return current.data

    def size(self):
        # 큐에 들어있는 정수 개수 출력!!
      
        return self.cnt

    def front(self):
        if self.empty():
            self.tail = None
            self.cnt =0
            return -1
        return self.head.data

    def back(self):
        if self.empty():
            self.tail = None
            self.cnt =0
            return -1
        return self.tail.data
# push X: 정수 X를 큐에 넣는 연산이다.
# pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
# size: 큐에 들어있는 정수의 개수를 출력한다.
# empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
# front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
# back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

N=int(input())
card = Queue()
for i in range(1, N+1):
    card.push(i)

while True:
    if card.size()==1:
        break
    print(card.pop(),end = " ")

    if card.size()==1:
        break
    
    card.push(card.pop())

print(card.pop())