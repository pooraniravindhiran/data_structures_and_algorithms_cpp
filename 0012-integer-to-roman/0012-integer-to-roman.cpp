// TC- O(1)
// SC- O(1)

class Solution {
private:
    vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

public:
    string intToRoman(int num) {
        string roman = "";
        for(int i=0; i<values.size(); i++){
            while(values[i]<=num){
                num -=values[i];
                roman += symbols[i];
            }
        }
        return roman;
    }
};