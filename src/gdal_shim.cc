#include "gdal.h"
#include "gdal_priv.h"
#include "gddk-rs/include/gdal_shim.h"
#include "gddk-rs/src/lib.rs.h"
#include <functional>
#include <iostream>

GDALDataset *RustDataset::Create(const char * /* pszFilename */, int /* nXSize */,
                               int /* nYSize */, int /* nBandsIn */, GDALDataType /*eType*/,
                               char ** /* papszOptions */) {
    return nullptr;
}

void register_rust_driver(RustDriverMetadata metadata) {
    if (GDALGetDriverByName(metadata.name.data()) != nullptr)
        return;

    GDALDriver *poDriver = new GDALDriver();

    poDriver->SetDescription(metadata.long_name.data());
    poDriver->SetMetadataItem(GDAL_DMD_LONGNAME, metadata.long_name.data());
    poDriver->pfnCreate = RustDataset::Create;
    GetGDALDriverManager()->RegisterDriver(poDriver);

    std::cout << "Hi " << metadata.name.data()  << std::endl;
}