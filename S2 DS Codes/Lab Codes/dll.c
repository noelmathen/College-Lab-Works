#include<stdio.h>
#include<stdlib.h>
void main()
{
  struct node
  {
    struct node *prev;
    int data;
    struct node *next;
  };
  
  struct node *head=NULL, *pos=NULL, *tail=NULL, *temp, *del;
  int ch, entry, count=0, i, j;

    printf("\n*******DOUBLY LINKED LIST*******\n\nMENU:-\n\n1. INSERT\n2. DISPLAY(forward)\n3. DISPLAY(backward)\n4. DELETE(at front)\n5. EXIT\n");
  while(1)  
  {  printf("\nEnter your choice: ");
    scanf("%d",&ch);
    
    switch(ch)
    {
      case 1:   //INSERT
      {
        printf("Enter the element to be inserted: ");
        scanf("%d",&entry);
        if(head==NULL)
        {
          head=(struct node*)malloc(sizeof(struct node));
          head->prev=NULL;
          head->data=entry;
          head->next=NULL;
          pos=head;
          tail=head;
        }
        else
        {
          tail->next=(struct node*)malloc(sizeof(struct node));
          tail->next->prev=tail;
          tail->next->data=entry;
          tail->next->next=NULL;
          tail=tail->next;
        }
        count++;
        break;
      }

      case 2:   //display forward
      {
        if(head==NULL)
        {
          printf("The list is empty!\n");
        }
        else
        {
          pos=head;
          printf("The list(forward) is: ");
          while(pos!=NULL)
          {
            printf("%d  ",pos->data);
            pos=pos->next;
          }
        }
        printf("\n");
        break;
      }

      case 3:   //display backward
      {
        if(head==NULL)
        {
          printf("The list is empty!\n");
        }
        else
        {
          pos=tail;
          printf("The list(forward) is: ");
          while(pos!=NULL)
          {
            printf("%d  ",pos->data);
            pos=pos->prev;
          }
        }
        printf("\n");
        break;
      }

      case 4:   //delete
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
            count--;
          }

          else if(entry>0 && entry<count-1)
          {
          	pos=head;
            for(i=0;i<entry-1;i++)
            {
              pos=pos->next;
            }
            temp=pos;
            del=pos->next;
            temp->next=temp->next->next;
            temp->next->prev=temp;
            del->next=NULL;
            del->prev=NULL;
            printf("The element deleted is: %d\n",del->data);
            free(del);
            count--;
          }

          else if(entry==count-1)
          {
            temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            temp->prev=NULL;
            printf("The element delted is: %d\n",temp->data);
            free(temp);
            count--;
          }

          else
          {
            printf("ERROR!! There is no element at the entered position!!\n");
          }
        }
        break;
      }

      case 5:   //exit
      {
        printf("OHK BEI:)\n");
        exit(0);
      }

      default: 
      {
        printf("INVALID INPUT!\n");
      }
    }
  }
}


