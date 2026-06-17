# TC- O(eloge)
# SC- O(e) where e is total num of unique emails

class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        
        # connected components problem
        # each email is a vertex and is connected?

        # one name as key and multiple lists as values- this doesnt work if existing lists contain one matching element from new list- so you need to merge existing lists- so connecteed components approach is better

        emails_to_name = {}
        visited = set()
        adj_mat = defaultdict(list)

        for account in accounts:
            name = account[0]
            first_email = account[1]

            for email in account[1:]:
                emails_to_name[email] = name
                adj_mat[email].append(first_email)
                adj_mat[first_email].append(email)

        def dfs(email, component):
            visited.add(email)
            component.append(email)

            for neigh in adj_mat[email]:
                if neigh not in visited:
                    dfs(neigh, component)

        result = []
        for email in emails_to_name:
            if email not in visited:
                component = []
                dfs(email, component)
                result.append([emails_to_name[email]]+sorted(component))
        return result