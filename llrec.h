#ifndef LLREC_H
#define LLREC_H
#ifndef NULL
#define NULL 0
#endif

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

/**
 * Node struct for both problems
 */
struct Node
{
    int val;
    Node *next;

    Node(int v, Node* n) : val(v), next(n) {}
};


/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot);

/**
 * Given a linked list pointed to by head, removes (filters out) nodes
 * whose value does not meet the criteria given by the predicate
 * function object, pred (i.e. pred should be a function object that implements
 * `bool operator()(int value)` and returns *true* for items that should
 * be *removed/filtered*.  Removed items should be deallocated.
 *
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @param[in] head
 *   Reference to the head pointer to the input list.
 * @param[in] pred
 *   Predicate object implementing: `bool operator()(int value)` that
 *   returns true if a node (based on its value) should be removed.
 * @return a head pointer to the resulting list (since the head pointer
 *   may change [i.e. be filtered])
 *
 */


//*****************************************************************************
// Since template implementations should be in a header file, we will
// implement the above function now.
//*****************************************************************************

template <typename Comp>
Node* llfilter(Node* head, Comp pred)
{
    //*********************************************
    // Provide your implementation below
    //*********************************************
  if (head == nullptr) {
        return nullptr;
    }
    
    Node* filteredNext = llfilter(head->next, pred);
    
    if (pred(head->val)) {
        delete head;
        return filteredNext;
    } else {
        head->next = filteredNext;
        return head;
    }

}

/**
 * Templated Stack class
 */
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack() = default;
    
    size_t size() const {
        return std::vector<T>::size();
    }
    
    bool empty() const {
        return std::vector<T>::empty();
    }
    
    void push(const T& item) {
        this->push_back(item);
    }
    
    void pop() {
        if (this->empty()) {
            throw std::underflow_error("Stack is empty");
        }
        this->pop_back();
    }
    
    T const & top() const {
        if (this->empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return this->back();
    }
};




/**
 * Functor for alphabetic string comparison
 */
struct AlphaStrComp {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        return lhs < rhs;
    }
};

/**
 * Functor for string length comparison
 */
struct LengthStrComp {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        return lhs.size() < rhs.size();
    }
};

/**
 * Generic comparison function using functors
 */
template <class Comparator>
void DoStringCompare(const std::string& s1, const std::string& s2, Comparator comp) {
    std::cout << comp(s1, s2) << std::endl;
}

#endif
