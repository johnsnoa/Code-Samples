class Node(object):
    def __init__(self, val):
        self.val = val
        self.next = None

    def get_data(self):
        return self.val

    def set_data(self, val):
        self.val = val

    def get_next(self):
        return self.next

    def set_next(self, next):
        self.next = next

class LinkedList(object):
    def __init__(self, head=None):
        self.head = head
        self.count = 0

    def get_count(self):
        return self.count

    def insert_tail(self, data):
        # TODO: insert a new node at the tail
        
        new_node = Node(data)
        last_node = self.head 
        
        if self.count == 0:
            self.head = new_node       
        else:
            while last_node.get_next() != None :
                last_node = last_node.get_next()
            last_node.set_next(new_node)

        self.count = self.count + 1

    def insert(self, data):
        # TODO: insert a new node at the head
        new_node = Node(data)
        new_node.set_next(self.head)
        self.head = new_node
        self.count = self.count + 1

        
    
    def find(self, val):
        item = self.head
        while item != None :
            if item.get_data() == val :
                return item
            item = item.get_next()
        return None

    def deleteAt(self, idx):
        item = self.head
        if idx > self.count-1:
            return
        if idx == 0:
            self.head = item.get_next()
        else:
            for i in range(idx):
                before = item
                item = item.get_next()
                after = item.get_next()
            before.set_next(after)
        self.count = self.count - 1

    def dump_list(self):
        item = self.head
        while item != None :
            print("Node: ", item.get_data())
            item = item.get_next()

            
            

        