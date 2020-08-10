class String {
 public:
	
	String( ); //constructor
	//add 
	
	int get_length();
	
	void erase(int index); //remove a char
	
	void erase(int start, int end); //erase multiple chars
	
	String substr(int start, int end);
	
	String operator+(const String& other); //add strings together and creates new 
	
	void operator+=(const String& other); //adds to current string
	
	bool operator<(const String& other); //compare by alpha/lexographic(alpha that says capital and lower are diff) order
	
	void replace(int index, char newchar); //replace one char
	
	void replace(int start, int end, const String& newchars); //replaces part of the string
	
	char& operator[](int index); //lets you reassign one char in original string(must use reference to actaully change)
 	
	
	
	/*void operator<<(); //print strings
	String alphabatize();
	String dups();
	*/
	
 private:
	char data[1000]; //assume a max size for now
 	int length;
	
 };