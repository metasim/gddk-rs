fn main() {
    let cfg = pkg_config::probe_library("gdal").unwrap();

    cxx_build::bridge("src/lib.rs")
        .file("src/gdal_shim.cc")
        .includes(cfg.include_paths)
        .flag_if_supported("-std=c++11")
        .compile("gddk-rs");

    println!("cargo:rerun-if-changed=src/lib.rs");
    println!("cargo:rerun-if-changed=src/gdal_shim.cc");
    println!("cargo:rerun-if-changed=include/gdal_shim.h");
}