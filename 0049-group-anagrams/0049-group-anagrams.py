# TC- O(nk) where n is number of words and k is max len of one word
# SC- O(nk)
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_map = defaultdict(list)
        for word in strs:
            count = [0]*26
            for ch in word:
                count[ord(ch)-ord('a')] +=1
            anagram_map[tuple(count)].append(word)
        
        return list(anagram_map.values())

# TC- O(nklogk) where n is number of words and k is max len of one word
# SC- O(nk)
# class Solution:
#     def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
#         anagram_map = defaultdict(list)
#         for word in strs:
#             sorted_word = ''.join(sorted(word))
#             anagram_map[sorted_word].append(word)
        
#         return list(anagram_map.values())