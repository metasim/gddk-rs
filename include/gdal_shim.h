#pragma once
#include "gdal.h"
#include "gdal_pam.h"
#include "gdal_priv.h"

struct RustDriverMetadata;

class RustDataset final: public GDALPamDataset
{
  public:
    RustDataset();
    ~RustDataset();

     static GDALDataset *Create(const char *pszFilename, int nXSize,
                                int nYSize, int nBands, GDALDataType eType,
                                char **papszParamList);
};

void register_rust_driver(RustDriverMetadata);
