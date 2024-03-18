#pragma once

#include "LabyrinthFieldWithoutHalts.h"
#include "LabyrinthFieldWithHalts.h"
#include "LabyrinthPrinter.h"

//typedef std::vector<LabyrinthFieldWithoutHalts> fields_without_halts_t;
//typedef std::vector<LabyrinthFieldWithHalts> fields_with_halts_t;  

template<class T>
class LabyrinthSolver {
public:
  //LabyrinthSolver(const file_path_t& filePath);
  LabyrinthSolver(const T& labyrinthField);
  
  // Getters
  std::vector<T> getRoutes() const;
  //fields_without_halts_t getFieldsWithoutHalts() const;
  //fields_with_halts_t getFieldsWithHalts() const;

  void findRoutes();
  //void findRoutesWithoutHalts(LabyrinthFieldWithoutHalts field, row_t row, column_t column);
  //void findRoutesWithHalts(LabyrinthFieldWithHalts field, row_t row, column_t column, size_t haltsNumber);

private:
  T labyrinthField_;
  std::vector<T> labyrinthRoutes_;
  //fields_without_halts_t fieldsWithoutHalts_;
  //fields_with_halts_t fieldWithHalts_;
  //FieldType fieldType_;

  void findRoutes(T field, row_t row, column_t, size_t haltsNumber);
};

