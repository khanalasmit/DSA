#include<iostream>
using namespace std;
int array[20]={1,3,4,5,6,77,43,22,11,77,2221,114,56,7775,33};

void linearsearch(){
	int item;
    cout<<"Enter the item to search:";
    cin>>item;
    int flag=0;
    int n=15;
    for(int i=0;i<n;i++){
        if (array[i]==item){
            cout<<"seach sucessful";
            flag=1;
        }

    }
    if(flag==0){
        cout<<"Item not found";
    }
}



int main(){
    linearsearch();
    return 0;
}