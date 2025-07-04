fn main() {
}

fn basic() {
    println!("Hello, world!");

    let x = 5; // 變數預設是 immutable 的
    println!("x 的數值為：{x}"); // string template

    let mut y = 6;
    println!("y 的數值為：{y}");
    y = 7;
    println!("y 的數值為：{y}");

    // 老朋友 const，後面的 u32 是 data type
    const THREE_HOURS_IN_SECONDS: u32 = 60 * 60 * 3;
}

fn shadowing() {
    let x = 5;

    // 這個行為叫遮蔽，可以暫時改變 immutable 變數的值
    let x = x + 1;

    {
        // 用大括號當作用範圍
        let x = x * 2;
        println!("x 在內部範圍的數值為：{x}");
    }

    // 出了作用範圍就會恢復成原本的值
    println!("x 的數值為：{x}");

    // 與 mut 不同的是 shadowing 可以改變資料型態
    let mut y = 1;
    y = 2;
    let y = "hello";
    // y = "world" // GG

    println!("y 的數值為：{y}");
}

fn data_type() {
    let i: i32 = 32; // int 32
    let u: u32 = 32; // unsigned int 32
    let f: f32 = 3.2; // float 32
    let b: bool = true; // 布林值
    let c: char = 'c';

    // 四則運算跟以前一樣
    // 整數相除一樣會自動 floor

    // 類似 struct 的數組
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    let (x1, y2, z3) = tup; // 解構賦值
    let x1 = tup.0; // 也可以用 index

    // array 登場
    let a1 = [1, 2, 3, 4, 5];
    // 宣告型態 / 長度
    let a2: [i32; 5] = [1, 2, 3, 4, 5];
    // fill(5)
    let a3 = [3; 5];
    let x2 = a1[0]; // 這可老熟了
}

fn add(a: i32, b: i32) -> i32 {
    return a + b;
}

fn increment(a: i32) -> i32 {
    // 可以寫成表達式 expressions
    let b: i32 = { a + 1 };

    println!("b 的數值為：{}", b);

    return a + 1;
}
