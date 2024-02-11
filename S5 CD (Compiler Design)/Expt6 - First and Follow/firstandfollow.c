// First and Follow(louis). idk about this. idk anything. fml.
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int n;
struct sym
{
    char s;
}lhs[10],par[10][10],first[10][10],follow[10][10];

struct str
{
    char line[10];
}rhs[10],foll[10];

//to slice the rhs
void slice(char *rs,int i)
{
    char *token;
    n=n+1;
    token = strtok(rs, "/");
    lhs[n].s=lhs[i].s;
    strcpy(rhs[i].line, token );
    token = strtok(NULL, "/");
    strcpy( rhs[n].line, token );
    
}



int firloop(int i,int r,int *l)
{
	int k=0,j=0,lk=*l;
	if(first[i][k].s==0)
        for (int j = 1; j <= n; j++)
        {
            if(lhs[j].s==lhs[i].s)
            {
                first[i][k++].s=rhs[j].line[0];
            }
        }
	k--;
	
	k=0;
	while(isgraph(first[i][k].s))
	{
		if(isupper(first[i][k].s))
		{
			int m=0,h=k;
			for (int j = r; j >0; j--)
			{
				
				if(first[i][k].s==lhs[j].s)
				{	
					
					while(isgraph(first[j][m].s))
					{
						
						first[i][h++].s=first[j][m++].s	;
						
					}
				}
			}
					
			*l+=1;
			if(isupper(rhs[i].line[*l]))
			{
				
				int z=0,f=1;
				while(first[i][z].s>0)
				{
           			if(first[i][z++].s=='#')
           				f=0;
           		}
           		if(f)
           			return 1;
           		h--;
				first[i][h].s=rhs[i].line[*l];
				firloop(i,r,l);
				return 1;	
			}
			else if(islower(rhs[i].line[*l]))
			{
				h--;
				first[i][h].s=rhs[i].line[*l];
				return 1;
			}
		}
		
		k++;
	}
	
}

int follloop(int i,int r)
{
    int k=0;
    char *pt;
    if(i==1)
    {   //rule 1
        foll[i].line[k]='#';
        follow[i][k++].s='$';
    }
    for (int j = 1; j <= n; j++)
    {
        pt=strchr(rhs[j].line,lhs[i].s);
        if(pt!=NULL)
        {
            if(pt[1]<=0 && lhs[j].s!=lhs[i].s)
            {
                //Rule 3.1
                foll[i].line[k]=lhs[j].s;
                
                for(int z=0;z<strlen(foll[j].line);z++)
                {
                    foll[i].line[k]=foll[j].line[z];
                    follow[i][k++].s=follow[j][z].s;
                }
                

            }
            else if(pt[1])   
            {
                
                if(strchr(foll[i].line,pt[1])!=NULL)
                    continue;
                foll[i].line[k]=pt[1];
                int z=0,j;
                for(j=1;j<=r;j++)
                {//find the actual pt[1] in lhs and use that as j)
                    if (lhs[j].s==pt[1])
                        break;    
                }
                while(first[j][z].s>0)
                {
                    if(first[j][z].s=='#')
                    {   
                        //rule 3.2
                        if(strlen(foll[j].line)==0)
                        {
                            follloop(j,r);
                        }
                        for(int y=0;y<strlen(foll[j].line);y++)
                        {
                            foll[i].line[k]=foll[j].line[y];
                            follow[i][k++].s=follow[j][y].s;
                        }
                        break;
                    }
                    //rule 2
                    follow[i][k++].s=first[j][z++].s;
                }
                
                if(!isupper(pt[1]) && strchr(foll[i].line,pt[1])!=NULL)
                {
                   follow[i][k++].s=pt[1];
                }

            }

        }
    }
                       
    foll[i].line[k]='\0';
}

void main()
{
    struct str prod[10];
    int r;
    printf("\n***FIRST AND FOLLOW***\n\n");
    printf("Enter number of rules: ");
    scanf("%d",&r);
    n=r;
    printf("Enter the production rules: \n");
    for(int i=1;i<=r;i++)
        scanf("%s",prod[i].line);
    for(int i=1;i<=r;i++)
    {
        //parse(prod[i].line,i);
        lhs[i].s=prod[i].line[0];
        strcpy(rhs[i].line,prod[i].line+2);
        

    }
    for(int i=1;i<=r;i++)
    { 
        if(strchr(rhs[i].line,'/')!=NULL)
            slice(rhs[i].line,i);
          
    }
    for(int i=r;i>0;i--)
   	{
   		int lk=0;
   		firloop(i,r,&lk);
    }
    printf("\nFIRST:");
    for(int i=1;i<=r;i++)
    {
        int j=0;
        printf("\n%d)%c\t-->",i,lhs[i].s);
        while(first[i][j].s>0)
            printf("%c  ",first[i][j++].s);
        
    }

    printf("\nFOLLOW:");
    for(int i=1;i<=r;i++)
   	{
   		follloop(i,r);
    }
    for(int i=1;i<=r;i++)
   	{
        int j=0;
        printf("\n%d)%c\t-->",i,lhs[i].s);
        while(follow[i][j].s>0)
            printf("%c  ",follow[i][j++].s);
        
    }
    printf("\n");
}

/*
5
E=TE`
E`=+TE`/#
T=FT`
T`=*FT`/#
F=(E)/#

1)E=>TE`
2)E`=>+TE`
3)T=>FT`
4)T`=>*FT`
5)F=>(E)
6)E`=>#
7)T`=>#
8)F=>i

5
E=TX
X=+TX/#
T=FY
Y=*FY/#
F=(E)/i

3
S=Bb/Cd
B=aB/#
C=cC/#

6
S=ABCDE
A=a/#
B=b/#
C=c
D=d/#
E=e/#

*/
