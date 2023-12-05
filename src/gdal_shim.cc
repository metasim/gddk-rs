#include "gddk-rs/include/gdal_shim.h"

std::unique_ptr<GDALDriverManager> get_driver_manager() {
  return std::unique_ptr<GDALDriverManager>(GetGDALDriverManager());
}