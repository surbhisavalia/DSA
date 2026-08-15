class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int pvoit = -1;
        for(int i = n - 2; i >= 0; i--)
        {
            if(arr[i] < arr[i + 1])
            {
                pvoit = i;
                break;
            }
        }
        if(pvoit == -1)
        {
            reverse(arr.begin(), arr.end());
            return;
        }
        for(int j = n - 1; j > pvoit; j--)
        {
            if(arr[j] > arr[pvoit])
            {
                swap(arr[j], arr[pvoit]);
                break;
            }
        }
        int i = pvoit + 1;
        int j = n - 1;
        while(i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};