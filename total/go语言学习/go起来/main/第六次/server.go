package 0

import (
    "fmt"
    "net"
)

func main() {
    // 监听本地 8080 端口
    listener, err := net.Listen("tcp", "localhost:8080")
    if err != nil {
        fmt.Println("监听端口时出错:", err)
        return
    }
    // 程序结束时关闭监听
    defer listener.Close()
    fmt.Println("服务器正在监听 localhost:8080...")

    // 接受客户端连接
    conn, err := listener.Accept()
    if err != nil {
        fmt.Println("接受客户端连接时出错:", err)
        return
    }
    // 程序结束时关闭与客户端的连接
    defer conn.Close()

    // 读取客户端发送的数据
    buf := make([]byte, 1024)
    n, err := conn.Read(buf)
    if err != nil {
        fmt.Println("读取客户端数据时出错:", err)
        return
    }
    // 打印客户端发送的消息
    fmt.Println("收到客户端消息:", string(buf[:n]))

    // 向客户端发送响应
    response := "已收到你的消息！"
    _, err = conn.Write([]byte(response))
    if err != nil {
        fmt.Println("向客户端发送响应时出错:", err)
        return
    }
}