#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;



//Node to store the data (Linked List)

class Node {
public:
	string key;
	int value;

	Node(string key, int value) {
		this->key = key;
		this->value = value;
	}
};


//LRU Cache Data Structure

class LRUCache{
public:
	int maxSize;
	list<Node> l;
	unordered_map<string, list<Node>::iterator > m;

	LRUCache(int maxSize) {
		this->maxSize = maxSize > 1 ? maxSize : 1;
	}

	void insertKeyValue(string key, int value) {
		// 2 Cases

		if(m.count(key) != 0) {
		
			//replace the old value and update

			auto it = m[key];
			it->value = value;
		}
		else{
			//check if cache is full or not
			//Remove the least recently used item from cache
			if(l.size() == maxSize) {
				Node last = l.back();
				m.erase(last.key);				//Remove from the hashmap
				l.pop_back();					//Remove from the linked list
			}

			Node n(key, value);
			l.push_front(n);
			m[key] = l.begin();
		}
	}

	int* getValue(string key) {
		//Check if key is present

		if(m.count(key) != 0) {
			auto it = m[key];

			int value = it->value;
			l.push_front(*it);
			l.erase(it);
			m[key] = l.begin();
			return &l.begin()->value;
		}
		return NULL;
	}

	string mostRecentKey() {
		return l.front.key;
	}

	int main() {
		LRUCache lru(3);

		lru.insertKeyValue("mango", 10);
		lru.insertKeyValye("apple", 20);
		lru.insertKeyValue("guava", 30);

		cout << lru.mostRecentKye() << endl;

		lru.insertKeyValue("mango", 40);
		cout << lru.mostRecentKey() << endl;

		lru.insertKeyValue("banana", 20);

		if(lru.getValue("apple") == NULL) {
			cout << "apple doesn't exist";
		}

		if(lru.getValue("guava") == NULL) {
			cout << "guava doesn't exist";
		}

		if(lru.getValue("banana") == NULL) {
			cout << "banana doesn't exist";
		}

		if(lru.getValue("mango") == NULL) {
			cout << "mango doesn't exists";
		}
	}

};