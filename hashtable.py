class Pair(object):
    def __init__(self, key, value):
        self.key = key
        self.value = value
    
    def get_key(self):
        return self.key

    def get_value(self):
        return self.value

    def set_key(self, key):
        self.key = key

    def set_value(self, value):
        self.value = value

class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next

    def set_data(self, data):
        self.data = data

    def set_next(self, next):
        self.next = next

class HashTable(object):
    def __init__(self):
        self.count = 0
        self.head = None

    def add(self, key, value):
        node = self.head
        if(self.head == None):
            self.head = Node(Pair(key, value))
        else:
            while(node != None):
                if(node.get_data().get_key() == key):
                    if node.get_data().get_value() < value:
                        node.set_data(Pair(key, value))
                    return
                before = node
                node = node.get_next()
            before.set_next(Node(Pair(key, value)))
            self.count = self.count + 1
            
    def get(self, key):
        node = self.head
        while(node != None):
            if node.get_data().get_key() == key:
                return node.get_data().get_value()
            node = node.get_next()
        return None

    def delete(self, key):
        node = self.head
        if self.head.get_data().get_key() == key:
                self.head = self.head.get_next()
                self.count = self.count - 1
                return
        while(node.get_next() != None):
            before = node
            node = node.get_next()
            if node.get_data().get_key() == key:
                before.set_next(node.get_next())
                self.count = self.count - 1
                return                