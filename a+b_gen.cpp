#include<bits/stdc++.h>
using namespace std;
int main(int argc,char **args)
{
	if(argc==0)
		srand(time(NULL));
	else {
		int seed;
		sscanf(args[0],"%d",seed);
		srand(seed);
	}
	ofstream fout("a+b.in");
	fout<<rand()<<' '<<rand()<<endl;
	return 0;
}
