#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
//Linear Search
void LinearSearch(int a[],int key){
int n,i;
cout<<"Enter the size of the array "<<endl;
cin>>n;
cout<<"Enter the array "<<endl;
for(i=0;i<n;i++){
    cin>>a[i];
}
for(i=0;i<n;i++){
    if(a[i]==key){
        cout<<"The value is found at index "<<i<<endl;
        break;
    }
}
if(i==n){
    cout<<"Element not present";
}
}
//finding max and smallest number in array
void big_small(int a[]){
int largest=INT_MIN;
int smallest=INT_MAX;
int n,i;
cout<<"Enter the size of the array "<<endl;
cin>>n;
cout<<"Enter the array "<<endl;
for(i=0;i<n;i++){
    cin>>a[i];
}
for(i=0;i<n;i++){
    if(a[i]>largest){
        largest=a[i];
    }
    if(a[i]<smallest){
        smallest=a[i];
    }
}
cout<<"Largest "<<largest<<"Smallest "<<smallest;
}
//Applying binary search
void Binary_se(int a[],int key){
int n,i;
cout<<"Enter the size of the array "<<endl;
cin>>n;
cout<<"Enter the array "<<endl;
for(i=0;i<n;i++){
    cin>>a[i];
}
int l,s,mid;
s=0;l=n-1;
while(s<=l){
    mid=(s+l)/2;
    if(a[mid]>key){
        s=mid+1;

    }
    else if(a[mid]<key){
        l=mid-1;
    }
    else if(a[mid]==key){
        cout<<"Element found at "<<mid;
        break;
    }
}
}
//Selection sort
void selection_Sort(int a[]){
int n,i,j,min_index;
cout<<"Enter the size of the array "<<endl;
cin>>n;
cout<<"Enter the array "<<endl;
for(i=0;i<n;i++){
    cin>>a[i];
}
for(i=0;i<n-1;i++){
        min_index=i;
    for(j=i;j<n;j++){
        if(a[j]<a[min_index]){
            min_index=j;
        }
    }
swap(a[min_index],a[i]);
}
for(i=0;i<n;i++){
    cout<<a[i]<<" ,";
}
}
//bubble sort
void bubble(int a[]){
int n,i,j;
cout<<"Enter the size of the array "<<endl;
cin>>n;
cout<<"Enter the array "<<endl;
for(i=0;i<n;i++){
    cin>>a[i];
}
for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
        }
    }
}
for(i=0;i<n;i++){
    cout<<a[i]<<",";
}
}
// insertion sort
void insertion(int a[]){
int n,i,j;
cout<<"Enter the size of the array "<<endl;
cin>>n;
cout<<"Enter the array "<<endl;
for(i=0;i<n;i++){
    cin>>a[i];
}
for(i=1;i<n;i++){
        int temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
for(i=0;i<n;i++){
    cout<<a[i]<<",";
}
}
//Generating subarrays from array
void sub1(int a[]){
int n,i,j,k;
cout<<"Enter the size of the array "<<endl;
cin>>n;
cout<<"Enter the array "<<endl;
for(i=0;i<n;i++){
    cin>>a[i];
}
for(i=0;i<n;i++){
    for(j=i;j<n;j++){
        for(k=i;k<=j;k++){
            cout<<a[k]<<",";
        }
        cout<<" "<<endl;
    }
}


}
//find max sum of subarray
void max_sub(int a[]){
int n,i,j,k,start,en;
int csum;
int msum=0;
cout<<"Enter the size of the array "<<endl;
cin>>n;
cout<<"Enter the array "<<endl;
for(i=0;i<n;i++){
    cin>>a[i];
}
for(i=0;i<n;i++){
    for(j=i;j<n;j++){
            csum=0;
        for(k=i;k<=j;k++){
            csum=csum+a[k];
        }
        if(msum<csum){
           msum=csum;
            start=i;
            en=j;
        }
    }

}
cout<<"msum"<<msum<<"at "<<start<<"to "<<en;
}
//find max sum using cumsum
void max_sub2(int a[]){
int n,i,j,csum;
int left=-1;
int right=-1;
int msum=0;
int cs[1000]={0};
cout<<"Enter the size of the array "<<endl;
cin>>n;
cin>>a[0];
cs[0]=a[0];
for(i=1;i<n;i++){
    cin>>a[i];
    cs[i]=cs[i-1]+a[i];
}
for(i=1;i<=n;i++){
    for(j=i;j<n;j++){
        csum=0;
        cout<<cs[j]<<"     "<<cs[i-1]<<" "<<endl;
        csum= cs[j]-cs[i-1];
        cout<<csum;
    }
    if(csum>msum){
        msum=csum;
        left=i;
        right=j;
    }
}
cout<<"Max_sum"<<msum<<" from "<<left<<" to "<<right;

}


int main()
{
    int a[1000];
    //LinearSearch(a,10);
    //big_small(a);
    //Binary_se(a,7);
    //selection_Sort(a);
    //bubble(a);
    //insertion(a);
    //sub1(a);
    //max_sub(a);
    max_sub2(a);
}
