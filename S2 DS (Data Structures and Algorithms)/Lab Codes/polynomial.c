#include <stdio.h>
#include <stdlib.h>
void main()
{	
	struct node
	{
		int data1;
		int data2;
		struct node *next;
	};
	struct node *head1=NULL, *pos1=NULL, *tail1=NULL,*head2=NULL, *pos2=NULL, *tail2=NULL, *head3=NULL, *pos3=NULL, *tail3=NULL;
	int coef,power,i,sumcoef;
	printf("Enter the largest power : ");
	scanf("%d",&power);
	printf("\nFor first polynomial :-\n");
	for(i=power;i>=0;i--)
	{
		printf("Enter Coefficient for x^%d: ",i);
		scanf("%d",&coef);
		if(head1==NULL)
		{
			head1=(struct node*)malloc(sizeof(struct node));
			head1->data1=coef;
			head1->data2=i;
			pos1=head1;
			tail1=head1;
		}
		else
		{
			tail1->next=(struct node*)malloc(sizeof(struct node));
			tail1=tail1->next;
			tail1->data1=coef;
			tail1->data2=i;
		}
	}
	
	printf("\nFor second polynomial :-\n");
	for(i=power;i>=0;i--)
	{
		printf("Enter Coefficient for x^%d: ",i);
		scanf("%d",&coef);
		if(head2==NULL)
		{
			head2=(struct node*)malloc(sizeof(struct node));
			head2->data1=coef;
			head2->data2=i;
			pos2=head2;
			tail2=head2;
		}
		else
		{
			tail2->next=(struct node*)malloc(sizeof(struct node));
			tail2=tail2->next;
			tail2->data1=coef;
			tail2->data2=i;
		}
	}
	for(i=power;i>=0;i--)
	{
		sumcoef=pos1->data1+pos2->data1;
		pos1=pos1->next;
		pos2=pos2->next;
		if(head3==NULL)
		{
			head3=(struct node*)malloc(sizeof(struct node));
			head3->data1=sumcoef;
			head3->data2=i;
			pos3=head3;
			tail3=head3;
		}
		else
		{
			tail3->next=(struct node*)malloc(sizeof(struct node));
			tail3=tail3->next;
			tail3->data1=sumcoef;
			tail3->data2=i;
		}
	}
	printf("\nSum of Polynomials is: ");
	for(i=power;i>=0;i--)
	{
		
		printf("%dx^%d",pos3->data1,pos3->data2);
		if(i!=0)
			printf(" + ");
		pos3=pos3->next;
	}
	printf("\n");
}