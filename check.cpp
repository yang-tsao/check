#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
char name[256]="a+b",s[256];
double RT=1.0;
int main(int argc,char **args)
{
	if(argc>1)
		sscanf(args[1],"%s",name);
	else {
		cout<<"Input Problem Name.\n";
		scanf("%s",name);
	}
	for(int t=1; t<=200; t++)
	{
		system("cls");
		cout<<(double(t)/200.0)*100.0<<'%'<<endl;
		sprintf(s,".\\\"%s_gen.exe\" %d",name,t);
		//printf("%s\n",s);
		system(s);
		auto start = std::chrono::steady_clock::now();
		sprintf(s,".\\\"%s1.exe\"",name);
		//printf("%s\n",s);
		system(s);
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> diff = end-start;
		if(diff.count()>RT)
		{
			cout<<"Program 1 TLE."<<endl;
			cout<<"Random seed is "<<t<<endl;
			system("pause");
			return 0;
		}
		sprintf(s,"copy>nul .\\\"%s.out\" .\\\"%s1.out\"",name,name);
		//printf("%s\n",s);
		system(s);
		start = std::chrono::steady_clock::now();
		sprintf(s,".\\\"%s2.exe\"",name);
		//printf("%s\n",s);
		system(s);
		end = std::chrono::steady_clock::now();
		diff = end-start;
		if(diff.count()>1.0)
		{
			cout<<"Program 2 TLE."<<endl;
			cout<<"Random seed is "<<t<<endl;
			system("pause");
			return 0;
		}
		sprintf(s,"copy>nul .\\\"%s.out\" .\\\"%s2.out\"",name,name);
		//printf("%s\n",s);
		system(s);
		sprintf(s,"fc>nul .\\\"%s1.out\" .\\\"%s2.out\"",name,name);
		////printf("%s\n",s);
		if(system(s))
		{
			cout<<"WA."<<endl;
			cout<<"Random seed is "<<t<<endl;
			system("pause");
			return 0;
		}
	}
	system("cls");
	cout<<"AC."<<endl;
	system("pause");
	return 0;
}
