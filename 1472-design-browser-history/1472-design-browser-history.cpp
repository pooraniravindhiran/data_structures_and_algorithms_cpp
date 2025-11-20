// SC- O(n)

class BrowserHistory {
private:
    vector<string> history;
    int curr_page;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr_page=0;
    }
    
    void visit(string url) {
        // TC - O(1) Amortized
        // remove forward history if it exists
        if(curr_page<history.size()-1)
            history.resize(curr_page+1);
        
        history.push_back(url);
        curr_page = history.size()-1;
    }
    
    string back(int steps) {
        // TC - O(1)
        curr_page = max(0, curr_page-steps);
        return history[curr_page];
    }
    
    string forward(int steps) {
        // TC- O(1)
        curr_page = min((int)history.size()-1, curr_page+steps);
        return history[curr_page];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

