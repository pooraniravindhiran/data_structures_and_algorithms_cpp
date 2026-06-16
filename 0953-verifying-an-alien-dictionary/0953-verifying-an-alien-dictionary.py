# TC- O(n)
# SC- O(1)

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:

        rank = {ch:i for i, ch in enumerate(order)}

        def compare(first_word, second_word):

            for j in range(min(len(second_word), len(first_word))):
                if rank[first_word[j]]==rank[second_word[j]]:
                    continue
                else:
                    return  rank[first_word[j]]<rank[second_word[j]]
            
            return len(first_word)<=len(second_word)   

        for i in range(len(words)-1):
            if not compare(words[i], words[i+1]):
               return False
        return True    