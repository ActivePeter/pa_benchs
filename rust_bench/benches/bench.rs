use criterion::{black_box, criterion_group, criterion_main, Criterion, BenchmarkId};
use std::fs::{OpenOptions, File};
use std::sync::{RwLock, Arc, Mutex};
use std::io::Write;

// use criterion::async_executor::FuturesExecutor;
fn touch() -> File {
    OpenOptions::new().create(true).write(true).open("./test").unwrap()
}

fn std_write(c: &mut Criterion){
    let lock=Arc::new(RwLock::new(()));
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
    let mut f =touch();
    let vec=Arc::new(Mutex::new(Vec::<String>::new())) ;
    {
        let vec = vec.clone();
        std::thread::spawn(
            move || {
                loop {
                    std::thread::sleep(std::time::Duration::from_micros(1));
                    {
                        let r_ = vec.try_lock();
                        if let Ok(mut r) = r_ {
                            if !r.is_empty() {
                                for s in r.iter() {
                                    f.write_all(s.as_bytes()).unwrap();
                                }
                                r.clear();
                            }
                        }
                    }
                    // res.send(()).unwrap();
                }
            });
    }
    std::thread::sleep(std::time::Duration::from_secs(5));

    c.bench_function("tokio_worker_write", |b| b.iter(|| {
        loop{
            let vec_=vec.lock();
            if let Ok(mut vec__)=vec_{
                vec__.push("ssss".to_string());
                break;
            }
        }

        // let (t1,r1)=tokio::sync::oneshot::channel();
        // t.blocking_send("ssssssssssssssssssss".to_string());
        // r1.blocking_recv();
    }));
}

fn mmap(){

}

criterion_group!(benches,
    // std_write,
    tokio_worker_write
);
criterion_main!(benches);