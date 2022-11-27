use std::sync::Arc;

fn main() {
    let s = Arc::new("hello world");
    let t = s.clone();
    std::thread::spawn(move || {
        println!("{:?}", t)
    });
}