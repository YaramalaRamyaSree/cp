/*
gfg link - https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
*/

//T.C:O(N*M)
//S.C:O(1)

void merge(int arr1[], int arr2[], int n, int m)
{ 
    //code here - idea : swap smallest element to correct place and sort the second array 
    int j;
    for(int i=0;i<n;i++){
        if(arr1[i]>arr2[0]){
            int temp=arr2[0];
            arr2[0]=arr1[i];
            arr1[i]=temp;
            int first=arr2[0];
            for(j=1;j<m&&arr2[j]<first;j++)
            {
                arr2[j-1]=arr2[j];
            }
            arr2[j-1]=first;
        }
    }
}

/*
EFFICIENT 
T.C:O(N+M(log(N+M))
S.C:O(1)
USING SHELL SORT INTUTION
*/
int nextGap(int gap)
{
	if (gap <= 1)
		return 0;
	return (gap / 2) + (gap % 2);
}

void merge(int* arr1, int* arr2, int n, int m)
{
	int i, j, gap = n + m,temp;
	for (gap = nextGap(gap);gap >=1; gap = nextGap(gap))
	{
		for (i = 0; i + gap < n; i++)
			if (arr1[i] > arr1[i + gap]){
			    temp=arr1[i+gap];
			    arr1[i+gap]=arr1[i];
			    arr1[i]=temp;
			}
			
		for (j = gap > n ? gap - n : 0;i < n && j < m;
			i++, j++)
			if (arr1[i] > arr2[j])
				{
				temp=arr1[i];
			    arr1[i]=arr2[j];
			    arr2[j]=temp;
				}

		if (j < m) {
			for (j = 0; j + gap < m; j++)
				if (arr2[j] > arr2[j + gap])
					{
			    temp=arr2[j+gap];
			    arr2[j+gap]=arr2[j];
			    arr2[j]=temp;
					}
		}
	}
}
