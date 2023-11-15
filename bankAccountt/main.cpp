//
//  main.cpp
//  bankAccountt
//
//  Created by Kaan Şengün on 14.11.2023.
//

#include <iostream>
#include "bankAccount.h"
using namespace std;


int main(int argc, const char * argv[]) {
    
    bankAccount person1("K","A");
    person1.credit(400);
    person1.displayProfile();
    
    
    return 0;
}
