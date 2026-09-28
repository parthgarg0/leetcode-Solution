class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp=0, rp=height.size()-1, ans= 0;
        int curwater;
        int ht,wd;
        while (lp<rp){
            ht = min(height[lp],height[rp]);
            wd = std::abs(lp - rp);
            curwater = ht*wd;
            ans=max(curwater,ans);
            height[lp]>height[rp] ? rp-- : lp++ ;
        }
        return ans;
    }
};