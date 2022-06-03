/*
gfg link - https://practice.geeksforgeeks.org/problems/maximize-the-array3340/1
*/

//T.C=O(NlogN)
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
            set<int>s;
            vector<int>res;
            //store all elements intoset (ascending)
            //then erase first (n) elements from set as we need unique n greater elements
            //the fashion / order we need to return is arr2 elements followed by arr1 
            //and order of elements also should be retained as given arrays order.
            //so we iterate again arr2,arr1 and return res in this order.
            for(int i=0;i<n;i++){
                s.insert(arr1[i]);
                s.insert(arr2[i]);
            }
            while(s.size()>n){
                s.erase(*s.begin());
            }
            for(int i=0;i<n;i++){
                if(s.find(arr2[i])!=s.end()){
                    res.push_back(arr2[i]);
                    s.erase(arr2[i]);
                }
            }
            for(int i=0;i<n;i++){
                if(s.find(arr1[i])!=s.end()){
                    res.push_back(arr1[i]);
                    s.erase(arr1[i]);
                }
            }
            return res;
    }
