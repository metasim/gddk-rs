
#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        include!("gddk-rs/include/gdal_shim.h");
        pub type GDALDriverManager;
        pub fn get_driver_manager() -> UniquePtr<GDALDriverManager>;
        pub fn GetDriverCount(&self) -> i32;
    }
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let dmgr = ffi::get_driver_manager();
        //dmgr.AutoLoadDrivers();
        dbg!(dmgr.is_null());
        let cnt = dmgr.GetDriverCount();
        dbg!(cnt);
    }
}
