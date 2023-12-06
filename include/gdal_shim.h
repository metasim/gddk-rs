#pragma once
#include "gdal.h"
#include "gdal_pam.h"
#include "gdal_priv.h"
#include "rust/cxx.h"

struct RustDriverMetadata;

class RustDataset final: public GDALPamDataset
{
  public:
    RustDataset(RustDriverMetadata);
    ~RustDataset();

     static GDALDataset *Create(RustDriverMetadata metadata, const char *pszFilename, int nXSize,
                                int nYSize, int nBands, GDALDataType eType,
                                char **papszParamList);
};

void register_rust_driver(RustDriverMetadata, rust::Fn<int(int, int)>);
