#include "../h/Line.h"

Line::Line() {
  this->text_ = new char[MAX_TEXT_SIZE];
  this->text_[0] = '\0';
  this->lastChar_ = &this->text_[0];
  this->size_ = 0;
}

void Line::push_back(const char& chr) {
  if (this->size_ >= MAX_TEXT_SIZE) return;

  shiftZeroToRight();
  this->lastChar_++;
  *this->lastChar_ = chr;
  this->size_++;
}

void Line::pop_back() {
  if (this->size_ <= 0) return;

  this->lastChar_--;
  this->size_--;
}

void Line::shiftZeroToRight() {
  char* zeroPosition{ this->lastChar_ + 1 };
  *(zeroPosition + 1) = '\0';
  *zeroPosition = ' ';
}
