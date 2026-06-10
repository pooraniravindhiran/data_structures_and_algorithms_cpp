# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        # SC- O(n)
        
        self.stack = []
        # push in reverse so that top of stack has first element
        for ni in reversed(nestedList):
            self.stack.append(ni)
    
    def next(self) -> int:
        # TC- O(1)
        # hasNext ensures top of stack is always an integer
        return self.stack.pop().getInteger()
        
    def hasNext(self) -> bool:
        # if stack is empty, return False. Else, keep iterating until top of stack is integer and return true.
        # TC- amortized O(1)
        
        while self.stack:
            top = self.stack[-1]
            if top.isInteger():
                return True
            
            self.stack.pop()
            for ni in reversed(top.getList()):
                self.stack.append(ni)
                
        return False

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())