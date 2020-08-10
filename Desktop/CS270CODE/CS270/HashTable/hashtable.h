#ifndef CS270_HASHTABLE
#define CS270_HASHTABLE

#include <string>
#include <list>
#include <utility>
#include <vector>
#include <exception>
#include <iostream>



int hashCode(const char* bytes, int len) {
  int hash = 0;
  for (int i = 0; i < len; i++) {
    hash = (bytes[i]*hash) + i;
  }
  return hash;
}

template<class K> //this hashes the numbers in the memory location
int hashCode(const K& key) { //allows you to hash any object
  //Convert any object into an array of "characters"
  const char* bytes = reinterpret_cast<const char*>(&key);
  int size = sizeof(K);
  return hashCode(bytes, size);
}

template<> //this says it is still matching above template but k known
//this is an exception--says use this if it is a std string
int hashCode(const std::string& key) {
  //Convert string into an array of characters
  return hashCode(key.c_str(), key.length()); //c_str() gets the array of chars
}

template<class K, class V>
class HashTable { //built ot be used as a map
 public:
  typedef std::pair<K, V> Entry; //means one entry is a key/val pair
  typedef const std::pair<K, V> ConstEntry;
  typedef std::pair<K, V>* EntryPtr;
  typedef typename std::list<Entry>::iterator TableIter;

 private:
  std::vector< std::list<Entry> > theTable; //vector of lists
	//list is a more powerful version of a list-doubly linked list
  int _size;

  void resize() {
    //Do we need to grow the array?
    if (theTable.size() > _size) {
      //Nope
      return;
    } else { //array is too small
      _size = 0; //reset size to be zero
      std::vector< std::list<Entry> > oldTable = theTable; //make a new table vector to store the old table values
      //Reset and resize theTable
      theTable.clear(); //clear the current table
      theTable.resize(2*oldTable.size()); //make the current table double the size

      //for each bucket
      //for ( std::vector<std::list<Entry> >::iterator it = oldTable.begin(); it != oldTable.end(); it++) {
      for ( auto it = oldTable.begin(); it != oldTable.end(); it++) { //nested loops to reassign all the values
      //  for each entry in bucket
      //  remember -std=c++11
      //  TableIter is a shortcut for "typename std::list<Entry>::iterator"
        for (TableIter it2 = (*it).begin(); it2 != (*it).end(); it2++) {
      //    re-add entry to table
          Entry e = (*it2);
          insert(e.first, e.second );
          //int bucket_id = hashCode( e.first ) % theTable.size();
          //theTable[bucket_id].push_front(e);
          
        }
      }


    }
  }

  //Return a valid iterator if this list contains an entry matching the given key
  //Return an invalid iterator (bucket.end()) otherwise
  TableIter //helper function to find the value of the key
  find_in_bucket(std::list<Entry>& bucket, const K& key) {
    //for each entry in bucket
    for ( TableIter it = bucket.begin() ; it != bucket.end(); it++) {
    //  if entry key matches given key return that entry
      if ( (*it).first == key) {
        return it;
      }
    }
    //Otherwise return invalid entry
    return bucket.end();
  }

 public:
  //Interfaces
  //void insert(ConstEntry e);
  HashTable() : theTable(3), _size(0) { };


  V& find(const K& key) { //this is all O(1) since it is constant
    int bucket_id = hashCode(key) % theTable.size();
    TableIter it = find_in_bucket(theTable[bucket_id], key);
    //Return the associated value if found, or throw an exception if not
    if (it != theTable[bucket_id].end()) {
      return it->second;
    } else {
      throw std::exception(); //causing an error to be reported
		//program still terminates but gives more info
    }
  }
  void insert(const K& key, const V& value){
	  int bucket_id = hashCode(key) % theTable.size(); //turn into hash
	  TableIter it = find_in_bucket(theTable[bucket_id], key); //see if duplicate
	  if(it != theTable[bucket_id].end()){
		  //the item is already in the bucket and reassigns
		  it->second = value;
	  	} else{ //adds in the new item
		  theTable[bucket_id].push_front(Entry(key, value));
	  		}
	  
	  }
  void remove(const K& key){
	  int bucket_id = hashCode(key) % theTable.size(); //turn into hash
	  TableIter it = find_in_bucket(theTable[bucket_id], key);
  
      	if (it != theTable[bucket_id].end()) {
      		theTable[bucket_id].erase(it);
			size = size -1;
		}
  }
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
  }
  /*void insert(const K& key, const V& value) {
    int bucket_id = hashCode(key) % theTable.size();
    TableIter it = find_in_bucket(theTable[bucket_id], key);
    if (it != theTable[bucket_id].end()) {
      it->second = value;
    } else {
      theTable[bucket_id].push_back(Entry(key, value));
      _size++;
    }
  }

  void remove(const K& key) { 
    int bucket_id = hashCode(key) % theTable.size();
    TableIter it = find_in_bucket(theTable[bucket_id], key);
    if (it != theTable[bucket_id].end()) {
      theTable[bucket_id].erase(it);
      _size--;
    }
  }
*/
  int size() const {
    return _size;
  }
  bool isEmpty() const { return size() == 0; };

};

#endif //CS270_HASHTABLE