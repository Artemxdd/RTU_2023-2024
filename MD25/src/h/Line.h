#include <cstdint>
#include <cstddef>

const uint8_t MAX_TEXT_SIZE{ 81 };

class Line {
public:
  Line();
  ~Line() { delete[] text_; };

  size_t size() const { return size_; };
  //  void clear();
  //  bool empty() const;
  void push_back(const char& chr);
  void pop_back();
  const char& front() const { return this->text_[0]; };
  const char* back() const { return this->lastChar_; };
  const char* data() const { return this->text_; };
  
private:
  char* text_;
  char* lastChar_;
  size_t size_;

  void shiftZeroToRight();  // Shifts zero to the right by one position if allowed
};
