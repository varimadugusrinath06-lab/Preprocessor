#include "header.h"

void header_file(char *file)
{
	FILE *fp=fopen("data","r");
	int c=large_line(fp),hl,sl,i,j,k,l,lc=0;
	char *s=(char *)malloc(c+1),h[50]="/usr/include/",ch;
	for(hl=0;h[hl];hl++);
	int fl;
	for(fl=0;file[fl];fl++);
	file[fl-1]='i';
	FILE *dp=fopen(file,"w"),*sf;
	while(fgets(s,c+1,fp))
	{
		lc++;
		for(sl=0;s[sl];sl++);
		for(i=0;i<=sl;i++)
		{
			if(s[i]=='<')
			{
				l=lc;
				for(j=i+1,k=hl;s[j]!='>';j++,k++)
					h[k]=s[j];
				h[k]='\0';
				break;
			}
		}
		if(l==lc)
		{
			sf=fopen(h,"r");
			while((ch=fgetc(sf))!=EOF)
				fputc(ch,dp);
			continue;
		}
		fputs(s,dp);
	}
	fclose(fp),fclose(dp),fclose(sf);
	remove("data");
}

