#include <iostream>
#include<vector>
using namespace std;


void Tower(  int n, char src, char helper, char des ){
      if( n==1){
         cout<< " move the disk from source to destination "<< src <<"to "<<des << endl;
           return;
      }
       Tower( n-1, src, des, helper);
       cout<< " move the disk from source to destination "<< src <<"to "<<des << endl;
       Tower(n - 1, helper, src, des); 
    }
int main() {
     int n=3;
       char rod1='A';
       char rod2='B';
       char rod3='C';
         Tower( n , rod1, rod2, rod3);
          return 0;

}
