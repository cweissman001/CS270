#include "Caesar.h"
using namespace std;

static const int maxchar = 'z';
static const int minchar = ' ';
static const int charrange = 1 + maxchar - minchar;

// Caesar constructor, accepts a single string argument as the cipher
// key


// get_key: return the current cipher key


//decode: decode the string argument using the key, return decoded string


//encode: encode the string argument using the key, return encoded string

char safemod(int val, int mod) {
  int modval = val % mod;
  if (modval < 0) {
    modval += mod;
  }
  return char(modval);
}

Caesar::Caesar(string h){
	key= h;
}
    // return the current cipher key
string Caesar::get_key() const {
	return key;
}


string Caesar::encode(string mess) const{
    
	int leng = mess.length(); 
	int leng2 = key.length();
	string answer; //decoded message
	int in; //int to help count

	int ans = 0; //number of new num for new string
	
	for(in =0; in<leng; in++) {
		ans = ((int)key[in % leng2]-minchar) + ((int)mess[in]-minchar); 
			if(ans > charrange){ 
			ans = ans % charrange;
			}
		answer =  answer + (char)(ans + minchar);
		
	}
	return answer;
}
	
string Caesar::decode(string mess) const {
	int leng = mess.length();
	int leng2 = key.length();
	string answer; //decoded message
	int in; //int to help count
	int ans = 0; //number of new num for new string
		
		for(in = 0; in<leng; in++){
			ans = ((int)mess[in]-minchar) - ((int)key[in % leng2]- minchar);
			
		if(ans < 0){
			ans = safemod(ans, charrange);
		}
			
		answer += (char)(ans + minchar);
		
		
		
		}
			
return answer;
} 
/*encode: a function that takes in a key and an unencrupted message, and returns 
the encrypted message*/






