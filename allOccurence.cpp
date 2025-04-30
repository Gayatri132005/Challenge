#include <iostream>
#include<vector>
using namespace std;


void AllOccurence( int arr[], int n , int i, vector<int>&ans,  int key){
  
      if( i==n){
       
          return ;
          
      }
     if( arr[i]==key){
          ans.push_back(i);
     }
     AllOccurence(arr, n, i + 1, ans, key); // ✅ Proper recursive call

  }
int main() {
    int arr[]={0,1,2,3,2,5,2,2};
     int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>ans;
     int key=2;
     AllOccurence( arr,n, 0, ans , key );
     
     for (int idx : ans) {
         cout << idx << " ";
     }
 
  return 0;


}
