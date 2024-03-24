#pragma once

#include "Field.h"
#include "FieldWithHalts.h"
#include "Printer.h"

typedef std::vector<Field> fields_without_halts_t;
typedef std::vector<FieldWithHalts> fields_with_halts_t;  

class Solver {
public:
  // Getters
  fields_without_halts_t getFieldsWithoutHalts() const;
  fields_with_halts_t getFieldsWithHalts() const;
  Field getFieldWithoutHaltsWithShortestTrace() const;
  FieldWithHalts getFieldWithHaltsWithShortestTrace() const;

  void findRoutesWithoutHalts(const Field& field);
  void findRoutesWithHalts(const FieldWithHalts& field);

private:
  fields_without_halts_t fieldsWithoutHalts_;
  fields_with_halts_t fieldsWithHalts_;

  void findRoutesWithoutHalts(Field field, cell_row_t row, cell_column_t column);
  void findRoutesWithHalts(FieldWithHalts field, cell_row_t row, cell_column_t column, size_t haltsNumber);
};

