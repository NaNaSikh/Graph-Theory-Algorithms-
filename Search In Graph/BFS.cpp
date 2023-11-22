#include <bits/stdc++.h>
using namespace std; 

//queue

int Q[1000];
int head,tail;

void QUEUE_INIT(int Q[]){
	head=0;
	tail=0;
}

bool QUEUE_EMPTY(int Q[]){
	if(tail<head) return false;
	else return true;
}

void ENQUEUE(int x){
	Q[head]=x; 
	head++;
}

int DEQUEUE(){
	tail++;
	return Q[tail-1];
} 


int main(){
	
int n,m; //n-wveroebi  m-wiboebi
int n1,m1;
cin>>n>>m; 

int A[n][n]={0}; // mosazgverobis matrica

for (int i=0; i<n; i++){
	for (int j=0; j<n; j++){
		A[i][j]=0;
	} 
}

for (int i=0; i<m; i++){
	cin>>n1>>m1;
	A[n1-1][m1-1]=1;
	A[m1-1][n1-1]=1;
}

for (int i=0; i<n; i++){
	for (int j=0; j<n; j++){
		cout<<A[i][j]<<" ";
	} cout<<endl;
}


int R[n];
QUEUE_INIT(Q);

for (int i=0; i<n; i++){
	R[i]=-1;
}

int start;
cin>>start; 
start--;


ENQUEUE(start);
R[start]=0;
cout<<endl;

while(!QUEUE_EMPTY(Q)){	

	for(int j=0; j<n; j++){
		if(A[tail][j]==1){
			if (R[j]==-1 ){
				ENQUEUE(R[tail]+1);
				R[j]=R[tail]+1;

				 } 
		}
	}
	
	DEQUEUE();	
		for (int i=0; i<n; i++){
		cout<<R[i]<<" ";
	} cout<<endl;
}
	cout<<endl;
	for (int i=0; i<n; i++){
		cout<<R[i]<<" ";
	}

	
return 0;
}