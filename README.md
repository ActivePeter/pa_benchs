# pa_code_playground
record my code tests

# cpp

## list_join

std list容器的拼接，裁剪

## cppmove

c++ 实现类似rust的栈上move，只有在最终move处析构才会触发最初设置的回调函数

## static_func_inc

c++相互引用例子，必须要将实现放到c文件中, 头文件中互相向前声明

# rust bench
### 顺序bench

1.首先测试std有锁和无锁的连续写（锁没有影响

![](./rc/std_write.png)

2.测试加入tokio 通道，单个thread worker写

```rust
fn tokio_worker_write(c: &mut Criterion){
    let mut f =touch();
    let (t,mut r)=tokio::sync::mpsc::channel(10);
    std::thread::spawn(
        move ||{
            loop{
                let res:tokio::sync::oneshot::Sender<()>=r.blocking_recv().unwrap();
                f.write("hhhh".as_bytes());
                res.send(()).unwrap();
            }
    });
    std::thread::sleep(std::time::Duration::from_secs(5));

    c.bench_function("tokio_worker_write", |b| b.iter(|| {
        let (t1,r1)=tokio::sync::oneshot::channel();
        t.blocking_send(t1);
        r1.blocking_recv();
    }));
}
```

![](./rc/wait_worker.png)

可以发现。通道通信耗费挺多时间的。毕竟通道是用于并发环境下，
