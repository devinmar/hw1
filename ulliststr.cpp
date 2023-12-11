#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

// adds a new value to the back of the list
void ULListStr::push_back(const std::string& val) {
	// checks if the list is empty or the last item's array is full
    if (tail_ == NULL || tail_->last == ARRSIZE) {
        Item* newItem = new Item;
        newItem->prev = tail_;
        if (tail_) {
            tail_->next = newItem;
        }
        tail_ = newItem;
				// links the current tail's next node to the new item, if tail exists
        if (head_ == NULL) {
            head_ = newItem;
        }
    }
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
}

// adds a new value to the front of the list
void ULListStr::push_front(const std::string& val) {
    // case when list is empty
    if (head_ == NULL) {
        head_ = new Item;
        tail_ = head_;
        head_->val[ARRSIZE - 1] = val;
        head_->first = ARRSIZE - 1;
        head_->last = ARRSIZE;
    } 
    // case when there's no space at the front of the first Item
    else if (head_->first == 0) {
        Item* newItem = new Item;
        newItem->next = head_;
        head_->prev = newItem;
        head_ = newItem;
        head_->val[ARRSIZE - 1] = val;
        head_->first = ARRSIZE - 1;
        head_->last = ARRSIZE;
    } 
    // case when there's space at the front of the first Item
    else {
        head_->first--;
        head_->val[head_->first] = val; // direct assignment to the array
    }
    size_++;
}

// removes a value from the back of the list
void ULListStr::pop_back() {
	// checks if the list is not empty
    if (tail_ != NULL) {
        tail_->last--;
        size_--;
				// checks if the last item becomes empty
        if (tail_->first == tail_->last) {
            Item* temp = tail_;
            tail_ = tail_->prev;
            delete temp;
						// update next of the new tail or set head to NULL if list is empty
            if (tail_) {
                tail_->next = NULL;
            } else {
                head_ = NULL;
            }
        }
    }
}

// removes a value from the front of the list
void ULListStr::pop_front() {
	// checks if the list is not empty
    if (head_ != NULL) {
        head_->first++;
        size_--;
				// checks if the first item becomes empty
        if (head_->first == head_->last) {
            Item* temp = head_;
            head_ = head_->next;
            delete temp;
						// updates prev of the new head or set tail to NULL if list is empty
            if (head_) {
                head_->prev = NULL;
            } else {
                tail_ = NULL;
            }
        }
    }
}

// returns a const reference to the back element of the list
std::string const & ULListStr::back() const {
	// throws exception if the list is empty
    if (tail_ == NULL) {
        throw std::invalid_argument("List is empty");
    }
    return tail_->val[tail_->last - 1]; // return the last element
}


// returns a const reference to the front element of the list
std::string const & ULListStr::front() const {
	  // throw exception if the list is empty
    if (head_ == NULL) {
        throw std::invalid_argument("List is empty");
    }
    return head_->val[head_->first]; // return the first element
}


// returns a pointer to the value at a specific location in the list
std::string* ULListStr::getValAtLoc(size_t loc) const {
	// returns NULL if the location is out of bounds
    if (loc >= size_) {
        return NULL;
    }
    Item* temp = head_;
    while (temp != NULL) {
        size_t numElems = temp->last - temp->first;
				// checks if the location is within the current item
        if (loc < numElems) {
            return &temp->val[temp->first + loc];
        }
        loc -= numElems;
        temp = temp->next;
    }
    return NULL;
}

// END OF MY CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

// comment to track to github