#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>


using namespace std;


int lcs_len(long long x,long long y)
	if(x==-1||y==-1){
		return 0;
	}
	int xx=x-1;
	int yy=y-1;
	if(st[x]==nd[y]){ // if the last element of both is equal
		return lcs_len(xx,yy)+1;
	}
	else{
		return max(lcs_len(xx,y),lcs_len(x,yy));
	}
}

int main()
{
    cout << lcs_len( 6541254939322816220209974565477289648317, 3142522751761601737419090933147067701840);
}