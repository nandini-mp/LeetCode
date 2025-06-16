class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count1=0,count2=0,el1=INT_MIN,el2=INT_MIN; //count and count2 for tracking counts of elements, el1 and el2 for storing the majority of elements
        for (int i=0;i<n;i++)
        {
            if (count1==0 && el2!=nums[i]) //count1 is 0 and current element is not el2 (we have filled only one majority element, the other one is vacant), then store the current element as el1 along with increasing count1 to 1
            {
                count1=1;
                el1=nums[i];
            }
            else if (count2==0 && el1!=nums[i])
            {
                count2=1;
                el2=nums[i];
            }
            else if (nums[i]==el1) count1++;
            else if (nums[i]==el2) count2++;
            else
            {
                count1--; //current element is neither majority element el1 nor el2
                count2--;
            }
        }
        vector<int> res;
        //manually check if stored elements in el1 and el2 are majority elements
        count1=0,count2=0;
        for (int i=0;i<n;i++)
            if (nums[i]==el1)
                count1++;
            else if (nums[i]==el2)
                count2++;
        int moreThanNBy3=int(n/3)+1;
        if (count1>=moreThanNBy3) res.push_back(el1);
        if (count2>=moreThanNBy3) res.push_back(el2);
        return res;
    }
};