# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Master:
#     def guess(self, word: str) -> int:

# TC- O(n)
# SC- O(n)

class Solution:
    def find_match(self, a, b):
        ans = 0
        for i in range(0, len(a)):
            if(a[i]==b[i]):
                ans += 1
        return ans

    def findSecretWord(self, words: List[str], master: 'Master') -> None:

        candidates = words
        exact_matches = 0

        while exact_matches<6:

            # pick a random word from candidates
            word = random.choice(candidates)

            # call master.guess and get exact amtches
            exact_matches = master.guess(word)

            if exact_matches ==6:
                return

            # prune candidates
            candidates = [candidate for candidate in candidates if self.find_match(candidate, word)==exact_matches]