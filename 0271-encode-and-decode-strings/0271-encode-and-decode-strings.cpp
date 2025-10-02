// TC- O(n)
// SC- O(n)
// where n is number of total chars in all strings

class Codec {
public:
    // Encodes a list of strings to a single string.
    // you can use delimiters to separate strings, but need to escape it if it is present also.
    // easier method is to append length of string and a symbol, then string.
    string encode(vector<string>& strs) {
        string encoded_str;
        for(auto& s:strs)
            encoded_str += to_string(s.size()) + '#' + s;
        return encoded_str;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded_str;
        int i=0;
        while(i<s.size()){
            string len_str = "";
            string word = "";
            while(s[i]!='#')
                len_str += s[i++];
            i++;
            int len = stoi(len_str);
            while(len>0){
                word += s[i++];
                len--;
            }
            decoded_str.push_back(word);
        }
        return decoded_str;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));