#include <list>
#include <iostream>
#include <iomanip>
#include <string>
#include "josephus.h"

using namespace std;

void init_vals(list<string> &L, args &in)
{
    cin >> in.N >> in.M >> in.K;
    cout << "Number of people? " << in.N << endl; 
    cout << "Index for elimination? " << in.M << endl; 
    cout << "Index for printing? " << in.K << endl; 


    L.resize(in.N);

    generate(L.begin(),L.end(),SEQ(in.N));


}

void print_list(const list<string> &L, const unsigned &cnt)
{
  int index = 0;

  list<string>::const_iterator itr = L.cbegin();

  if(cnt == 0)
  {
    cout << endl;
    cout << "Initial group of people" << endl;
    cout << "-----------------------" << endl;

    while(itr != L.end())
    {
      if(index % NO_ITEMS == 0)
      {
        cout << endl; 
      }
        cout << *itr << " ";
        ++itr;
        ++index;
    }
    
    cout << endl;
  }
  else
  {
    cout << endl;
    cout << "After eliminating " << cnt << "th person" << endl;
    cout << "-----------------------" << endl;

     while(itr != L.end())
    {
      if(index % NO_ITEMS == 0)
      {
        cout << endl; 
      }
        cout << *itr << " ";
        ++itr;
        ++index;
    }
     
    cout << endl;
  }
  
  
}



int main()
{
 
  list<string> group;

  args info;

  init_vals(group,info);

   int count = 0;
   cout << endl; 


  print_list(group,count);

  cout << endl;

  int i =0;
  
  while(group.size() > 1)
  {

    if(count > 0 && count % info.K == 0)
    {
   
      print_list(group,count);
     
    }

    list<string>::iterator itr = group.begin();

    unsigned j = (i + (info.M - 1)) % group.size();

    advance(itr,j);

    group.erase(itr);

    i = j;

    ++count;

    
  }



  print_list(group,count);

  cout << endl; 
  

 
    





return 0;
};