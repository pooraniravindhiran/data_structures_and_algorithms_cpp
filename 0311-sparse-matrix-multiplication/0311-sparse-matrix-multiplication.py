# SC- O(m+n)
# TC- O(MK + KN + MNL) where L is number of non zero elements

class Solution:
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:
        # Represent the 1st matrix in CSR format and 2nd matrix in CSC format
        def to_csr(mat):
            rows, cols, data = [], [], []
            rows.append(0)
            for r in range(len(mat)):
                for c in range(len(mat[0])):
                    if mat[r][c]!=0:
                        cols.append(c)
                        data.append(mat[r][c])
                rows.append(len(data)) 
            return rows, cols, data
        
        def to_csc(mat):
            rows, cols, data = [], [], []
            cols.append(0)
            for c in range(len(mat[0])):
                for r in range(len(mat)):
                    if mat[r][c]!=0:
                        rows.append(r)
                        data.append(mat[r][c])
                cols.append(len(data)) 
            return rows, cols, data

        rows1, cols1, data1 = to_csr(mat1)
        rows2, cols2, data2 = to_csc(mat2)

        # print(rows1, cols2, data2)

        # multiply given representations
        r1, c1 = len(mat1), len(mat1[0])
        r2, c2 = len(mat2), len(mat2[0])
        ans = [[0]*c2 for _ in range(r1)]
        
        for i in range(r1):
            for j in range(c2):
                p1 = rows1[i]
                p1_end = rows1[i+1]
                p2 = cols2[j]
                p2_end = cols2[j+1]

                dot_pdt = 0
                while p1<p1_end and p2<p2_end:
                    if cols1[p1] == rows2[p2]:
                        dot_pdt += data1[p1]*data2[p2]
                        p1 += 1
                        p2 += 1
                    elif cols1[p1]<rows2[p2]:
                        p1 += 1
                    else:
                        p2 += 1
                ans[i][j] = dot_pdt
        
        return ans


        