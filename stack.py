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

class Stack(object):
    def __init__(self, head=None):
        self.head = head
        self.count = (0 if head == None else 1)

    def get_count(self):
        return self.count

    def get_head(self):
        return self.head
    
    def push(self, val):
        val = Node(val)
        if self.head != None:
            val.set_next(self.head)
        self.head = val
        self.count = self.count + 1

    def peek(self):
        if(self.head == None):
            return
        return self.head.get_data()

    def pop(self):
        if(self.head == None):
            return
        top = self.head.get_data()
        self.head = self.head.get_next()
        self.count = self.count - 1
        return top
