#include<iostream>
using namespace std;

void Tower_of_honoi(int n, char src,char axu, char dest){
    if (n==0){
        //cout<<"Move from"<<src<<" to"<< dest<<". \n";
        return ;
    }
    Tower_of_honoi(n-1,src,dest,axu);
    cout<<"Move disk "<<n<<" from "<<src<<" to rod"<<dest<<endl;
    Tower_of_honoi(n-1,axu,src,dest);

}

int main()
{
    int n;
    cout<<"Enter the numbers of  disk for the tower of the honoi:";
    cin>>n;
    cout<<"Moves to opearte are:"<<endl;
    Tower_of_honoi(n,'A','B','C');
    return 0;
}