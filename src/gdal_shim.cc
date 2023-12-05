#include "gddk-rs/include/gdal_shim.h"

std::unique_ptr<GDALDriverManager> get_driver_manager() {
  auto mgr = GetGDALDriverManager();
  mgr->AutoLoadDrivers();
  return std::unique_ptr<GDALDriverManager>(mgr);
}