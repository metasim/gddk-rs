#include "gdal.h"
#include "gdal_priv.h"

std::unique_ptr<GDALDriverManager> get_driver_manager();