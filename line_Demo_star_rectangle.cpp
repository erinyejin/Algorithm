#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
   for (int h = 1; h <= b; h++)
   {
       for (int w = 1; w <=a; w++)
       {
           cout << "*";
       }
       cout << endl;
   }
       
    return 0;
}