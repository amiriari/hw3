#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : m_(m), comp_(c) {}

  /**
  * @brief Destroy the Heap object
  * 
  */
  //~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item) { 
      heap_.push_back(item);
      heapifyUp(heap_.size() - 1);
  }

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const {
        if (empty()) {
            throw std::underflow_error("Heap is empty");
        }
        return heap_.front();
    }

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop() {
        if (empty()) {
            throw std::underflow_error("Heap is empty");
        }
        std::swap(heap_.front(), heap_.back());
        heap_.pop_back();
        heapifyDown(0);
    }


  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const{//ADDED
      return heap_.empty();
  }

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const { 
      return heap_.size();
  }

private:

  std::vector<T> heap_;
  int m_;
  PComparator comp_;

  void heapifyUp(size_t index) {
      if (index == 0) return;
      size_t parent = (index - 1) / m_;
      if (comp_(heap_[index], heap_[parent])) {
          std::swap(heap_[index], heap_[parent]);
          heapifyUp(parent);
      }
  }


  void heapifyDown(size_t index) {
      size_t best = index;
      for (int i = 1; i <= m_; ++i) {
          size_t child = m_ * index + i;
          if (child < heap_.size() && comp_(heap_[child], heap_[best])) {
              best = child;
          }
      }
      if (best != index) {
          std::swap(heap_[index], heap_[best]);
          heapifyDown(best);
      }
  }
};



#endif

