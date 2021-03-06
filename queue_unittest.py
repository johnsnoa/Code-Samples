import queue as q 

def test_Node():
    node = q.Node(1)
    assert (node.get_data() == 1)
    print("[TESTING] Success on get_data()")
    assert (node.get_next() == None)
    print("[TESTING] Success on get_next() on None")
    node.set_next(q.Node(3))
    print("[TESTING] Set next node to be non-None")
    assert (node.get_next() != None)
    print("[TESTING] Success on get_next() on non-None")
    assert (node.get_next().get_data() == 3)
    print("[TESTING] Success on set_next() verified by data")
    print("[TESTING] test_Node() concluded successfully")

def test_Queue():
    empty_queue = q.Queue() 
    queue = q.Queue(q.Node(1))
    assert (empty_queue.peek() == None)
    print("[TESTING] Success on empty_queue.peek()")
    assert (empty_queue.get_count() == 0)
    print("[TESTING] Success on empty_queue.get_count() with zero elements")
    assert (queue.peek() == 1)
    print("[TESTING] Success on queue.peek(), queue.__init__() with one entry")
    assert (queue.get_count() == 1)
    print("[TESTING] Success on queue.get_count(), queue.__init__() with one element")
    queue.enqueue(2)
    queue.enqueue(3)
    assert (queue.get_count() == 3)
    print("[TESTING] Success on queue.get_count() with more than one element")
    assert (queue.peek() == 1)
    print("[TESTING] Success on queue.peek() with more than one element")
    assert (queue.dequeue() == 1)
    print("[TESTING] Success on queue.dequeue() with more than one element")
    assert (queue.get_count() == 2)
    print("[TESTING] Success on queue.get_count() after dequeue")
    assert (queue.dequeue() == 2)
    assert (queue.dequeue() == 3)
    assert (queue.get_count() == 0)
    print("[TESTING] Success on queue.get_count() after emptying queue")
    queue.enqueue(1)
    assert (queue.peek() == 1)
    assert (queue.get_count() == 1)
    print("[TESTING] Success on queue.peek() after repopulating from empty queue")
    print("[TESTING] test_Queue() concluded successfully")


test_Node()
test_Queue()
print("[TESTING] Unit tests concluded successfully")