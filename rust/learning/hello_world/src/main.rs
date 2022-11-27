
fn main() {
    println!("Hello, world!");

    println!("{}, {}!", "Hello", "world");
    println!("{0}, {1}!", "Hello", "world");
    println!("{greeting}, {name}!", greeting="Hello", name="world");

    let y = String::from("Hello, ") + "world!";
    println!("{}", y);
}