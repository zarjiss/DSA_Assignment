#include<stdio.h>
int main()
{
	int n, choice, pos, new_val, s_val, i, flag;
	printf("Enter the size of array: ");
	scanf("%d", &n);

	int arr[n];

	///Remember that you'll have to insert elements first, before printing, updating, searching and deleting.
	///Check the SAL.exe file to get an idea on how your finished code will run like.

    while(1)
    {
       err:
       printf("\n1.Print \n2.Update\n3.Search\n4.Insert\n5.Delete (bonus)\n0.EXIT");
       printf("\n\nEnter choice: ");
       scanf("%d", &choice);

       if(choice==1)
       {
            printf("\nEnter the index to print: ");
            scanf("%d", &pos);
            printf("\nThe val at index %d: %d", pos, arr[pos]);
       }
	       
       else if(choice==2)
       {
            printf("\nEnter the index to update: ");
            scanf("%d", &pos);
            printf("\nEnter the new value: ");
            scanf("%d", &new_val);
            arr[pos]=new_val;
            printf("The new val at index %d: %d", pos, arr[pos]);
       }

       else if(choice==3)
       {
            ///WRITE CODE OF LINEAR SEARCH

            flag = 0;
            printf("\nEnter the value to search: ");
            scanf("%d",&s_val);
            for (i=0; i<n; i++){
                if (arr[i]==s_val){
                    printf("Value %d found at index %d\n",s_val,i);
                    flag = 1;
                    break;
                }
            }
            if (!flag){
                printf("Value %d not found in the array\n",s_val);
            }
       }

       else if(choice==4)
       {
            printf("\nEnter the value to insert: ");
            scanf("%d", &new_val);
            printf("\nEnter the position (index) to insert: ");
            scanf("%d", &pos);

            ///WRITE CODE OF INSERTION

            if (pos>=0&&pos<n){
                for (i=n-1; i>pos; i--){
                    arr[i]= arr[i-1];
                }
                arr[pos]=new_val;
                printf("Value %d inserted at index %d\n",new_val,pos);
            }
            else{
                printf("\ninvalid index!\n");
            }
       }

       else if(choice==5)
       {
           printf("\nEnter the position (index) to delete from: ");
            scanf("%d", &pos);

            ///WRITE CODE FOR DELETION (OPTIONAL, BUT YOU'LL GET BONUS MARKS)

            if (pos>=0 && pos<n){
                for (i=pos; i<n-1; i++){
                    arr[i]=arr[i+1];
                }
                arr[n-1] = 0; 
                printf("value at index %d delete\n", pos);
            }
            else{
                printf("\ninvalid index!\n");
            }
        }

       else if(choice==0)
            break;
        else
        {
            printf("\nWrong Choice. Enter again.\n\n");
            goto err;
        }
    }
    return 0;
}
