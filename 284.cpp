/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    int nextNum;
    bool checkNext;
    
    void processNext(void)
    {
        checkNext = Iterator::hasNext();
        
        if(checkNext)
            nextNum = Iterator::next();
    }
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    processNext();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    return nextNum;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int t = nextNum;
	    processNext();
	    return t;
	}

	bool hasNext() const {
	    return checkNext;
	}
};