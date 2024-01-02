#include "LinearProbing.h"

using namespace std ;

// int helper_func(string id , int count){

// }


void LinearProbing::createAccount(std::string id, int count) {
    long long int value = hash(id);
    long long int initial = value;
    int i = 1;
    bool found = false;
    while (i <= 100019) {
        if (bankStorage1d[value].id == id) {
            found = true;
            break;}
        value = (initial + i) % 100019;
        i++;
    }
    if (!found) {
        i = 1;
        while (i <= 100019) {
            if (bankStorage1d[value].id == "-1" || bankStorage1d[value].id == "-2") {
                Account NewAccount;
                NewAccount.id = id;
                NewAccount.balance = count;
                bankStorage1d[value] = NewAccount;
                data_size++;
                break;}
            value = (initial + i) % 100019;
            i++;
        }
    }
}

vector<int> LinearProbing::getTopK(int k) {
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


int LinearProbing::getBalance(std::string id) {
    long long int value = hash(id);
    long long int initial = value;
    if (bankStorage1d[value].id == id) {
        return bankStorage1d[value].balance;
    }
    int i = 1;
    while (true) {
        value = (initial + i) % 100019;
        if (bankStorage1d[value].id == "-1") {
            return -1;
        }
        if (bankStorage1d[value].id == id) {
            return bankStorage1d[value].balance;
        }
        i++;
        if (i > 100019) {
            return -1;
        }
    }return -1 ;
}


void LinearProbing::addTransaction(std::string id, int count) {
    long long int value = hash(id);
    long long int initial = value;
    int i = 1;
    bool found = false;
    while (i <= 100019) {
        if (bankStorage1d[value].id == id) {
            found = true;
            bankStorage1d[value].balance += count;
            break;}
        value = (initial + i) % 100019;
        i++;}
    if (!found) {i = 1; 
        while (i <= 100019) {
            if (bankStorage1d[value].id == "-1" || bankStorage1d[value].id == "-2") {
                Account NewAccount;
                NewAccount.id = id;
                NewAccount.balance = count;
                bankStorage1d[value] = NewAccount;
                data_size++;
                break;}
            value = (initial + i) % 100019;
            i++;}}}


bool LinearProbing::doesExist(std::string id) {
    long long int value = hash(id);
    long long int initial=value;
    int i = 0; 
    if (bankStorage1d[value].id == "-1") {
        return false; 
    } else if (bankStorage1d[value].id == id) {
        return true; 
    } else {
        while (i<=100019) {
            i++;
            value = (initial + i) %100019; 
            if (bankStorage1d[value].id == "-1") {
                return false;
            }
            if(bankStorage1d[value].id == id){return true;}
        }
        return false;
            }
}

bool LinearProbing::deleteAccount(std::string id) {
    long long int value = hash(id);
    long long int initial = value;
    int i =0;
    while(i<=100019){
        if(bankStorage1d[value].id==id){
            bankStorage1d[value].id = "-2"; 
            bankStorage1d[value].balance = 0;
            data_size--;
            return true;
        }    
        value=(initial+i)%100019;
        i++;
    }
    return false;

}

//     if (bankStorage1d[value].id == "-1") {
//         return false; // Account not found
//     }

//     // Check if the account is in the initial slot
//     else if (bankStorage1d[value].id == id) {
        // bankStorage1d[value].id = "-2"; // Mark as deleted
        // bankStorage1d[value].balance = 0;
        // data_size--;
        // return true;
//     }

//     // Otherwise, probe linearly
//     else{
//         int i = 1;
//     while (true) {
//         value = (initial + i) % 100019;

//         // Check if the account is in the current slot
//         if (bankStorage1d[value].id == id) {
//             bankStorage1d[value].id = "-2"; // Mark as deleted
//             bankStorage1d[value].balance = 0;
//             data_size--;
//             return true;
//         }
//         i++;
//         if (i > 100019) {
//             return false;
//         }
//     }
// }
//     return false;



int LinearProbing::databaseSize() { 
    return data_size;
}

int LinearProbing::hash(std::string id) {
    long long int hash_ans = 0;
    for (int i = 0; i < id.length(); i++) {
        hash_ans += static_cast<int>(id[i]) * (i + 1); // Multiply by position (1-based)
    }
    int hash_value = hash_ans % 100019;
    return hash_value;
}


// int main()
// {   LinearProbing Object1 ;
//     Object1.createAccount("}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}",54);
//     cout<<Object1.databaseSize()<<endl;
//     Object1.createAccount("}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}",54);
//     cout<<Object1.databaseSize()<<endl;
//     Object1.createAccount("46567wdhcdj",777676774);
//     cout<<Object1.databaseSize()<<endl;
//     cout<<Object1.doesExist("3287466283")<<endl;
//     cout<<Object1.databaseSize()<<endl;
//     cout<<Object1.getBalance("}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}")<<endl;
//     cout<<Object1.databaseSize()<<endl;
//     Object1.deleteAccount("}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}");
//     cout<<Object1.databaseSize()<<endl;
//     cout<<Object1.deleteAccount("46567wdhcdj")<<endl;
//     cout<<Object1.databaseSize()<<endl;
//     cout<<Object1.deleteAccount("hfd")<<endl;
//     cout<<Object1.databaseSize()<<endl;
//     // Object1.createAccount("CDAD7786825_7990768648" , 648);
//     // Object1.createAccount("DCDA7547234_9919615552" , 552);
//     // Object1.createAccount("AACB1850545_7974534788" , 788);
//     // cout<<Object1.databaseSize()<<endl;
//     // Object1.createAccount("CDBD5250777_1124276711" , 711);
//     // Object1.createAccount("ABCB8377155_0656808575" , 575);
//     // Object1.getTopK(1);
//     // Object1.createAccount("CDDC3792028_3313680038" , 38);
//     // Object1.createAccount("CBBA9574444_7470182321" , 321);
//     // Object1.createAccount("DBCC4334636_8057544188" , 188);
//     // Object1.getTopK(3);
//     // Object1.createAccount("BABD5741078_5109455304" , 304);
//     // Object1.createAccount("BCBA7529510_0817878868" , 868);
//     // cout<<Object1.databaseSize()<<endl;
//     // Object1.getTopK(1);
//     // Object1.addTransaction("BCBA7529510_0817878868",-860);
//     // cout<<Object1.getBalance("BCBA7529510_0817878868")<<endl;
//     // Object1.getTopK(1);
//     // Object1.addTransaction("DCDA7547234_9919615552",592);
//     // Object1.getTopK(5);
//     // Object1.deleteAccount("DCDA7547234_9919615552");
//     // // Object1.getTopK(4);
//     // cout<<Object1.databaseSize()<<endl;
    

// }

