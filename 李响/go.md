### **Go 语言基础语法笔记**

#### **1. 注释**

* 单行注释：`//`
* 多行注释：`/* ... */`

#### **2. 数据类型 & 类型转换**

* 基本类型：`int`, `float64`, `bool`, `string`
* 类型转换：`var b float64 = float64(a)`

#### **3. 变量 & 常量**

* 变量：`var x int` 或 `x := 10`
* 常量：`const Pi = 3.14`

#### **4. 运算符**

* 算术：`+`, `-`, `*`, `/`, `%`
* 比较：`==`, `!=`, `<`, `>`, `<=`, `>=`
* 逻辑：`&&`, `||`, `!`

#### **5. 输入 & 输出**

* 输出：`fmt.Println("Hello")`
* 输入：`fmt.Scan(&x)`

#### **6. 分支逻辑**

```go
if x > 0 {
    fmt.Println("Positive")
} else {
    fmt.Println("Non-Positive")
}
```

#### **7. 循环**

```go
for i := 0; i < 10; i++ {
    fmt.Println(i)
}
```

* `for {}` 无限循环
* `for x > 0 {}` 作为 `while` 用

#### **8. 数组**

```go
var arr [5]int
arr[0] = 10
```

#### **9. 切片**

```go
slice := []int{1, 2, 3}
slice = append(slice, 4)
```

#### **10. Map**

```go
m := make(map[string]int)
m["age"] = 25
fmt.Println(m["age"])
```

#### **11. 函数**

```go
func add(x, y int) int {
    return x + y
}
```

* 多返回值：`func swap(a, b int) (int, int)`

#### **12. 指针**

```go
var x int = 58
var p *int = &x
fmt.Println(*p)
```

#### **13. 包管理**

```go
import "fmt"
```

* `go mod init <module-name>`
* `go mod tidy`

#### **14. 结构体**

```go
type Person struct {
    Name string
    Age  int
}
```

#### **15. 方法 & 接口**

```go
type Circle struct { Radius float64 }
func (c Circle) Area() float64 { return 3.14 * c.Radius * c.Radius }
type Shape interface { Area() float64 }
```

#### **16. 错误处理**

```go
func divide(a, b int) (int, error) {
    if b == 0 {
        return 0, fmt.Errorf("division by zero")
    }
    return a / b, nil
}
```

—— **Go 语言基础速查笔记** ✅