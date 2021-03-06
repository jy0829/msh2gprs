#pragma once

#include "simdata.hpp"
#include "transes.hpp"


class OutputData
{
public:
   OutputData(SimData * pSimData);
  ~OutputData();

  void write_output(const std::string & output_path);
  void writeGeomechDataNewKeywords(const std::string & output_path);

protected:
  SimData * pSim;
};
