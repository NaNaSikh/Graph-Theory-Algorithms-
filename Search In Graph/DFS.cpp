//Adjacency Matrix
#include <bits/stdc++.h>
using namespace std; 

int S[1000];
int n,m,n1,m1,start;
int top;

//STACK

void STACK_INIT(int S[]){
	top=-1;
}
 
bool STACK_EMPTY(int S[]){
	if (top >= 0) return false;
	else return true;
}

void PUSH(int x){
	
	top++;
	S[top]=x;
}

void  POP(){

top--;
//return S[top+1];
}

//STACK


int main(){
	
	cin>>n>>m; 

int A[n][n]; // mosazgverobis matrica

for (int i=0; i<n; i++){
	for (int j=0; j<n; j++){
		A[i][j]=0;
	} 
}

for (int i=0; i<m; i++){
	cin>>n1>>m1;
	A[n1-1][m1-1]=1;
}

cin>>start;
start--;

for (int i=0; i<n; i++){
	for (int j=0; j<n; j++){
		cout<<A[i][j]<<" ";
	} cout<<endl;
}

int N[n]; // wdeebis masivi 
int F[n]; // f masivshi vimaxsovrebt i-wveroshi saidan movedit 
int t[n]; //im adgilis damaxsovreba sadac gavcherdit
/*
// am shemtxvevashi ar viyeneb 
int T[n]={0}; //pirpapiri wvero 
int B[n]={0}; // ukuwiboebi*/

for(int i=0; i<n; i++){
	N[i]=0; 
	F[i]=-2;
	t[i]=0;
}
STACK_INIT(S); // STACK 

F[start]=-1;
N[start]=1;

PUSH(start);
//int k=30;
int x=2; //wdeebi 
while (!STACK_EMPTY(S)){

	bool edge=false;
	for(int i=t[start]; i<n; i++){
		
		if(A[start][i]==1){
			
			if (F[start]==i){
				continue;
			} else
				if( N[i]==0 && F[i]==-2){
					N[i]=x; x++;
					F[i]=start;
					PUSH(i);
					t[start]=i+1;
					start=S[top];
					break;
					} 
				}
			
		if(i==(n-1)) edge=true;
		
	}  
	if(t[start]>=n) edge=true;
	
	if(edge){
		POP();
		start=S[top];
	}
	

}
		cout<<"\nN: ";
	for(int i=0; i<n; i++){
		cout<<N[i]<<" ";
	}
	cout<<"\nF: ";
	for(int i=0; i<n; i++){
		cout<<F[i]<<" ";
	}
		cout<<"\nt: ";
	for(int i=0; i<n; i++){
		cout<<t[i]<<" ";
	}
	
return 0;
}