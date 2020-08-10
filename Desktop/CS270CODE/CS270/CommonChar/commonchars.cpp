#include <iostream>
#include "commonchars.h"
#include <string>
using namespace std;

string commonchars(string a, string b){
  string common = ""; // new string for common chars
    int found; //int for index
    for(int j=0; j< b.length(); j++){ //loop through str
      for(int i =0; i < a.length(); i++){ // loop through str2
        if(b[j] == a[i]){
          found=common.find(b[j]);
          if(found < 0) {
            common.append(1, ' ');
            common.append(1, b[j]);
            common.append(1, ',');
            
          
          }
          break;
        }
        }
      }
  common[(common.length()-1)] = '\0'; //cutting off last comma
  return common;
  }