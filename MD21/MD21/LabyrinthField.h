#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <fstream>
#include "LabyrinthAnsiColors.cpp"
#include "LabyrinthCell.h"

typedef std::string file_path_t;
typedef std::vector<LabyrinthCell> field_t;

enum FieldType {
  WITH_HALTS,
  WITHOUT_HALTS,
  UNDEFINED
};

class LabyrinthField {
public:
  LabyrinthField(); // Empty field
  LabyrinthField(const file_path_t& filePath);

  // Getters
  field_t getField() const;
  LabyrinthCell& operator()(const row_t& row, const column_t& column);
  const LabyrinthCell* getStart() const;
  const LabyrinthCell* getFinish() const;

  // Setters
  void setCellValue(const row_t& row, const column_t& column, const value_t& value);
  void setCellType(const row_t& row, const column_t& column, const CellType& cellType);

  bool isCellExist(const row_t& row, const column_t& column) const;
  bool isFirstStep() const;

protected:
  field_t field_;
  LabyrinthCell* start_;
  LabyrinthCell* finish_;
  FieldType type_;

  virtual void defineType() = 0;

private:
  void defineStart();
  void defineFinish();
};

