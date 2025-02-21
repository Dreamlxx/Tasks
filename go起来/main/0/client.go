package 0

import (
    "fmt"
    "net"
)

func main() {
    // 连接到服务器
    conn, err := net.Dial("tcp", "localhost:8080")
    if err != nil {
        fmt.Println("连接服务器时出错:", err)
        return
    }
    // 程序结束时关闭连接
    defer conn.Close()

    // 要发送给服务器的消息
    message := "Hello, Server!"
    // 向服务器发送消息
    _, err = conn.Write([]byte(message))
    if err != nil {
        fmt.Println("发送消息给服务器时出错:", err)
        return
    }

    // 读取服务器的响应
    buf := make([]byte, 1024)
    n, err := conn.Read(buf)
    if err != nil {
        fmt.Println("读取服务器响应时出错:", err)
        return
    }
    // 打印服务器的响应
    fmt.Println("服务器响应:", string(buf[:n]))
}