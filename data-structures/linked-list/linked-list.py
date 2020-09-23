"""The LinkedList code from before is provided below.
Add three functions to the LinkedList.
"get_position" returns the element at a certain position.
The "insert" function will add an element to a particular
spot in the list.
"delete" will delete the first element with that
particular value.
Then, use "Test Run" and "Submit" to run the test cases
at the bottom."""

class Element(object):
    def __init__(self, value):
        self.value = value
        self.next = None
        
class LinkedList(object):
    def __init__(self, head = None):
        self.head = head
    
    def append(self, el):
        current = self.head
        while current.next:
            current = current.next
        current.next = el

    def get_position(self, position):
        c = 1
        current = self.head

        if position <= 1:
            return current
        else:
            while current.next and c < position:
                current = current.next
                c += 1
        return current

    def insert(self, el, position):
        c = 1
        current = self.head

        if position > 1:
            while current.next and c < position-1:
                current = current.next
                c += 1
        
        el.next = current.next
        current.next = el
        pass
    
    def delete(self, value):
        current = self.head

        if current.next:
            if current.value != value:
                while current.next and current.next.value != value:
                    current = current.next
                current.next = current.next.next
            else:
                self.head = current.next
        else:
            self.head = None
        pass


# Test cases
# Set up some Elements
e1 = Element(1)
e2 = Element(2)
e3 = Element(3)
e4 = Element(4)

# Start setting up a LinkedList
ll = LinkedList(e1)
ll.append(e2)
ll.append(e3)

# Test get_position
# Should print 3
print (ll.head.next.next.value)
# Should also print 3
print (ll.get_position(3).value)

# # Test insert
ll.insert(e4,3)
# # Should print 4 now
print (ll.get_position(3).value)

# Test delete
ll.delete(1)
# Should print 2 now
print (ll.get_position(1).value)
# Should print 4 now
print (ll.get_position(2).value)
# Should print 3 now
print (ll.get_position(3).value)