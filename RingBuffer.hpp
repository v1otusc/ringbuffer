#ifndef __RINGBUFFER_H__
#define __RINGBUFFER_H__

#include "Nocopyable.hpp"

template <typename T, int N>
class RingBuffer : public Nocopyable {
 public:
  RingBuffer();
  ~RingBuffer() override;

  inline void push_back(const T& data);
  inline void pop_front();
  inline void pop_front(int num);

  inline bool empty() const;
  inline bool full() const;
  inline int size() const;
  inline void clear();

  inline T* const index_ptr(int i);
  inline T* const front_ptr(int i);
  inline T* const back_ptr(int i);

  inline T index(int i) const;
  inline T front(int i) const;
  inline T back(int i) const;
  inline T operator[](int i) const;

 private:
  int head_;
  int tail_;
  T buffer_[1 << N];  // 2^N
  const int buffer_size_;
  const int buffer_size_1_;  // buffer_size_ - 1
};

template <typename T, int N>
RingBuffer<T, N>::RingBuffer()
    : head_(0),
      tail_(0),
      buffer_size_(1 << N),
      buffer_size_1_(buffer_size_ - 1){};

template <typename T, int N>
RingBuffer<T, N>::~RingBuffer() {
  clear();
}

template <typename T, int N>
inline void RingBuffer<T, N>::push_back(const T& data) {
  buffer_[head_] = data;

  head_ = (head_ + 1) & buffer_size_1_;
  if (head_ == tail_) tail_ = (tail_ + 1) & buffer_size_1_;
}

template <typename T, int N>
inline void RingBuffer<T, N>::pop_front() {
  if (empty()) return;

  tail_ = (tail_ + 1) & buffer_size_1_;
}

template <typename T, int N>
inline void RingBuffer<T, N>::pop_front(int num) {
  if (num <= 0) return;

  if (empty()) return;

  if (num >= size()) {
    clear();
    return;
  }

  tail_ = (tail_ + num) & buffer_size_1_;
}

template <typename T, int N>
inline bool RingBuffer<T, N>::empty() const {
  return (head_ == tail_);
}

template <typename T, int N>
inline bool RingBuffer<T, N>::full() const {
  return ((head_ + 1) & buffer_size_1_) == tail_;
}

template <typename T, int N>
inline int RingBuffer<T, N>::size() const {
  return (head_ + buffer_size_ - tail_) & buffer_size_1_;
}

template <typename T, int N>
inline void RingBuffer<T, N>::clear() {
  head_ = 0;
  tail_ = 0;
}

template <typename T, int N>
inline T* const RingBuffer<T, N>::index_ptr(int i) {
  return buffer_ + ((tail_ + i) & buffer_size_1_);
}

template <typename T, int N>
inline T* const RingBuffer<T, N>::front_ptr(int i) {
  return buffer_ + ((tail_ + i) & buffer_size_1_);
}

template <typename T, int N>
inline T* const RingBuffer<T, N>::back_ptr(int i) {
  return buffer_ + ((head_ + buffer_size_ - 1 - i) & buffer_size_1_);
}

template <typename T, int N>
inline T RingBuffer<T, N>::index(int i) const {
  return *(buffer_ + ((tail_ + i) & buffer_size_1_));
}

template <typename T, int N>
inline T RingBuffer<T, N>::front(int i) const {
  return *(buffer_ + ((tail_ + i) & buffer_size_1_));
}

template <typename T, int N>
inline T RingBuffer<T, N>::back(int i) const {
  return *(buffer_ + ((head_ + buffer_size_ - 1 - i) & buffer_size_1_));
}

template <typename T, int N>
inline T RingBuffer<T, N>::operator[](int i) const {
  return *(buffer_ + ((tail_ + i) & buffer_size_1_));
}

#endif // __RINGBUFFER_H__
