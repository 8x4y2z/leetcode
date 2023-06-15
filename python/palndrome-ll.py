

class ListNode(object):
    def __init__(self, val="", next=None):
        self.val = val
        self.next = next

    def __str__(self):
        return str(self.val)

def assign(node_a:"ListNode",node_b:"ListNode" ):
    tmp = ListNode()
    tmp.val = node_b.val
    tmp.next = node_b.next

    node_a.val = tmp.val
    node_a.next = tmp.next


class Solution(object):
    def isPalindrome(self, head:"ListNode"):
        """
        :type head: ListNode
        :rtype: bool
        """
        currentNode:"ListNode" = ListNode("")
        midNode: "ListNode" = ListNode("")
        nextNode: "ListNode" = ListNode("")
        prevNode: "ListNode" = ListNode("")

        l = 1
        n = 0 # current pos
        m = 0 # pos from mid-point
        even = 0
        result:bool = False

        # Get length of the list
        assign(currentNode,head)

        while (currentNode.next):
            l += 1
            assign(currentNode,currentNode.next)

        if l==1:
            return True

        if l==2:
            return head.val == head.next.val

        if not l%2:
            even = 1
        m = l//2

        # find midnode
        assign(currentNode,head)
        while(n!=m+1):
            assign(currentNode, currentNode.next)
            n += 1

        n = 0 # reset n to 0
        assign(midNode,currentNode)

        # reverse only 2nd half
        # import pdb; pdb.set_trace()
        while(midNode.next):
            assign(nextNode, midNode.next)

            assign(midNode.next, prevNode)

            assign(prevNode, midNode)

            assign(midNode, nextNode)

        midNode.next = prevNode # Just replace next pointer, val is already correct

        # Now compare
        assign(currentNode, head)
        if m == 1:
            result = currentNode.val == midNode.val
        # for even length stop before middle
        if even:
            m = m-1

        for _ in range(m):
            result = currentNode.val == midNode.val
            if not result:
                return result
            assign(currentNode, currentNode.next)
            assign(midNode, midNode.next)

        # additional check for even
        if even:
            result = currentNode.val == currentNode.next.val
        return result

class LinkedList:
    def __init__(self,val=None):
        "docstring"
        self._headNode = None
        if val is not None:
            if isinstance(val,ListNode):
                self._headNode = val
            else:
                self._headNode = ListNode(val)

    def empty(self):
        return self._headNode == None

    def add_front(self,val):
        node = ListNode(val)
        if self._headNode is not None:
            node.next = self._headNode
        self._headNode = node

    def front(self):
        return self._headNode.val

    def remove_front(self):
        self._headNode = self._headNode.next

    def frontNode(self):
        return self._headNode

    def reverse(self):
        midNode = self._headNode
        prevNode = ListNode()
        nextNode = ListNode()
        while(midNode.next):
            nextNode.val = midNode.next.val
            nextNode.next = midNode.next.next

            midNode.next.val = prevNode.val
            midNode.next.next = prevNode.next

            prevNode.val = midNode.val
            prevNode.next = midNode.next

            midNode.val = nextNode.val
            midNode.next = nextNode.next

        midNode.next = prevNode
        # midNode.next.next = prevNode.next.next
        self._headNode = midNode

    def __str__(self):
        node = self._headNode
        string = ""
        if node is not None:
            string += str(node.val) + "--"
        while (node is not None and node.next is not None and node.next.val != ""):
            node = node.next
            string += str(node.val)
            string += "--"
        return string[:-2]


def main():
    """
    """
    ll = LinkedList("a")
    ll.add_front("b")
    ll.add_front("c")
    ll.add_front("d")
    ll.add_front("e")
    print(ll)
    result = Solution().isPalindrome(ll.frontNode())
    print("list is palindrome ",result)

    print("-"*80)

    ll = LinkedList("a")
    ll.add_front("b")
    ll.add_front("c")
    ll.add_front("d")
    ll.add_front("e")

    ll.add_front("e")
    ll.add_front("d")
    ll.add_front("c")
    ll.add_front("b")
    ll.add_front("a")
    print(ll)
    result = Solution().isPalindrome(ll.frontNode())
    print("list is palindrome ",result)

    print("-"*80)

    ll = LinkedList("a")
    ll.add_front("b")
    ll.add_front("c")
    ll.add_front("d")
    ll.add_front("e")
    ll.add_front("f")
    ll.add_front("e")
    ll.add_front("d")
    ll.add_front("c")
    ll.add_front("b")
    ll.add_front("a")
    print(ll)
    result = Solution().isPalindrome(ll.frontNode())
    print("list is palindrome ",result)

    print("-"*80)

    ll = LinkedList("a")
    ll.add_front("b")
    ll.add_front("a")
    print(ll)
    result = Solution().isPalindrome(ll.frontNode())
    print("list is palindrome ",result)

    print("-"*80)

    ll = LinkedList("a")
    ll.add_front("b")
    ll.add_front("b")
    print(ll)
    result = Solution().isPalindrome(ll.frontNode())
    print("list is palindrome ",result)

    print("-"*80)

    ll = LinkedList("a")
    ll.add_front("b")
    print(ll)
    result = Solution().isPalindrome(ll.frontNode())
    print("list is palindrome ",result)

    print("-"*80)

    ll = LinkedList("b")
    ll.add_front("b")
    print(ll)
    result = Solution().isPalindrome(ll.frontNode())
    print("list is palindrome ",result)

    print("-"*80)

    ll = LinkedList("b")
    ll.add_front("b")
    ll.add_front("a")
    ll.add_front("a")
    ll.add_front("b")
    print(ll)
    result = Solution().isPalindrome(ll.frontNode())
    print("list is palindrome ",result)

    print("-"*80)

    ll = LinkedList("b")
    ll.add_front("a")
    ll.add_front("a")
    ll.add_front("b")
    ll.add_front("b")
    print(ll)
    result = Solution().isPalindrome(ll.frontNode())
    print("list is palindrome ",result)

    print("-"*80)

    ll = LinkedList("b")
    ll.add_front("b")
    ll.add_front("a")
    ll.add_front("b")

    print(ll)
    result = Solution().isPalindrome(ll.frontNode())
    print("list is palindrome ",result)

    print("-"*80)

    ll = LinkedList(1)
    ll.add_front(0)
    ll.add_front(1)
    ll.add_front(1)

    print(ll)
    result = Solution().isPalindrome(ll.frontNode())
    print("list is palindrome ",result)

    print("-"*80)

    ll = LinkedList(1)
    ll.add_front(1)
    ll.add_front(2)
    ll.add_front(1)
    ll.add_front(2)
    ll.add_front(2)

    print(ll)
    result = Solution().isPalindrome(ll.frontNode())
    print("list is palindrome ",result)



if __name__ == '__main__':
    main()
