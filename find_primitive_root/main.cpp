//
//  main.cpp
//  find_primitive_root
//
//  Created by Arta Zidele on 13/11/2024.
//


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int isPrimitiveRoot(int k, int num) {
    int modArray[k-1];
    for (int i=0; i<k-1; i++) {
        modArray[i] = 0;
    }
    int primitiveRoot = true;
    for (int i=1; i<k; i++) {
        long long aPow = num;
        for(int j=1; j<i; j++) {
            aPow *= num;
        }
        int newReminder = aPow%k;
        for (int l=0; l<i; l++) {
            if (modArray[l] == newReminder) {
                primitiveRoot = false;
            }
        }
        if (primitiveRoot == false) {
            break;
        } else {
            modArray[i-1] = newReminder;
        }
    }
    if (primitiveRoot == true) {
        return num;
    } else {
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    
    ifstream file("ieeja.txt");
    if(file.is_open()) {
        // nolasa datus
        string rinda;
        getline(file, rinda);
        int k = stoi(rinda);
        int p[k];
        int e[k];
        for (int i=0; i<k; i++) {
            getline(file, rinda);
            p[i] = stoi(rinda);
        }
        for (int i=0; i<k; i++) {
            getline(file, rinda);
            e[i] = stoi(rinda);
        }
        // aprēķina p
        int pMod = 1;
        for (int i=0; i<k; i++) {
            for (int j=0; j<e[i]; j++) {
                pMod *= p[i];
            }
        }
        pMod += 1;
        // atrod primitīvās saknes
        for (int i=0; i<pMod; i++) {
            int possibleRoot = isPrimitiveRoot(pMod, i+1);
            if (possibleRoot != 0) {
                cout<<possibleRoot<<endl;
            }
        }
    }
    file.close();
    return 0;
}
