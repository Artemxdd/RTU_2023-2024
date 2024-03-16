#pragma once

#include "LabyrinthField.h"

typedef std::vector<LabyrinthField> fields_with_routes_t;

class LabyrinthSolver : public LabyrinthField {
public:
  LabyrinthSolver(const file_path_t& filePath);
  
  fields_with_routes_t getFieldsWithRoutes() const; // Getter

  void findRoutes(LabyrinthField field, row_t row, column_t column);
  //void findRoutesWithHalts(LabyrinthField field, row_t row, column_t column);

private:
  fields_with_routes_t fieldsWithRoutes;
};

