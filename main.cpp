#include <iostream>
#include "computed_chaining.cpp"

using namespace std;

int main(){

    ComputedChaining list(11);

    list.insert(41);
    list.insert(19);
    list.insert(49);
    list.insert(73);
    list.insert(30);
    list.insert(80);
    list.insert(20);
    list.insert(58);
    list.insert(82);
    list.insert(79);
    //list.insert(90);

    for(int i = 0; i < list.data.size(); i++)
    {
        cout << i << "\t" << list.data[i].key << "\t" << list.data[i].plink << endl;
    }


    return 0;
}