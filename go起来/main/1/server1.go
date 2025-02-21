package 1

import (
    "fmt"
    "net/http"
)

// 处理函数，当客户端请求根路径 "/" 时会调用该函数
func helloHandler(w http.ResponseWriter, r *http.Request) {
    // 向客户端发送响应内容
    fmt.Fprintf(w, "Hello, Client! 这是服务器的响应。")
}

func main() {
    // 注册处理函数，将根路径 "/" 与 helloHandler 函数关联起来
    http.HandleFunc("/", helloHandler)

    // 服务器监听本地的 8080 端口
    fmt.Println("服务器正在监听 :8080...")
    err := http.ListenAndServe(":8080", nil)
    if err != nil {
        // 如果监听过程中出现错误，打印错误信息
        fmt.Println("服务器启动失败:", err)
    }
}