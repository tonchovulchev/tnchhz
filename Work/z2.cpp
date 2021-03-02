#include<iostream.h>
#include<string.h>

bool stopper=0;
bool resh=0;

bool global_red(int *a){
	for(int k=0;k<9;k++){
		for(int i=9*k;i<9*k+9;i++){
			for(int j=i+1;j<9*k+9;j++){
				if(a[i]==a[j]) return false;
			}
		}
	}
	return true;
}

bool global_stulb(int * a){
	for(int k=0;k<9;k++){
		for(int i=k;i<k+73;i+=9){
			for(int j=i+9;j<k+73;j+=9){
				if(a[i]==a[j]) return false;
			}
		}
	}
	return true;
}

bool global_kvadr(int *a){return 1;}

bool global_prov(int * a){
	return global_stulb(a)&&global_red(a)&&global_kvadr(a);
}




bool local_red(int *a,int n,int k){
	int r=n/9;
	for(int i=r*9;i<r*9+9;i++){
		if(a[i]==k&&i!=n) return false;
	}
	return true;
}

bool local_stulb(int *a,int n,int k){
	int r=n%9;
	for(int i=r;i<r+73;i+=9){
		if(a[i]==k&&i!=n) return false;
	}
	return true;
}

bool local_poz_kvadr(int *a, int i,int n,int k){
	if((a[i]==k&&i!=n)||(a[i+1]==k&&(i+1)!=n)||(a[i+2]==k&&(i+2)!=n)) return false;
	if((a[i+9]==k&&(i+9)!=n)||(a[i+10]==k&&(i+10)!=n)||(a[i+11]==k&&(i+11)!=n)) return false;
	if((a[i+18]==k&&(i+18)!=n)||(a[i+19]==k&&(i+19)!=n)||(a[i+20]==k&&(i+20)!=n)) return false;
	return true;
}

bool local_kvadr(int *a,int n,int k){
	int poz=(n%9)/3+((n/9)/3)*3;
	int ch=27*(poz/3)+3*(poz%3);
	return local_poz_kvadr(a,ch,n,k);
}

bool local_prov(int * a,int n,int k){
	return local_red(a,n,k)&&local_stulb(a,n,k)&&local_kvadr(a,n,k);
}



void print(int *a){
	cout<<"ZZZZZZZ:"<<endl<<endl;
	for(int i=0;i<73;i+=9){
		for(int j=i;j<i+9;j++){
			cout<<a[j]<<" ";;
		}
		cout<<endl<<endl;
	}
	cout<<"Easy!"<<endl;
	cout<<"To exit enter 1:"<<endl;
}



void generator(int a[],int n,int const *b){
	if(stopper) return;
	if(n==81){
		if(global_prov(a)) {
			print(a);stopper=1;resh=1; return;
		}
		else {
			cout<<"ISCHISLITELNA GRESHKA"<<endl;stopper=1;return;
		}
	}

	if(b[n]!=0) generator(a,n+1,b);
	if(b[n]==0){
		for(int k=1;k<10;k++){
			if(local_prov(a,n,k)){
				a[n]=k;
				generator(a,n+1,b);
			}
		}
	a[n]=b[n];
	return;
	}
}


void read(int *a){
	cout<<"=========================  ZZ  ========================="<<endl<<endl;
	cout<<"Hello!"<<endl;
	cout<<"Enter grid with no interval."<<endl;
	cout<<endl;
	char s[9];
	for(int i=1;i<10;i++){
		cout<<"vavedete red "<<i<<":";
		cin>>s;
		for(int j=0;j<9;j++){
			a[9*(i-1)+j]=s[j]-'0';
		}
		//cout<<endl;
	}
	cout<<endl;
	cout<<"You entered"<<endl;
	cout<<"solve?(y/n)"<<endl;
	char f;cin>>f;
	if(!(f-'n')) cout<<"hh :)"<<endl;
	cout<<endl<<endl;

}


void main(){
		
	int a[81];
	read(a);
	int b[81];
	for(int i=0;i<81;i++){
		b[i]=a[i];}

	generator(a,0,b);

	if(!resh){ 
		cout<<"no solution exists!"<<endl;
	}
	int krai;
	cin>>krai;

}
