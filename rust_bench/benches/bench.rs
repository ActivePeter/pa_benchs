use criterion::{black_box, criterion_group, criterion_main, Criterion, BenchmarkId};
use std::fs::{OpenOptions, File};
use std::sync::RwLock;
use std::io::Write;

// use criterion::async_executor::FuturesExecutor;
fn touch() -> File {
    OpenOptions::new().create(true).write(true).open("./test").unwrap()
}

fn std_write(c: &mut Criterion){
    let lock=RwLock::new(());
    let mut f =touch();
    std::thread::sleep(std::time::Duration::from_secs(5));

    c.bench_function("lock_and_write", |b| b.iter(|| {
        let guard=lock.write().unwrap();
        f.write("hhhh".as_bytes());
    }));
    c.bench_function("nolock_write", |b| b.iter(|| {
        // let guard=lock.write().unwrap();
        f.write("hhhh".as_bytes());
    }));
}

fn tokio_worker_write(c: &mut Criterion){
    let lock=RwLock::new(());
    let mut f =touch();
    std::thread::sleep(std::time::Duration::from_secs(5));

    c.bench_function("lock_and_write", |b| b.iter(|| {
        let guard=lock.write().unwrap();
        f.write("hhhh".as_bytes());
    }));
}



criterion_group!(benches,
    std_write
);
criterion_main!(benches);