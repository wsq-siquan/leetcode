class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> h(10005);
        for(int i= 0; i <10005; ++i) {
        	h[i] = 0;
        }
        int size = deck.size();
        if(size < 2) return false;
        int x;
        for(int i= 0; i < size; ++i) {
        	h[deck[i]]+=1;
        }
        x = h[deck[0]];
        for(int i= 0; i < size; ++i) {
        	x = min(x,h[deck[i]]);
        }
        for(int j =2; j <= x; j++) {
        	if(x % j == 0) {
        		bool flag =true;
        		for(int i = 0;  i < 10005; ++i) {
        			if(h[i] % j != 0) {
        				flag = false;
        				break;
        			}
        		}
        		if(flag == true) return true;
        	}            
        }
        return false;
    }
};