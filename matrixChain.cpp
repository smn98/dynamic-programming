#include<stdio.h>
#include<limits.h>
#define D 5

printSol(int s[][D], int l,int h){
	if(s[l][h]){
		printf("(");
		printSol(s,l,s[l][h]);
	}
	if(!s[l][h]){
		printf(" A%d ",l);
	}
	if(s[l][h]){
		printSol(s,s[l][h]+1,h);
		printf(")");
	}
}
matrixChain(int p[], int m[][D], int s[][D]){
	int n = D;
	for(int d = 1; d<n-1;d++){
		for(int i = 1; i<n-d;i++){
			int j = i+d;
			int min = INT_MAX;
			for(int k = i;k<j;k++){
				int q = m[i][k] + m[k+1][j] + (p[i-1] * p[k] * p[j]);
				if(q<min){
					min = q;
					s[i][j] = k;
					m[i][j] = min;
				}	
			}
		}
	}
	
	printf("Min cost: %d\n", m[1][n-1]);
	
	printSol(s,1,n-1);
}
int main(){
	int p[] = {40, 20, 30, 10, 30};
	int m[D][D] = {0};
	int s[D][D] = {0};
	matrixChain(p,m,s); 
	return 0;
}
