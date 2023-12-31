
#[cxx::bridge]
pub mod gdal_ddk {
    struct RustDriverMetadata {
        name: String,
        long_name: String,
    }

    unsafe extern "C++" {
        include!("gddk-rs/include/gdal_shim.h");
        pub fn register_rust_driver(meta: RustDriverMetadata, ctor: fn(i32, i32) -> i32);
    }
}

impl gdal_ddk::RustDriverMetadata {
    pub fn new(name: String, long_name: String) -> Self {
        Self { name, long_name }
    }
}

#[cfg(test)]
mod tests {
    use crate::gdal_ddk::*;

    #[test]
    fn it_works() {
        let meta = RustDriverMetadata::new("RUST".into(), "Demo driver written in Rust".into());
        register_rust_driver(meta, |a, b| a+b);
    }
}
