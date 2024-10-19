#include <stdio.h>
 
void main()
{
    int heap[10], no, i, j, c, root, temp;
 
printf("\nEnter number of elements (max 10): ");
scanf("%d", &no);
if (no > 10) 
{ 
    printf("Number of elements exceeds the maximum limit of 10.\n");
    return 1; // Exit if the number of elements exceeds the limit
}
    printf("\n Enter the nos : ");
    for (i = 0; i < no; i++)
       scanf("%d", &heap[i]);
    for (i = 1; i < no; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (heap[root] < heap[c])   /* to create MAX heap array */
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
 
    printf("Heap array : ");
    for (i = 0; i < no; i++)
        printf("%d\t ", heap[i]);
    for (j = no - 1; j >= 0; j--)
    {
        temp = heap[0];
        heap[0] = heap[j];   /* swap max element with rightmost leaf element */
        heap[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1;    /* left node of root element */
    if (c < j) 
    { // Check if left child is within bounds
    if (c + 1 < j && heap[c] < heap[c + 1]) // Check if right child exists and is greater
        c++; // Move to the right child
    if (heap[root] < heap[c]) { // Swap if root is less than the largest child
        temp = heap[root];
        heap[root] = heap[c];
        heap[c] = temp;
    }
    root = c; // Move down to the child
}
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < j);
    } 
    printf("\n The sorted array is: ");
    for (i = 0; i < no; i++)
       printf("\t %d", heap[i]);
    printf("\n Complexity : \n Best case = Avg case = Worst case = O(n logn) \n");
}
