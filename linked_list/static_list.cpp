#include<iostream>
using namespace std;

struct node{
    int data;
    int next;
};

class Static_List{
    private:
        static const int size=100;
        node n[size];
        int list;
        int avial;
        int getnode(int x){
            if(avial==-1){
                cout<<"Overflow";
                return;
            }
            else{
                int index;
                index=avial;
                avial=n[index].next;
                n[index].data=x;
                n[index].next=-1;
                return index;
            }
        }
        void freenode(int index){
            n[index].next=avial;
            avial=index;
            if(index==list){
                list=-1;
            }
        }
        void initalize(){
            for (int i=0;i<size;i++){
                n[i].next=i+1;
            }
            n[size-1].next=-1;
        }
    public:
        Static_List(int m):list(-1),avial(0){
            initalize();
        }
        void insertBeg(int x){
            int index=getnode(x);
            n[index].next=list;
            list=index;
        }
        void insertEnd(int x){
            int index=getnode(x);
            int i=list;
            if(list==-1){
                insertBeg(x);
                return;
            }
            while(n[i].next!=-1){
                i=n[i].next;
            }
            n[i].next=index;
        }
        void insertAfter(int x,int sp){
            int index=getnode(x);
            int i=list;
            if(list==-1){
                insertBeg(x);
                return;
            }
            while(n[i].data!=sp){
                i=n[i].next;
            }
            n[index].next=n[i].next;
            n[i].next=index;
        }
        void deletionBeg(){
            if(list==-1){
                
            }
        }
};
