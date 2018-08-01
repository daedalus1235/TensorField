#include <iostream>
#include <vector>
#define nl "\n"

using namespace std;

vector<int> field(int (&arr)[2]);

int main(){
    int n = 1000;
    int pos[2];
    int vel[2];
    while(n>0){
        pos[0]=n;
        pos[1]=2*n;
        vel[0]=field(pos)[0];
        vel[1]=field(pos)[1];
        cout<<vel[0]<<", "<<vel[1]<<nl;
        n--;
    }
    return 0;
}

vector<int> field(int (&arr)[2]) {
    vector<int> accel;

    accel.push_back(arr[0]);
    accel.push_back(arr[1]);

    return accel;
}
