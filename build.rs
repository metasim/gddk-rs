fn main() {
    pkg_config::probe_library("gdal").unwrap();

    cxx_build::bridge("src/lib.rs")
        .file("src/gdal_shim.cc")
        .flag_if_supported("-std=c++11")
        .compile("gddk-rs");
}