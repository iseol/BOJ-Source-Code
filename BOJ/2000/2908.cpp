#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void) {
	char stra[4], strb[4];
	scanf("%s %s", &stra, &strb);
	
	char temp;
	temp = stra[0];
	stra[0] = stra[2];
	stra[2] = temp;
	
	temp = strb[0];
	strb[0] = strb[2];
	strb[2] = temp;
	
	int a = atoi(stra);
	int b = atoi(strb);
	
	if (a > b) printf("%d", a);
	else printf("%d", b);
	return 0;
}
