#pragma once

#include "LabyrinthFieldWithoutHalts.h"
#include "LabyrinthFieldWithHalts.h"
#include "LabyrinthPrinter.h"

typedef std::vector<LabyrinthFieldWithoutHalts> fields_without_halts_t;
typedef std::vector<LabyrinthFieldWithHalts> fields_with_halts_t;  

class LabyrinthSolver {
public:
  // Getters
  fields_without_halts_t getFieldsWithoutHalts() const;
  fields_with_halts_t getFieldsWithHalts() const;
  LabyrinthFieldWithoutHalts getFieldWithoutHaltsWithShortestTrace() const;
  LabyrinthFieldWithHalts getFieldWithHaltsWithShortestTrace() const;

  void findRoutesWithoutHalts(const LabyrinthFieldWithoutHalts& field);
  void findRoutesWithHalts(const LabyrinthFieldWithHalts& field);

private:
  fields_without_halts_t fieldsWithoutHalts_;
  fields_with_halts_t fieldsWithHalts_;

  void findRoutesWithoutHalts(LabyrinthFieldWithoutHalts field, row_t row, column_t column);
  void findRoutesWithHalts(LabyrinthFieldWithHalts field, row_t row, column_t column, size_t haltsNumber);
};

