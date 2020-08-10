#include <iostream>
using namespace std;

const int maxchar = 'z';
const int minchar = ' ';
const int charrange = 1 + maxchar - minchar;
//A mod function that is "safe" to use even when val might be negative

char safemod(int val, int mod) {
  int modval = val % mod;
  if (modval < 0) {
    modval += mod;
  }
  return char(modval);
}


string encode(string key, string mess){
    
	int leng = mess.length(); 
	int leng2 = key.length();
	string answer; //decoded message
	int in; //int to help count

	int ans = 0; //number of new num for new string
	
	for(in =0; in<leng; in++) {
	ans = ((int)key[in % leng2]-minchar) + ((int)mess[in]-minchar); /* adding the casted int of both message and key that are both downshifted to make 32=0 in the context of the code */
	if(ans > charrange)
		ans = ans % charrange;
	answer =  answer + (char)(ans + minchar); /* casting number to char to add to string and making sure to add minchar to shift back up */
		
	}
	return answer;
}
	
string decode(string key, string mess) {
	int leng = mess.length();
	int leng2 = key.length();
	string answer; //decoded message
	int in; //int to help count
	int ans = 0; //number of new num for new string
		
		for(in = 0; in<leng; in++){
		ans = ((int)mess[in]-minchar) - ((int)key[in % leng2]- minchar);
			//cout<< in<< " Before mod: " << ans << endl;
		if(ans < 0){
			ans = safemod(ans, charrange);
		}
			
		answer = answer + (char)(ans + minchar);
		
		//cout<< in<< " After Mod: " << ans << endl;
		
		}
			
return answer;
} 
/*encode: a function that takes in a key and an unencrupted message, and returns 
the encrypted message*/


int main() {

	
string keyword;
string sentence; 
cout << "Enter a message : ";
cin >> sentence;
cout << "Enter a keyword: ";
cin >> keyword;

cout << "Would you like to encode or decode the message? 1 for encode and 2 for decode: ";
int code;
cin >> code;
	
string returnCode;
	
if(code == 1) {
	returnCode = encode(keyword, sentence);
	cout << "Encoded Message: " << returnCode <<endl;
}
else { 
	returnCode = decode(keyword, sentence);	
	cout << "Decoded Message: " << returnCode << endl;

}

	
}
