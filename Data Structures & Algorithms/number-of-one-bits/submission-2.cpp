class Solution {
public:
    int hammingWeight(uint32_t n) {
       int res = 0;
       int temp = 1;
       int count = 0;
        while(temp <= n){
            
            if(((temp & n) >> count) == 1 ){
                res++;
            }
            temp = temp << 1;
            count++;
        }
        return res;
    }
};
