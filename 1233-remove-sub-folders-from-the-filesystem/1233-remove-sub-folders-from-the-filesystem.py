# TC- O(nl)
# SC- O(nl)

class Solution:

    class TrieNode:
        def __init__(self):
            self.is_end = False
            self.children = {}

    def __init__(self):
        self.root = self.TrieNode()

    def removeSubfolders(self, folder: List[str]) -> List[str]:
        
        # add all paths to a trie
        for path in folder:

            curr = self.root
            folders = path.split("/")
            for folder_name in folders:
                if folder_name == "":
                    continue
                
                if folder_name not in curr.children:
                    curr.children[folder_name] = self.TrieNode()
                curr = curr.children[folder_name]

            curr.is_end = True

        # check if any path is a subfolder
        result = []
        for path in folder:

            folders = path.split("/")
            is_subfolder = False
            curr = self.root
            for i, folder_name in enumerate(folders):

                if folder_name=="":
                    continue
                
                next_node = curr.children[folder_name]
                if next_node.is_end==True and i!=len(folders)-1:
                    is_subfolder = True
                    break
                curr = next_node
            
            if is_subfolder==False:
                result.append(path)
        return result


# root 
#     a - end
#         b- end
#     c
#         d- end
#             e- end
#         f- end