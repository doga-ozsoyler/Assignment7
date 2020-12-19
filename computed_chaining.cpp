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

    int mod = h1(key);

    if(data[mod].valid == false)
    {
        data[mod].key = key;
        data[mod].valid = true;
        data[mod].plink = -1;
    }
    else if(data[mod].valid == true)
    {
        if(h1(data[mod].key) == h1(key))
        {
            int address = mod;
            while(data[address].plink != -1)
            {
                address = h1(address + h2(data[address].key) * data[address].plink);
            }

            int newAddress = address;
            int inc = h2(data[address].key);
            int plink = 0;
            int noLoop = 0;
            while(data[newAddress].valid != false && noLoop <= data.size())
            {
                newAddress = h1(newAddress + inc);
                plink++;
                noLoop++;
            }

            if(noLoop > data.size())
            {
                cout << "List is full!!!" << endl;
            }
            else
            {
                data[address].plink = plink;
                data[newAddress].key = key;
                data[newAddress].valid = true;
            }
        }
        else
        {
            int address = mod;
            int oldAddress = address;
            vector<int> removeData;
            while(data[address].plink != -1)
            {
                removeData.push_back(data[address].key);
                data[address].valid = false;
                address = h1(address + h2(data[address].key) * data[address].plink);
                data[oldAddress].plink = -1;
                oldAddress = address;
            }

            while(removeData )

        }
        
    }

}


int ComputedChaining::remove(int pos) {


}