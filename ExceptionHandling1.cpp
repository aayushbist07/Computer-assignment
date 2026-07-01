#include<iostream>
using namespace std;
int main()
{
    int arr[5];
    int index;
    cout<<"Enter 5 elements:";
    for(int i=0;i<5;i++)
    cin>>arr[i];
cout<<"ENter index:";
cin >> index;

try{
    if(index<0 || index>=5)
    throw index;
cout<<"ELement="<< arr[index];
}
catch(int)
{
    cout<<"invalid index";
}
return 0;
}