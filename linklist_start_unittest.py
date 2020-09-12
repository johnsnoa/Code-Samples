import linklist_start as ll

def test_Node():
    node = ll.Node(1)
    assert (node.get_data() == 1), "Error in function Node.get_data(). Expected 1, received " + node.get_data()
    node.set_data(2)
    assert (node.get_data() == 2), "Error in function Node.set_data(). Expected 2, received " + node.get_data()
    assert (node.get_next() == None), "Error in function Node.get_next(). Expected None, received " + node.get_next()
    node.set_next(ll.Node(3))
    assert (node.get_next().get_data() == 3), "Error in function Node.set_next(). Expected 3, received " + node.get_next().get_data()

def test_LinkedList():
    linklist = ll.LinkedList()
    assert (linklist.head == None), "Error in function LinkedList.__init__(). Expected head = None, received head = " + str(linklist.head)
    linklist.insert(1)
    assert (linklist.head.get_data() == 1), "Error in function LinkedList.insert(). Expected head = Node(1), received head = Node(" + str(linklist.head.get_data()) + ")"
    linklist.deleteAt(0)
    assert (linklist.head == None), "Error in function LinkedList.deleteAt(). Expected head = None, received head = " + str(linklist.head)
    linklist.insert_tail(1)
    assert (linklist.head.get_data() == 1), "Error in function LinkedList.insert_tail(). Expected head.get_data() = 1, received " + str(linklist.head.get_data())
    linklist.insert_tail(2)
    assert (linklist.head.get_next().get_data() == 2), "Error in function LinkedList.insert_tail(). Expected head.get_next().get_data() = 2, received " + str(linklist.head.get_next().get_data())
    assert (linklist.find(2) != None), "Error in function LinkedList.find(). Expected 2 to be present, but it was not found."
    assert (linklist.find(3) == None), "Error in function LinkedList.find(). Expected 3 to not be present, but it was returned."

test_Node()
print("Testing complete for class Node, no failures detected.")
test_LinkedList()
print("Testing complete for class LinkedList, no failures detected.")
