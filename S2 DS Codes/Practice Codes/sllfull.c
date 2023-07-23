#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL, *pos=NULL, *tail=NULL, *temp, *del;
int ch, entry, count, size=0, i;

void main()
{
    printf("\n*******SINGLY LINKED LIST*******\n\nMENU:-\n\n1. INSERT\n2. DELETE\n3. SEARCH\n4. COUNT\n5. DISPLAY\n6. EXIT\n");
    while(1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: //INSERT
            {
                printf("Enter the element to be inserted: ");
                scanf("%d",&entry);
                if(head==NULL)
                {
                    head=(struct node*)malloc(sizeof(struct node));
                    head->data=entry;
                    head->next=NULL;
                    pos=head;
                    tail=head;
                }
                else
                {
                    tail->next=(struct node*)malloc(sizeof(struct node));
                    tail=tail->next;
                    tail->data=entry;
                    tail->next=NULL;
                }
                size++;
                break;
            }

            case 2:
            {
                if(head==NULL)
                {
                    printf("The list is empty! Cannot delete!\n");
                }
                else
                {
                    printf("Enter the position for deletion: ");
                    scanf("%d",&entry);
                    if(entry==0)
                    {
                        del=head;
                        head=head->next;
                        del->next=NULL;
                        printf("The deleted element is: %d",del->data);
                        free(del);
                    }
                    else if (entry>0 && entry<size-1)
                    {
                        pos=head;
                        for(i=0;i<entry-1;i++)
                        {
                            pos=pos->next;
                        }
                        temp=pos;
                        del=pos->next;
                        temp->next=temp->next->next;
                        del->next=NULL;
                        printf("The deleted element is: %d",del->data);
                        free(del);
                    }
                    else if (entry==size-1)
                    {
                        pos=head;
                        for(i=0;i<entry-1;i++)
                        {
                            pos=pos->next;
                        }
                        tail=pos;
                        del=tail->next;
                        tail->next=NULL;
                        printf("The deleted element is: %d",del->data);
                        free(del);
                    }
                    else
                    {
                        printf("Invalid position!\n");
                    }
                    size--;
                }
                break;
            }

            case 3:    //SEARCH
            {
                if(head==NULL)
                {
                    printf("The list is empty! Cannot search!\n");
                }
                else
                {
                    printf("Enter the element to be searched: ");
                    scanf("%d",&entry);
                    count=-1;
                    while(pos!=NULL)
                    {
                        count++;
                        if(pos->data==entry)
                        {
                            printf("The element %d is dound at position %d\n",entry,)
                        }
                    }
                }
            }
            case 5:
            {    if(head==NULL)
                {
                    printf("The list is empty! Cannot delete!\n");
                }
                else
                {
                    printf("The list is: ");
                    pos=head;
                    while(pos!=NULL)
                    {
                        printf("%d  ",pos->data);
                        pos=pos->next;
                    }
                    break;
                }
            }
            default:
            {
                printf("INVALID CHOICE!\n");
            }
        }
    }
}