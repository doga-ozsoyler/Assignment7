#include "computed_chaining.h"
#include <assert.h>

using namespace std;

int ComputedChaining::h1(int key) {

    return key % data.size();
}

int ComputedChaining::h2(int key) {

    int inc = (key / data.size()) % data.size();
    
    if(inc == 0)
    {
        return 1;
    }
    else
    {
        return inc;
    }
}


void ComputedChaining::insert(int key) {



}


int ComputedChaining::remove(int pos) {


}