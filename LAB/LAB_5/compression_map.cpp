#include<bits/stdc++.h>
using namespace std;

class hashing{
    public:
    vector<int> *arr;
    int size;
    hashing(int n){
        size = n;
        arr = new vector<int>[size];
    }

    int hashfunction1(int key){
        return (key%size);
    }
    int hashfunction2(int key,int a,int b){
        return (a*key+b)%size;
    }

    void insert(int key){
        int index = hashfunction1(key);
        arr[index].push_back(key);
    }
    void deleteItem(int key)
    {
      int index = hashfunction1(key);

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
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a)/sizeof(a[0]);
    hashing hash(10);
    for (int i = 0; i < n; i++){
        hash.insert(a[i]);
    }
    hash.display();
}