#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_string(char *str,int *length,int typ,int lin)
{
	if(*length>0)
	{
		printf("%.*s\t%s\t",*length,str,(typ==1)?"identifier":"constant");
		printf("%d\n",lin);
		*length=0;
	}
}

int check_indentifier(char *str,int *length,int lin)
{
	if(strncmp(str, "int", 3)==0)
	{
		printf("int\tkeyword \t%d\n",lin);
		*length=0;
		return 0;
	}
	else if(strncmp(str, "void", 4)==0)
	{
		printf("void\tkeyword \t%d\n",lin);
		*length=0;
		return 0;
	}
	else if(strncmp(str, "printf", 6)==0)
	{
		printf("printf\tkeyword \t%d\n",lin);
		*length=0;
		return 0;
	}
	return 1;
}

//key,idn,oper,pun,cons
void main()
{
	char cd[130];
	char str[20];
	int length=0,line=1;
	int typ;
	
	printf("Lexeme\tToken\t\tLine number\n");
	FILE* fptr; 
    fptr = fopen("expression_hard.txt", "r");
    if (fptr == NULL) {
        printf("The file is not opened");
        exit(0);
    }	
    else
    {
    	int begin=0,forward=0,line=1;
    	while(cd[forward]!=EOF)
    	{
    		cd[forward]=getc(fptr);
    		if (cd[forward]=='=' || cd[forward]=='+')
    		{
				print_string(str,&length,typ,line);
    			printf("%c\toperator\t%d\n",cd[forward++],line);
    			begin++;
    			continue;
    		}
    		
    		else if (cd[forward]=='>' || cd[forward]=='<')
    		{
				print_string(str,&length,typ,line);
    			printf("%c\trelational operator\t%d\n",cd[forward++],line);
    			begin++;
    			continue;
    		}
    		
    		else if (cd[forward]=='}' || cd[forward]==')')
    		{
				print_string(str,&length,typ,line);
    			printf("%c\tclosing bracket\t%d\n",cd[forward++],line);
    			begin++;
    			continue;
    		}
    		else if (cd[forward]=='(' || cd[forward]=='{')
    		{
    			if(!check_indentifier(str,&length,line))
					print_string(str,&length,typ,line);
    			printf("%c\topening bracket\t%d\n",cd[forward++],line);
    			begin++;
    			continue;
    		}
    		else if (cd[forward]=='"')
    		{
				print_string(str,&length,typ,line);
    			printf("%c\tdouble quote\t%d\n",cd[forward++],line);
    			while(1)
    			{
    				cd[++forward]=getc(fptr);
    				if(cd[forward]=='"')
    					break;
    				printf("%c",cd[forward]);
	    			begin++;
	    		}
	    		printf("\tstring\t\t%d\n%c\tdouble quote\t%d\n",line,cd[forward++],line);
    			continue;
    		}
    		
    		else if(cd[forward]>='0' && cd[forward]<='9')
    		{	
				typ=0;
				str[length++]=cd[forward++];
    			begin++;
    			continue;
    		}
    		
    		else if(cd[forward]>='a' && cd[forward]<='z')
    		{
				typ=1;
				str[length++]=cd[forward++];
    			begin++;
    			continue;
    		}
    		else if(cd[forward]=='#' || cd[forward]=='.')
    		{	
				print_string(str,&length,typ,line);
    			printf("%c\tspecial symbol\t%d\n",cd[forward++],line);
    			begin++;
    			continue;
    		}
    		else if(cd[forward]==';')
    		{	
				print_string(str,&length,typ,line);
    			printf("%c\tsemicolon\t%d\n",cd[forward++],line);
    			begin++;
    			continue;
    		}
    		
    		else if(cd[forward]==' ' || cd[forward]=='\n')
    		{
				if (cd[forward]=='\n')
					line++;
				if(length!=0)
					if(check_indentifier(str,&length,line))
						print_string(str,&length,typ,line);
    			forward++;
    			begin++;
    			continue;
    		}
    		else
    		{
    			break;
    			forward++;
    			begin++;
    		}
    	}
    }

    fclose(fptr);
    printf("\n");
}
