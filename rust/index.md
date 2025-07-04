# Learn You a Rust for Great Good!

> 不想寫前端了嗚嗚嗚嗚嗚嗚

想學個 Rust，去寫更底層的程式

## Install

安裝蠻簡單的，直接一口氣裝一大包

```sh
curl --proto '=https' https://sh.rustup.rs -sSf | sh
```

確認安裝成功

```sh
rustc --version
# rustc 1.87.0 (17067e9ac 2025-05-09)

#更新 rust 版本
rustup update
```

編譯像是 g++

```sh
 # 編譯
rustc main.rs
 # 執行可執行檔
./main
```

## 開新專案

cargo 就像是 npm

```sh
# 開新專案 
cargo new hello_cargo
cd hello_cargo
# 編譯
cargo build
# 可執行檔在這
./target/debug/hello_cargo
# 或是藉由 cargo 執行
cargo run

## 快速檢查能不能編譯
cargo check

# build production 版
cargo build --release
```
