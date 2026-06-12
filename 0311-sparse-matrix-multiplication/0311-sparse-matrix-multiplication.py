# TC- O(mk+kn+n*nnz1+m*nnz2)
# SC- O(m+n+nnz1+nnz2)

class Solution:
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        
        # store one matrix in csr and another in csc
        def to_csr(mat):
            m, n = len(mat), len(mat[0])
            rows, cols, data = [], [], []
            rows.append(0)
            for i in range(m):
                for j in range(n):
                    if mat[i][j]!=0:
                        data.append(mat[i][j])
                        cols.append(j)
                rows.append(len(cols))
            return rows, cols, data

        def to_csc(mat):
            m, n = len(mat), len(mat[0])
            rows, cols, data = [], [], []
            cols.append(0)
            for j in range(n):
                for i in range(m):
                    if mat[i][j]!=0:
                        data.append(mat[i][j])
                        rows.append(i)
                cols.append(len(rows))
            return rows, cols, data
        
        rows1, cols1, data1 = to_csr(mat1)
        rows2, cols2, data2 = to_csc(mat2)
        # print(rows1, cols1, data1)
        # print(rows2, cols2, data2)

        m, k = len(mat1), len(mat1[0])
        k, n = len(mat2), len(mat2[0])
        ans = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                dot_pdt = 0
                p1, p2 = rows1[i], cols2[j]
                while p1<rows1[i+1] and p2<cols2[j+1]:
                    if cols1[p1] == rows2[p2]:
                        dot_pdt += (data1[p1]*data2[p2])
                        p1 += 1
                        p2 += 1
                    elif cols1[p1]<rows2[p2]:
                        p1 += 1
                    else:
                        p2 += 1
                ans[i][j] = dot_pdt
        return ans


