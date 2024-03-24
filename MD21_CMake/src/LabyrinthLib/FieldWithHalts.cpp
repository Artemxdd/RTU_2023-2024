#include "FieldWithHalts.h"

FieldWithHalts::FieldWithHalts(const file_path_t& filePath) : Field(filePath) {
  this->haltsNumber_ = 0;
  for (auto& cell : this->field_)
    if (cell.getType() == cell_type_t::HALT)
      this->haltsNumber_++;
}

size_t FieldWithHalts::getHaltsNumber() const {
  return this->haltsNumber_;
}
