#include <iostream>
#include <omp.h>
using namespace std;

int main() {

    #pragma omp parallel
    {  for(int i=1; i<6; i++){
        
        cout << "Hello from thread no:"<<i<< "\n";}
    }

    return 0;
}