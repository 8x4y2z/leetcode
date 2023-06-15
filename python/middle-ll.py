
from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next:"ListNode"=None):
        self.val = val
        self.next = next

    def __str__(self):
        return str(self.val)

    def __repr__(self):
        return self.__class__.__name__ + "("+str(self.val) +","+repr(self.next)+")"

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        """
        slow:ListNode = None
        fast:ListNode = None

        slow = fast = head

        while(fast.next is not None and fast.next.next is not None):
            slow = slow.next
            fast = fast.next.next

        # for even move the slow to 1 more
        if fast.next is not None:
            slow = slow.next
        return slow

    def middleNodeFast(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        """
        slow = fast = head

        while(fast is not None and fast.next is not None):
            slow = slow.next
            fast = fast.next.next

        return slow

def create_ll(n):
    ll = [ListNode(x) for x in range(n)]
    for i in range(n-1):
        ll[i].next = ll[i+1]
    return ll[0]

def main():

    head = create_ll(10)
    midNode = Solution().middleNode(head)
    print(repr(head))
    print(midNode)

    head = create_ll(9)
    midNode = Solution().middleNode(head)
    print(repr(head))
    print(midNode)


if __name__ == '__main__':
    main()
