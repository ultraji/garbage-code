use std::fs;

//cargo run --bin scrape_url_homework -- "https://www.rust-lang.org/"
fn main(){
    let args: Vec<String> = std::env::args().collect();
    if args.len() < 2 {
        panic!("please input a url!")
    }

    let url = args.get(1).unwrap();
    let output = "rust.md";

    println!("Fetching url: {}", url);
    let body = reqwest::blocking::get(url).unwrap().text().unwrap();

    println!("Converting html to markdown...");
    let md = html2md::parse_html(&body);

    fs::write(output, md.as_bytes()).unwrap();
    println!("Converted markdown has been saved in {}.", output);
}
