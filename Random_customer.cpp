#include <iostream>
#include <bits/stdc++.h>
#include "getinfofromgrocery.h"

using namespace std;

struct customertrolley{
  int order;
  int totalprice;
};
void swap(int *a, int *b){
  int temp;
  temp =*a;
  *a = *b;
  *b = temp;
}
void random50customers(){
  int customerno;
  cin >> customerno;
  customertrolley *customerlist;
  int *numbergrocery;
  customerlist = new customertrolley[customerno];
  numbergrocery = new int[customerno];
  //const int customerno = 50;

  //customertrolley customerlist[customerno];
  //int numbergrocery[customerno];
  srand(time(NULL));
  for (int i=0;i<customerno;i++){
    numbergrocery[i] = 1+rand()%10;
    customerlist[i].order = i+1;
    customerlist[i].totalprice =0;
  }

  for (int i=0; i<customerno; i++){
    for (int j=0; j<numbergrocery[i]; j++){
      //int whatgrocery = rand()%12;
      unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
      uniform_int_distribution<int> uniform_dist2(0,11);
      default_random_engine pb1(seed);
      int whatgrocery = uniform_dist2(pb1);
      randomgroceryprice();
      //cout << "whatgrocery= " << whatgrocery <<endl;
      customerlist[i].totalprice+=arr[whatgrocery].random;

    }
  }
  //for (int i=0;i<customerno;i++){
    //cout << customerlist[i].order <<" " << customerlist[i].totalprice << endl;
  //}
  int idx,max_idx;
  for (int i=0;i<customerno-1;i++){
    max_idx = i;
    for (int j=i+1; j<customerno; j++){
      if (customerlist[j].totalprice> customerlist[max_idx].totalprice){
        max_idx = j;
      }
    }
      swap(&customerlist[i].totalprice,&customerlist[max_idx].totalprice);
      swap(&customerlist[i].order,&customerlist[max_idx].order);

  }
  for (int i=0;i<customerno;i++){
    cout << customerlist[i].order << " " << customerlist[i].totalprice << endl;
  }

  delete[] customerlist;
  delete[] numbergrocery;
}
//int main(){
  //random50customers();
//}
