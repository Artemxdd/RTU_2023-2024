#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <fstream>
#include "LabyrinthCell.h"

typedef std::string file_path_t;
typedef std::vector<LabyrinthCell> field_t;

class LabyrinthField {
public:
  LabyrinthField(); // Empty field
  LabyrinthField(const file_path_t& filePath);

  // Getters
  field_t getField() const;
  LabyrinthCell& operator()(const row_t& row, const column_t& column);

  // Setters
  void setCellValue(const row_t& row, const column_t& column, const value_t& value);
  void setCellType(const row_t& row, const column_t& column, const CellType& cellType);

  bool isCellExist(const row_t& row, const column_t& column) const;

private:
  field_t field_;
};

