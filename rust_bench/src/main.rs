#![feature(associated_type_defaults)]
#![feature(type_alias_impl_trait)]
#![feature(generic_associated_types)]

use std::future::Future;

pub trait KvIterator {
    type NextFuture: Future<Output = ()>;

    /// Get the next item from the iterator.
    fn next(&mut self) -> Self::NextFuture;
}

pub struct TestIterator {
    idx: usize,
}

impl KvIterator for TestIterator {
    //这里的具体实现类型靠impl future 自动推导出来了
    type NextFuture = impl Future<Output = ()>;
    fn next(&mut self) -> Self::NextFuture {
        async move { () }
    }
}
// struct HHH{
//
// }
//
// pub trait ApiHandler{
//     type NextFuture =impl Future<Output = ()>;
//
//     fn api_get_notes_mata(&mut self)-> Self::NextFuture;
// }
// impl ApiHandler for HHH{
//     type NextFuture =impl Future<Output = ()>;
//     fn api_get_notes_mata(&mut self) -> Self::NextFuture{
//         async move{
//
//             ()
//         }
//     }
// }

fn main() {
    let a: dyn KvIterator =TestIterator{idx:0};
    println!("Hello, world!");
}
