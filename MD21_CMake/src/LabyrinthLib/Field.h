#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "AnsiColors.cpp"
#include "Cell.h"

typedef std::string file_path_t;
typedef std::vector<Cell> field_t;

class Field {
public:
  Field(const file_path_t& filePath);

  Cell& operator()(const cell_row_t& row, const cell_column_t& column);
  void operator=(const file_path_t& filePath);

  // Getters
  field_t getField() const;
  const Cell* getStart() const;
  const Cell* getFinish() const;

  size_t countSteps() const;

  bool isCellExist(const cell_row_t& row, const cell_column_t& column) const;
  bool isFirstStep() const;

protected:
  field_t field_;
  Cell* start_;
  Cell* finish_;

private:
  void defineStart();
  void defineFinish();
};

