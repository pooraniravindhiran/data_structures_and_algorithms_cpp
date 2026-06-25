# TC- O(logn)
# SC- O(1)

class Solution:
    def reverseBits(self, n: int) -> int:
        
        cache = {}
        def reverse_byte(byte:int)->int:
            if byte in cache:
                return cache[byte]
            
            r = 0
            n = byte
            for _ in range(8):
                r = (r<<1) | (byte&1)
                byte = byte>>1

            cache[n] = r
            return r

        res = 0
        for _ in range(4):
            byte = n & (0xFF)
            res = (res<<8) | reverse_byte(byte)
            n = n>>8
        return res

# # TC- O(1)
# # SC- O(1)

# class Solution:
#     def reverseBits(self, n: int) -> int:
        
#         res = 0
#         power = 31
#         while n:
#             res |= ((n&1)<<power)
#             n = n>>1
#             power -= 1
#         return res