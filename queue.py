class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None
    
    def get_data(self):
        return self.data
    
    def set_data(self, data):
        self.data = data

    def get_next(self):
        return self.next
    
    def set_next(self, next):
        self.next = next

class Queue(object):
    def __init__(self, head=None):
        self.head = head
        self.count = (0 if head == None else 1)

    def get_count(self):
        return self.count

    #Pushes item onto the back 
    def enqueue(self, val):
        last_item = self.head
        if(self.count == 0):
            self.head = Node(val)
        else:
            while(last_item.get_next() != None):
                last_item = last_item.get_next()
            last_item.set_next(Node(val))
        self.count = self.count + 1

    #Peeks the value at the front
    def peek(self):
        if(self.head == None):
            return
        return self.head.get_data()

    #Returns and removes the front item
    def dequeue(self):
        if(self.head == None):
            return
        to_pop = self.head.get_data()
        self.head = self.head.get_next()
        self.count = self.count - 1
        return to_pop




