class Solution {
public:
	struct bucket
	{
		/* data */
		int big;
		int small;
		bool flag = false;
		bucket() {
			flag = false;
			big = 1;
			small = 2;
		}
	};
    int maximumGap(vector<int>& n) {
        if(n.size() < 2) return 0;
        int minn = n[0];
        int maxx = n[0];
        int size = n.size();

        for(int i=1; i < size; ++i) {
        	minn = min(minn, n[i]);
        	maxx = max(maxx, n[i]);
        }
        
        int gap = (maxx - minn);
        if(gap == 0) return 0;
        gap /= size -1;
        if(gap == 0) gap = 1;
        //gap--;
        vector<struct bucket> bucs(size+ 10000);
        for(int i = 0; i < size; ++i) {
        	int k = (n[i] - minn) / gap;
        	if(bucs[k].flag == false) {
        		bucs[k].flag = true;
        		bucs[k].big = bucs[k].small = n[i];
        	} else {
        		bucs[k].big = max(bucs[k].big, n[i]);
        		bucs[k].small = min(bucs[k].small, n[i]);
        	}
        }
        int tmax = minn;
        for(int i = 0; i < size+10; i++) {
        	if(bucs[i].flag == false) {
        		continue;
        	} else {
        		gap = max(gap, bucs[i].small - tmax);
        		tmax = bucs[i].big;
        	}
        }
        return gap;
    }
};