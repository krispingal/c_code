//This prog uses Euclid's algorithm to find
//G.C.D for given two no.s
#include<stdio.h>

int findgcd(int i ,int j){
	int t;
	if( i%j ) {
		t=i;
		i=j;	
		j=t%i;
		j=findgcd(i,j);
		}
	else
		return (j);
	return (j);
}
int main(){
	int i,j;
	printf("Enter two no.s\n");
	scanf("%d%d",&i,&j);
	i = findgcd(i,j);
	printf("g.c.d of the two no.s is %d:",i);
	return (0);
}
