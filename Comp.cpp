#include "Comp.h"
using namespace std ; 


void Comp::createAccount(std::string id, int count) {
   int value = hash(id);
   int dummy=0;
   if(bankStorage2d[value].size()==0){
    Account NewAccount;
    NewAccount.id = id;
    NewAccount.balance=count;
    (bankStorage2d[value]).push_back(NewAccount);
    data_size++;
   }
   else{
    for (int i = 0; i < bankStorage2d[value].size(); i++){
    dummy = i;
    if(bankStorage2d[value][i].id == id){break;}
    }
    if(dummy == bankStorage2d[value].size()-1){
    Account NewAccount;
    NewAccount.id = id;
    NewAccount.balance=count;
    (bankStorage2d[value]).push_back(NewAccount);
    data_size++;}
   
   }
   
}

std::vector<int> Comp::getTopK(int k) {
    std::vector<int> balanceVector;
    std::vector<int> topK;
    for(int i=0; i < bankStorage2d.size();i++){
        if(bankStorage2d[i].size()==0){continue;}
        else{
        for(int j =0; j<bankStorage2d[i].size();j++){
            balanceVector.push_back(bankStorage2d[i][j].balance);
        }
    }
    }
    int n = balanceVector.size();
    for (int i = 0; i < k && i < n; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (balanceVector[j] > balanceVector[maxIndex]) { // Changed to >
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
    // for (int i = 0; i < topK.size(); i++)
    // {
    //     cout<<topK[i]<<" ";
    //         }
    // cout<<endl;
    
    return topK;
}

int Comp::getBalance(std::string id) {
    int value = hash(id);
    int dummy=0;
    if(bankStorage2d[value].size()==0){return -1;}
    else{
        for (int i = 0; i < bankStorage2d[value].size(); i++){
        dummy =i;
        if(bankStorage2d[value][i].id==id){break;}
    }
    if(bankStorage2d[value][dummy].id==id){return bankStorage2d[value][dummy].balance;}
    else{return -1;}
    }
    
    
}

void Comp::addTransaction(std::string id, int count) {
    int value=hash(id);
    int dummy=0 ;
    if(bankStorage2d[value].size()==0){
        Account NewAccount;
        NewAccount.id = id;
        NewAccount.balance=count;
        (bankStorage2d[value]).push_back(NewAccount);
        data_size++;
    }
    else{
        for (int i = 0; i < bankStorage2d[value].size(); i++){
        dummy = i;
        if(bankStorage2d[value][i].id==id){
            bankStorage2d[value][i].balance+=count;
            break;}
    }
    if(dummy==(bankStorage2d[value].size())-1&&bankStorage2d[value][dummy].id!=id){
        Account NewAccount;
        NewAccount.id = id;
        NewAccount.balance=count;
        (bankStorage2d[value]).push_back(NewAccount);
        data_size++;
    }
    }
    
    
}




bool Comp::doesExist(std::string id) {
    int value = hash(id);

    for (const Account& account : bankStorage2d[value]) {
        if (account.id == id) {
            return true; // Account found, return true
        }
    }

    return false; // Account not found, return false
}

// bool Chaining::doesExist(std::string id) {
//     int value = hash(id);
//     bool found = false;

//     if (bankStorage2d[value].size() > 0) {
//         for (int i = 0; i < bankStorage2d[value].size(); i++) {
//             if (bankStorage2d[value][i].id == id) {
//                 found = true;
//                 break;
//             }
//         }
//     }

//     return found;
// }


bool Comp::deleteAccount(std::string id) {
    int value = hash(id);

    for (auto it = bankStorage2d[value].begin(); it != bankStorage2d[value].end(); ++it) {
        if (it->id == id) {
            bankStorage2d[value].erase(it);
            data_size--;
            return true; // Account found and deleted
        }
    }

    return false; // Account not found
}



// bool Chaining::deleteAccount(std::string id) {
//     int value = hash(id);
//     int dummy = 0;
//     if (bankStorage2d[value].size() == 0) {
//         return false;
//     } else {
//         for (int i = 0; i < bankStorage2d[value].size(); i++) {
//             dummy = i;
//             if (bankStorage2d[value][i].id == id) {
//                 bankStorage2d[value].erase(bankStorage2d[value].begin() + i);
//                 break;
//             }
//         }
//         if (bankStorage2d[value][dummy].id == id) { 
//             data_size--;
//             return true;
//         } else {
//             return false;
//         }
//     }
// }


int Comp::databaseSize() {
    return data_size;
}

int Comp::hash(std::string id) {
    int hash_ans = 0;
    for (int i = 0; i < id.length(); i++) {
        hash_ans += static_cast<int>(id[i]) * (i + 1); // Multiply by position (1-based)
    }
    int hash_value = hash_ans % 99991;
    return hash_value;
}



// int main()
// {   Comp Object1 ;
//     Object1.createAccount("CDAD7786825_7990768648" , 648);
//     Object1.createAccount("DCDA7547234_9919615552" , 552);
//      Object1.createAccount("AACB1850545_7974534788" , 788);
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
//     Object1.getTopK(1);
//     cout<<Object1.databaseSize()<<endl;
//     Object1.addTransaction("DCDA7547234_9919615552",592);
//     Object1.getTopK(5);
//     cout<<Object1.databaseSize()<<endl;
//     Object1.deleteAccount("DCDA7547234_9919615552");
//     Object1.getTopK(4);
    
//     cout<<Object1.databaseSize()<<endl;
//     // cout<<Object1.doesExist("DCDA7547234_9919615552")<<endl;
//     // cout<<Object1.doesExist("DCDA7547234_9961586552")<<endl;

// }


