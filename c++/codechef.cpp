#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int l,v1,v2,t1,t2;
	    cin>>l>>v1>>v2;
	    if(l%v1==0 && l%v2==0){
	        t1=l/v1;
	        t2=l/v2;
	        if(t1>t2){
	            cout<<t1-t2-1<<endl;
	        }
	        else{
	            cout<<-1<<endl;
	        }
	    }
	    else if(l%v1!=0 && l%v2!=0){
	        t1=l/v1+1;
	        t2=l/v2+1;
	        if(t1>t2){
	            cout<<t1-t2-1<<endl;
	        }
	        else{
	            cout<<-1<<endl;
	        }
	    }
	    else if(l%v1==0 && l%v2!=0){
	        t1=l/v1;
	        t2=l/v2+1;
	        if(t1>t2){
	            cout<<t1-t2-1<<endl;
	        }
	        else{
	            cout<<-1<<endl;
	        }
	    }
	    else if(l%v1!=0 && l%v2==0){
	        t1=l/v1+1;
	        t2=l/v2;
	        if(t1>t2){
	            cout<<t1-t2-1<<endl;
	        }
	        else{
	            cout<<-1<<endl;
	        }
	    }
	    
	}
	return 0;
}