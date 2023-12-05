
#[cxx::bridge]
mod ffi {
//    #[namespace="::"]
    unsafe extern "C++" {
        include!("gddk-rs/include/gdal_shim.h");
        type GDALDriverManager;
        fn get_driver_manager() -> UniquePtr<GDALDriverManager>;
        //fn GetDriverCount(&self) -> i32;
    }
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let dmgr = ffi::get_driver_manager();
        //let cnt = dmgr.GetDriverCount();
        dbg!(dmgr.is_null());
    }
}
