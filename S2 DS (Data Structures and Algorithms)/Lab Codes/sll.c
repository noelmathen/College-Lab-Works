#include<stdio.h>
#include<stdlib.h>
void main()
{
    struct node
    {
        int data;
        struct node *next;
    };

    struct node *head=NULL, *pos=NULL, *tail=NULL, *temp, *del;
    int ch, entry, number=0, i=0;
    printf("\n*******SINGLY LINKED LIST*******\n\nMENU:-\n\n1. INSERT\n2. DELETE\n3. SEARCH\n4. COUNT\n5. DISPLAY\n6. EXIT\n");
    while(1)
    {   
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: //Insert
            {
                printf("Enter the element to be inserted: ");
                scanf("%d",&entry);
                if(head==NULL)
                {
                  head=(struct node*)malloc(sizeof(struct node));
                  head->data=entry;
                  pos=head;
                  tail=head;
                }
                else
                {
                    tail->next=(struct node*)malloc(sizeof(struct node));
                    tail=tail->next;
                    tail->data=entry;
                }
                number++;
                break;
            }
           
        case 2:   //delete
        {
          if(head==NULL)
          {
            printf("Can't delete. The list is empty!\n");
          }
          else
          {
            printf("Enter the position of the element to be deleted: ");
            scanf("%d",&entry);
            if(entry==0)
            {
              temp=head;
              head=head->next;
              temp->next=NULL;
              printf("The element delted is: %d\n",temp->data);
              free(temp);
              number--;
            }

            else if(entry>0 && entry<number-1)
            {
          	  pos=head;
              for(i=0;i<entry-1;i++)
              {
                pos=pos->next;
              }
              temp=pos;
              del=temp->next;
              temp->next=temp->next->next;
              del->next=NULL;
              printf("The element deleted is: %d\n",del->data);
              free(del);
              number--;
            }

            else if(entry==number-1)
            {
              pos=head;
              for(i=0;i<entry-1;i++)
              {
                pos=pos->next;
              }
              temp=pos;
              tail=pos->next;
              del=tail;
              temp->next=NULL;
              printf("The element deleted is: %d\n",del->data);
              free(del);
              number--;
            }
            else
            {
              printf("ERROR!! There is no element at the entered position!!\n");
            }
          }
          break;
        }
           
            case 3:    //search
            {
                int count=-1;
                printf("Enter the element to be searched: ");
                scanf("%d",&entry);
                pos=head;
                while(pos!=NULL)
                {
                    count++;
                    if(pos->data==entry)
                    {
                        printf("The position of %d is: %d\n",entry,count);
                    }
                    pos=pos->next;
                   
                }
               
                break;
            }
           
            case 4: //count
            {
                int count=0;
                pos=head;
                while(pos!=NULL)
                {
                    pos=pos->next;
                    count++;
                }
                printf("The total number of elements are: %d\n",count);
                break;
            }
           
           
            case 5:    //Display
            {
                printf("\nThe list is: ");
                pos=head;
                while(pos!=NULL)
                {
                    printf("  %d",pos->data);
                    pos=pos->next;
                }
                printf("\n");
                break;
            }
           
           
            case 6:
            {
                printf("OHK BEI!\n");
                exit(0);
            }
            
            default:
            {
            	printf("INVALID INPUT!\n");
            }
        }
    }
}

