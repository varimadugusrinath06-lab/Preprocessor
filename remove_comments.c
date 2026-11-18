#include "header.h"

int large_line(FILE *fp)
{
	int c=0,c1=0;
	char ch;
	while((ch=fgetc(fp))!=EOF)
	{
		c++;
		if(ch=='\n')
		{
			if(c>c1)
				c1=c;
			c=0;
		}
	}
	rewind(fp);
	return c1;
}

void remove_comment(FILE *fp,char *file)
{
	int c=large_line(fp),i,f=0;
	char *s=(char *)malloc(c+1);
	char *t=(char *)malloc(c+1);
	FILE *dp=fopen("temp","w");
	while(fgets(s,c+1,fp))
	{
		for(i=0;s[i];i++)
		{
			if(s[i]=='/' && s[i+1]=='/')
				break;
			if(s[i]=='/' && s[i+1]=='*')
			{
				f=1;
				break;
			}
			if(s[i]=='*' && s[i+1]=='/')
				break;
		}
		if(s[i]=='/'&& s[i+1]=='/')
		{
			fputs("\n",dp);
			continue;
		}
		if(f)
		{
			fputs("\n",dp);
			if(s[i]=='*' && s[i+1]=='/')
				f=0;
			continue;
		}

		fputs(s,dp);
	}
	fclose(fp);
	fclose(dp);

	remove("data");
	rename("temp","data");

}

