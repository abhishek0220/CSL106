#include<bits/stdc++.h>
using namespace std;


class chaining{
    public:
    vector<int> *arr;
    int size;
    chaining(int n){
        size = n;
        arr = new vector<int>[size];
    }

    int hashfunction(int key){
        return (key%size);
    }
    
    void insert(int key){
        int index = hashfunction(key);
        arr[index].push_back(key);
        system("CLS");
        display();
        delay(1);
    }
    void delay(int number_of_seconds) 
    { 
        int milli_seconds = 1000 * number_of_seconds; 
      
        // Stroing start time 
        clock_t start_time = clock(); 
      
        // looping till required time is not acheived 
        while (clock() < start_time + milli_seconds) 
            ; 
    } 
    void deleteItem(int key)
    {
      int index = hashfunction(key);
      vector<int> :: iterator i;
      for (i = arr[index].begin(); i != arr[index].end(); i++) {
          if (*i == key)
          break;
      }
      if (i != arr[index].end())
          arr[index].erase(i);
    }

    void display() {
        for (int i = 0; i < size; i++) {
          cout << i;
          vector <int> :: iterator t;
          for (t = arr[i].begin();t != arr[i].end(); t++)
          cout << "\t->\t" << *t;
          cout << endl;
        }
    }
};
int main(){
    int arr[] = {15, 11, 27, 8, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    chaining hash(n);
    for (int i = 0; i < n; i++){
        hash.insert(arr[i]);
    }
}