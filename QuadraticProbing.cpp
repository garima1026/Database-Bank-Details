#include "QuadraticProbing.h"
#include <vector> 
#include <string> 

using namespace std ;

void QuadraticProbing::createAccount(std::string id, int count) {
    int value = hash(id);
    int initial = value;
    bool found = false;
    int i=1;
    for (int i = 0; i < bankStorage1d.size(); i++){
        if(bankStorage1d[i].id==id){found = true; break;}
    }
        while (!found) {
            value = (initial + (i*i)) % 200017;
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

vector<int> QuadraticProbing::getTopK(int k) {
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




int QuadraticProbing::getBalance(std::string id) {
    int value = hash(id);
    int initial = value;
    bool found=false;
    int i=1;
    for (int i = 0; i < bankStorage1d.size(); i++){
        if(bankStorage1d[i].id==id){return bankStorage1d[i].balance;}
    }
    return -1;
}

void QuadraticProbing::addTransaction(std::string id, int count) {
    int value = hash(id);
    int initial = value;
    int i = 0; 
    bool found = false;
    for (; i < bankStorage1d.size(); i++) {
        int probe_value = (value + (i*i)) % 200017;
        if (bankStorage1d[probe_value].id == id) {
            found = true;
            bankStorage1d[probe_value].balance += count;
            break;}}
    if (!found) {
        while (i <= bankStorage1d.size()) {
            value = (initial + (i * i)) % 200017;
            if (bankStorage1d[value].id == "-1" || bankStorage1d[value].id == "-2") {
                Account NewAccount;
                NewAccount.id = id;
                NewAccount.balance = count;
                bankStorage1d[value] = NewAccount;
                data_size++;
                break;}i++;}}
}


bool QuadraticProbing::doesExist(std::string id) {
    int value = hash(id);
    int i = 0; 

    for (int i = 1; i < bankStorage1d.size(); i++) {
        value = (value + (i * i)) % 200017;
        if (bankStorage1d[value].id == id) {
            return true; 
        }
        if (bankStorage1d[value].id == "-1") {
            break; 
        }
    }
    return false;
}

bool QuadraticProbing::deleteAccount(std::string id) {
    int value=hash(id);
    int initial = value;
    int i=1;
    for (; i < bankStorage1d.size(); i++) {
        int probe_value = (value + (i*i)) % 200017;
        if (bankStorage1d[probe_value].id == id) {
            bankStorage1d[probe_value].id="-2";
            bankStorage1d[probe_value].balance=0;
            data_size--;
            return true;}}
    return false;
}

int QuadraticProbing::databaseSize() {
    return data_size; 
}

int QuadraticProbing::hash(std::string id) {
    int hash_ans=0;
    for(char c : id){
        hash_ans+=static_cast<int>(c);
    }
    int hash_value=hash_ans%200017 ;
    return hash_value ; // Placeholder return value
}

