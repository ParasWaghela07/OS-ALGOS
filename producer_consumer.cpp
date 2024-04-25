#include<bits/stdc++.h>
using namespace std;

int mutex=1;
int full=0;
int empty=5;

void producer(){
    mutex=0;
    full++;
    empty--;

    cout<<"Produced !"<<endl;
    cout<<"Inside buffer"<<full<<endl;
    cout<<"space in buffer"<<empty<<endl;

    cout<<endl;

    mutex=1;
}

void consumer(){
    mutex=0;
    full--;
    empty++;

    cout<<"Produced !"<<endl;
    cout<<"Inside buffer"<<full<<endl;
    cout<<"space in buffer"<<empty<<endl;

    cout<<endl;

    mutex=1;
}

int main(){

    while(1){
        cout<<"1.Producer"<<endl<<"2.consumer"<<endl<<"3.End"<<endl<<endl;

        int c;
        cin>>c;

        switch(c){
            case 1:
            if(mutex==1 && full<5){
                producer();
            }
            else{
                cout<<"Buffer is full "<<endl;
            }
            break;

            case 2:
            if(mutex==1 && full>0){
                consumer();
            }
            else{
                cout<<"Buffer is empty"<<endl;
            }
            break;

            case 3:
            exit(0);
        }
    }
}