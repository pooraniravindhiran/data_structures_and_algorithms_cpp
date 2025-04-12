// TC- O(1)
// SC- O(1)

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ((n&0x0000ffff)<<16) | ((n&0xffff0000)>>16);
        n = ((n&0x00ff00ff)<<8) | ((n&0xff00ff00)>>8);
        n = ((n&0x0f0f0f0f)<<4) | ((n&0xf0f0f0f0)>>4);
        n = ((n&0x33333333)<<2) | ((n&0xcccccccc)>>2);
        n = ((n&0x55555555)<<1) | ((n&0xaaaaaaaa)>>1);
        return n;
    }
};

// class Solution {
// public:
//     uint32_t reverseBits(uint32_t n) {
//         uint32_t res =0; int power =31;
//         while(n){
//             res |= ((n&1)<<power);
//             n = n>>1;
//             power -=1;
//         }
//         return res;
//     }
// };