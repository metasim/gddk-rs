#pragma once
#include "/opt/homebrew/include/gdal.h"

std::unique_ptr<GDALDriverManager> get_driver_manager();