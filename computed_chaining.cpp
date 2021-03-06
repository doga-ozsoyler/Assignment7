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
                data[newAddress].plink = -1;
            }
        }
        else
        {
            remove(mod);
            data[mod].key = key;
            data[mod].plink = -1;
        }
        
    }

}


int ComputedChaining::remove(int pos) {

    int next = h1(data[pos].key);
    int prev = next;
    while (data[next].key != data[pos].key)
    {
        prev = next;
        next = h1(next + h2(data[next].key) * data[next].plink);
    }
    data[prev].plink = -1;

    int address = pos;
    int oldAddress = address;
    vector<int> removeData;
    while (data[address].plink != -1 || removeData.size() == 0)
    {
        removeData.push_back(data[address].key);
        address = h1(address + h2(data[address].key) * data[address].plink);
        if(h1(removeData[0]) != h1(removeData.back()))
        {
            removeData.pop_back();
            oldAddress = address;
            continue;
        }
        data[oldAddress].valid = false;
        data[oldAddress].plink = -1;
        oldAddress = address;
    }

    data[pos].valid = true;

	for(int i = 0; i < removeData.size(); i++)
    {   
        insert(removeData[i]);
	}

    removeData.clear();

    return 1;
}