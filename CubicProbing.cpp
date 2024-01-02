#include "CubicProbing.h"
#include <vector> 
#include <string> 

using namespace std ;

void CubicProbing::createAccount(std::string id, int count) {
    int value = hash(id);
    int initial = value;
    bool found = false;
    int i=1;
    for (int i = 0; i < bankStorage1d.size(); i++){
        if(bankStorage1d[i].id==id){found = true; break;}
    }
        while (!found) {
            value = (initial + (i*i*i)) % 200017;
            if (bankStorage1d[value].id == "-1" || bankStorage1d[value].id == "-2") {
                Account NewAccount;
                NewAccount.id = id;
                NewAccount.balance = count;
                bankStorage1d[value] = NewAccount;
                data_size++;
                break;
            }
            i++;
            // // Add an exit condition for the edge case when the table is full.
            // if (i >= 200017) {
            //     break;
            // }
        }
    }

vector<int> CubicProbing::getTopK(int k) {
    vector<int> balanceVector;
    vector<int> topK;
    for (int i = 0; i < bankStorage1d.size(); i++) {
        balanceVector.push_back(bankStorage1d[i].balance);
    }
    int n = balanceVector.size();
    for (int i = 0; i < k && i < n; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (balanceVector[j] > balanceVector[maxIndex]) {
                maxIndex = j;
            }
        }
        int temp = balanceVector[i];
        balanceVector[i] = balanceVector[maxIndex];
        balanceVector[maxIndex] = temp;
    }
    for (int i = 0; i < k && i < n; i++) {
        topK.push_back(balanceVector[i]);
    }
    return topK;
}




int CubicProbing::getBalance(std::string id) {
    int value = hash(id);
    int initial = value;
    bool found=false;
    int i=1;
    for (int i = 0; i < bankStorage1d.size(); i++){
        if(bankStorage1d[i].id==id){return bankStorage1d[i].balance;}
    }
    return -1;
}

void CubicProbing::addTransaction(std::string id, int count) {
    int value = hash(id);
    int initial = value;
    int i = 0; 
    bool found = false;
    for (; i < bankStorage1d.size(); i++) {
        int probe_value = (value + i*i*i) % 200017;
        if (bankStorage1d[probe_value].id == id) {
            found = true;
            bankStorage1d[probe_value].balance += count;
            break;}}
    if (!found) {
        while (i <= bankStorage1d.size()) {
            value = (initial + (i * i*i)) % 200017;
            if (bankStorage1d[value].id == "-1" || bankStorage1d[value].id == "-2") {
                Account NewAccount;
                NewAccount.id = id;
                NewAccount.balance = count;
                bankStorage1d[value] = NewAccount;
                data_size++;
                break;}i++;}}
}


bool CubicProbing::doesExist(std::string id) {
    int value = hash(id);
    int i = 0; 

    for (int i = 1; i < bankStorage1d.size(); i++) {
        value = (value + (i * i*i)) % 200017;
        if (bankStorage1d[value].id == id) {
            return true; 
        }
        if (bankStorage1d[value].id == "-1") {
            break; 
        }
    }
    return false;
}

bool CubicProbing::deleteAccount(std::string id){
    int value=hash(id);
    int initial = value;
    int i=1;
    for (; i < bankStorage1d.size(); i++) {
        int probe_value = (value + i*i*i) % 200017;
        if (bankStorage1d[probe_value].id == id) {
            bankStorage1d[probe_value].id="-2";
            bankStorage1d[probe_value].balance=0;
            data_size--;
            return true;}}
    return false;
}

int CubicProbing::databaseSize() {
    return data_size; 
}

int CubicProbing::hash(std::string id) {
    int hash_ans=0;
    for(char c : id){
        hash_ans+=static_cast<int>(c);
    }
    int hash_value=hash_ans%200017 ;
    return hash_value ; // Placeholder return value
}


// int main()
// {   CubicProbing Object1 ;
//     Object1.createAccount("CDAD7786825_7990768648" , 648);
//     Object1.createAccount("DCDA7547234_9919615552" , 552);
//     Object1.createAccount("AACB1850545_7974534788" , 788);
//     cout<<Object1.databaseSize()<<endl;
//     Object1.createAccount("CDBD5250777_1124276711" , 711);
//     Object1.createAccount("ABCB8377155_0656808575" , 575);
//     Object1.getTopK(1);
//     cout<<Object1.databaseSize()<<endl;
//     Object1.createAccount("CDDC3792028_3313680038" , 38);
//     Object1.createAccount("CBBA9574444_7470182321" , 321);
//     Object1.createAccount("DBCC4334636_8057544188" , 188);
//     Object1.getTopK(3);
//     cout<<Object1.databaseSize()<<endl;
//     Object1.createAccount("BABD5741078_5109455304" , 304);
//     Object1.createAccount("BCBA7529510_0817878868" , 868);
//     cout<<Object1.databaseSize()<<endl;
//     Object1.getTopK(1);
//     Object1.addTransaction("BCBA7529510_0817878868",-860);
//     cout<<Object1.getBalance("BCBA7529510_0817878868")<<endl;
//     cout<<Object1.databaseSize()<<endl;
//     Object1.getTopK(1);
//     Object1.addTransaction("DCDA7547234_9919615552",592);
//     cout<<Object1.getBalance("DCDA7547234_9919615552")<<endl;
//     Object1.getTopK(5);
//     Object1.deleteAccount("DCDA7547234_9919615552");
//     cout<<Object1.getBalance("DCDA7547234_9919615552")<<endl;
//     // Object1.getTopK(4);
//     cout<<Object1.databaseSize()<<endl;
//     cout<<Object1.doesExist("DCDA7547234_9919615552")<<endl;
//     cout<<Object1.doesExist("DCDA7547234_9961586552")<<endl;

// }


