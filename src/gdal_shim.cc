#include "gdal.h"
#include "gdal_priv.h"
#include "gddk-rs/include/gdal_shim.h"
#include "gddk-rs/src/lib.rs.h"
#include <functional>
#include <iostream>

GDALDataset *RustDataset::Create(RustDriverMetadata metadata, const char * /* pszFilename */, int /* nXSize */,
                               int /* nYSize */, int /* nBandsIn */, GDALDataType /*eType*/,
                               char ** /* papszOptions */) {
    return nullptr;
}

RustDataset::RustDataset(RustDriverMetadata /* metadata */) {
}


void register_rust_driver(RustDriverMetadata metadata, rust::Fn<int(int, int)> someRustFn) {
    if (GDALGetDriverByName(metadata.name.data()) != nullptr)
        return;

    GDALDriver *poDriver = new GDALDriver();

    poDriver->SetDescription(metadata.long_name.data());
    poDriver->SetMetadataItem(GDAL_DMD_LONGNAME, metadata.long_name.data());

    auto someValue = someRustFn(32, 33);

    auto boundCreate = [metadata](const char *pszFilename, int nXSize,
                                int nYSize, int nBandsIn, GDALDataType eType,
                                char ** papszOptions) {
        return RustDataset::Create(metadata, pszFilename, nXSize, nYSize, nBandsIn, eType, papszOptions);
    };
    // Causes: error: cannot initialize a variable of type 'GDALDataset *(*)(const char *, int, int, int, GDALDataType, char **)' with an rvalue of type '(lambda at src/gdal_shim.cc:28:24) *'
    // GDALDataset *(*pfnCreate)(const char *, int, int, int, GDALDataType, char **) = &boundCreate;
    // poDriver->pfnCreate = pfnCreate;

    GetGDALDriverManager()->RegisterDriver(poDriver);

    std::cout << "Hi " << metadata.name.data() << " " << someValue << std::endl;
}