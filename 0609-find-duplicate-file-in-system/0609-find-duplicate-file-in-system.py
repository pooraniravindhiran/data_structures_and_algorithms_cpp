# TC- O(m)
# SC- O(m)
# where m is total len of paths including each char inside it

class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        
        files = defaultdict(list)
        for line in paths:
            parts = line.split(' ')
            direc = parts[0]
            for part in parts[1:]:
                part_splits = part.split('(')
                filename =  part_splits[0]
                content = part_splits[1][:-1]
                files[content].append(direc+"/"+filename)
        
        ans = []
        for value in files.values():
            if len(value)>1:
                ans.append(value)
        return ans