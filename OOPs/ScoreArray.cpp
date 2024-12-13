#include <bits/stdc++.h>
using namespace std;

long long findScore(vector<int>& nums) {
        int score = 0;
        int n = nums.size();
        vector<bool> marked(n, false);

        while(true){
            int minVal = INT_MAX;
            int minIndex = -1;
            for(int i =0; i<n; i++){
                if(!marked[i] && nums[i]< minVal){
                    minVal = nums[i];
                    minIndex = i;
                }
            }
            if(minIndex == -1){
                break;
            }
            score =  score + nums[minIndex];
            //marked the element adjacent element 
            marked[minIndex] = true;
            if(minIndex>0){
                marked[minIndex -1] = true;
            }
            if(minIndex < n-1){
                marked[minIndex +1] = true;
            }
        }
        return score;
    }

int main(){
    vector<int> nums = {2,1,3, 4, 5, 2};
    cout << "output: " << findScore(nums) << endl;
    return 0;
}