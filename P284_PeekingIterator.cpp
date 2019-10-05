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
private:
    int m_status;
    int m_next;
    bool m_hasnext;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    m_status = 0;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(!m_status){
            if(Iterator::hasNext())
                m_next = Iterator::next();
        }
        m_status = 1;
        return m_next;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(m_status) {}
        else{
            if(Iterator::hasNext())
                m_next = Iterator::next();
        }
        m_status = 0;
        return m_next;
	}

	bool hasNext() const {
	    if(m_status){
            return true;
        }
        return Iterator::hasNext();
	}
};
