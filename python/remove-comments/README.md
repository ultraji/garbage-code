# remove_comments

删除代码文件中的所有注释，支持C，CPP，Java。

## known bug

1. 会匹配到字符串内部的注释符号：
    ```c
    "hello /* comments */ world"  -> "hello  world"
    ```
2. 换行符会产生影响：
    ```c
    // #define f(x)     \
        ((x) * (x))          ->  ((x) * (x))
    ```

## How To Use

```shell
python3 remove_comments.py <src path> <dst path>
# or
./remove_comments.py <src path> <dst path>
```