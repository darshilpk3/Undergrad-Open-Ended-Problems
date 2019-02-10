#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ans[20000];
int i=0,j=0,ch=0;
long z=0;
void match(const char *replace)
{
	int k;
	for(k=0; replace[k] != '\0';k++)
	{
			ans[z] = replace[k];
			z++;
			ch=i;
	}
}
void kmp_search(const char *text, const char *pattern,const char *replace)
{
	
    int *T;
    T = (int*) malloc((strlen(pattern)+1) * sizeof(int) );
    T[0] = -1;
    for (i=0; pattern[i] != '\0'; i++) 
    {
        T[i+1] = T[i] + 1;
        while (T[i+1] > 0 && pattern[i] != pattern[T[i+1]-1])
            T[i+1] = T[T[i+1]-1] + 1;
    }
	printf("\n LookUp Table");
	printf("\n ____________");
	printf("\n\n");
	for(i=1;i<strlen(pattern)+1;i++)
	{
		printf(" %d",T[i]);
	}
    /* Perform the search */
    for (i=j=0; text[i] != '\0'; ) 
    {
        if (text[i] == pattern[j] || text[i]+32 == pattern[j] || text[i]-32 == pattern[j]) 
        {
            ++i, ++j;
            if (pattern[j] == '\0') {
         //      result = text+i-j;
         //      break;
				match(replace);
				j=0;
            }
        }
        else
        {
			j = T[j];
			ans[z] = text[ch];
			z++;
			ch++;
			i = ch;
			j=0;
		}
    }
    
 ans[z]='\0';
    free(T);
}

int main()
{
	FILE *p;
	p=fopen("ada3_1.txt","r");
	char c,text[20000],pattern[15],replace[15];
	int i=0;
	c=getc(p);
	while(c!=EOF)
	{
		text[i]=c;
		i++;
		c=getc(p);
	}
	printf("\n ************   Find And Replace(Using Knuth-Morris-Pratt)   ************");
	printf("\n\n\n");
	printf("\n Enter The Pattern U Want to Find: ");
	gets(pattern);
	printf("\n Enter The String U Want To Replace With: ");
	gets(replace);
	kmp_search(text,pattern,replace);
	fclose(p);
	p=fopen("ada3_1.txt","w");
	fprintf(p,"%s",ans);
	fclose(p);
	return 0;
}
