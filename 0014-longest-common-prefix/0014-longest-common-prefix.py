# TC- O(nl)
# SC- O(nl)

class Solution:

    class TrieNode:
        def __init__(self):
            self.children = {}
            self.is_end = False
    
    def __init__(self):
        self.root = self.TrieNode()

    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        # building trie
        for word in strs:
            curr = self.root

            for letter in word:
                if letter not in curr.children:
                    curr.children[letter] = self.TrieNode()
                curr = curr.children[letter]
            curr.is_end = True
        
        # inspect
        prefix = []
        curr = self.root
        while True:

            if len(curr.children)!=1 or curr.is_end:
                break

            ch = next(iter(curr.children)) # ch = list(curr.children.keys())[0]
            prefix.append(ch)
            curr = curr.children[ch]

        return "".join(prefix)

