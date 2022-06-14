/*
leetcode link - https://leetcode.com/problems/permutation-sequence/
*/

    //we also can do by genarating all permutations and sort and return k-1 string from ans vector -T.C=O(2^n *n)+o(2^n log 2^n)
    //T.C=O(N^2)
    string getPermutation(int n, int k) {
        k=k-1;
        int fact=1;
        vector<int>v;
        for(int i=1;i<n;i++){//O(N)
            fact*=i;
            v.push_back(i);
        }
        v.push_back(n);
        string s="";
        //O(N^2)
        while(v.size()>0){//O(N)
            int i=k/fact;
            s+=to_string(v[i]);
            v.erase(v.begin()+i);//O(N)
            k=k%fact;
            if(v.size())
            fact=fact/v.size();
        }
        return s;
    }
