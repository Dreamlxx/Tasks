package 1

import (
    "fmt"
    "io/ioutil"
    "net/http"
)

func main() {
    // 向服务器的根路径发送 GET 请求
    resp, err := http.Get("http://localhost:8080")
    if err != nil {
        // 如果请求过程中出现错误，打印错误信息
        fmt.Println("请求服务器时出错:", err)
        return
    }
    // 确保在函数结束时关闭响应体，避免资源泄漏
    defer resp.Body.Close()

    // 读取服务器响应的内容
    body, err := ioutil.ReadAll(resp.Body)
    if err != nil {
        // 如果读取响应内容时出现错误，打印错误信息
        fmt.Println("读取服务器响应时出错:", err)
        return
    }

    // 打印服务器的响应内容
    fmt.Println("服务器响应内容:", string(body))
}