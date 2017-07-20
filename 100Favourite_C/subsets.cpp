#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void printShadow(char* origStr, char* str)
{
	char output[20] = {'\0'};
	int i=0;
	
	output[i++]='{';
	for(int j=0;str[j]!='\0';j++)
	{
		if(str[j]=='1')
		{
			output[i++] = origStr[j];
			output[i++] = ',';
		}
	}
	// remove last comma
	if(output[i-1]==',')
		i--;
	output[i++]='}';
	output[i] = '\0';
	
	cout << output << endl;
}

void subsets(char* str,int m,int n,char* origStr=NULL)
{
	if(n<m)
	{
		if(origStr==NULL)
		{
			cout << str << endl;
		}
		else
		{
			printShadow(origStr,str);
		}
	}
	else
	{
		str[m] = '0';
		subsets(str,m+1,n,origStr);
	    str[m] = '1';
	    subsets(str,m+1,n,origStr);
	}
}

void printSubsets(char* s)
{
	// Prints all subsets of s
	if (s==NULL)
		return;
	int len = strlen(s);
	char* standStr = new char[len+1];
	memset(standStr,'\0',len+1);
	cout << s << endl;
	subsets(standStr,0,len-1,s);
	delete[] standStr;
}


// Main
int main()
{
	char s[] = "abc";
	printSubsets(s);
	return 0;
}

