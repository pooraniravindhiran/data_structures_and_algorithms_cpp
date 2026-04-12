# TC- O(mk+kn+mnl)
# SC- O(m+n+nz1+nz2)

class Solution:
    def multiply(self, mat1: List[List[int]], mat2: List[List[int]]) -> List[List[int]]:

        def to_csr(mat1):
            rows1, cols1, data1 = [], [], []
            r1, c1 = len(mat1), len(mat1[0])
            rows1.append(0)

            for i in range(r1):
                for j in range(c1):
                    if mat1[i][j]!=0:
                        cols1.append(j)
                        data1.append(mat1[i][j])
                rows1.append(len(data1))

            return rows1, cols1, data1

        def to_csc(mat2):
            rows2, cols2, data2 = [], [], []
            r2, c2 = len(mat2), len(mat2[0])
            cols2.append(0)

            for j in range(c2):
                for i in range(r2):
                    if mat2[i][j]!=0:
                        rows2.append(i)
                        data2.append(mat2[i][j])
                cols2.append(len(data2))
                
            return rows2, cols2, data2

        rows1, cols1, data1 = to_csr(mat1)
        rows2, cols2, data2 = to_csc(mat2)

        # print(rows1, cols1, data1, rows2, cols2, data2)

        res = [[0]*len(mat2[0]) for _ in range(len(mat1))]
        for i in range(len(mat1)):
            for j in range(len(mat2[0])):

                dot_pdt = 0
                p1 = rows1[i]
                p1_end = rows1[i+1]
                p2 = cols2[j]
                p2_end = cols2[j+1]

                while p1<p1_end and p2<p2_end:
                    if cols1[p1] == rows2[p2]:
                        dot_pdt += data1[p1]*data2[p2]
                        p1 += 1
                        p2 += 1
                    elif cols1[p1]<rows2[p2]:
                        p1 += 1
                    else:
                        p2 += 1
                
                res[i][j] = dot_pdt

        return res