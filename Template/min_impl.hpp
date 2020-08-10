#include <string>
#include <iostream>
template<class TBD>
TBD minimum(TBD x, TBD y) {
	TBD result = y;
	if(x < y) {
		result = x;
	}
	return result;
	}
	//assuming that you can compare data types using this operator 