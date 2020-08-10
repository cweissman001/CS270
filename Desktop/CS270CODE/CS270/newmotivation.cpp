
class big_object {
	int data[10000];
};

big_object* build_big_object() {
	//Build the object
	big_object* returnval = new big_object(); //new will always create an object and pointer to that object and return a pointer
	return returnval
}

int main() {
big_object* var = build_big_object();
(*var).data[0] //Access the thing that var points to 
delete var;// for every new there must for a corresponding delete
//because of dynamic memory allocation you do not have too delete in same function - should come before reassingment 
//you will want to set pointer to refer to an invald thing after deleting object
var = NULL;
var = build_big_object();
delete var; //one for every "new" keyword
	//all delete does is remove te object that the pointer points to 
var = nullptr; //you need to reassign always after deleting
//nullptr and NULL mean the same but first is more common
}