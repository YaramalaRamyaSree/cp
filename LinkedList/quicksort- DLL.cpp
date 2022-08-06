/*
gfg link - https://practice.geeksforgeeks.org/problems/quicksort-on-doubly-linked-list/1
*/
class solution{
public:
    Node* partition(Node *l, Node *h){
      //key idea **** 1st ele is pivot , 2nd to ith ele<=first , from i+1 to jth ele > first  ,from j+th to last not proceessed . 
        int key=l->data;
        Node* i=l;
        Node* j=i->next;
        while(j!=h->next){
            if(j->data<=key){
                i=i->next;
              //swap(i,j) data part 
                int temp=j->data;
                j->data=i->data;
                i->data=temp;
            }
            j=j->next;
        }
      //swap(first ele or head node data  and i node data)
        int temp=i->data;
        i->data=l->data;
        l->data=temp;
      //hence l data is placed correctly in ith node data; 
        return i;
    }
};

void quickSort(struct Node* l, struct Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Solution ob;
        struct Node *p = ob.partition(l, h);
        quickSort(l, p->prev);
        quickSort(p->next, h);
    }
}
