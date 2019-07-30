package main
import "fmt"

// PersonInfo是一个包含个人详细信息的类型
type PersonInfo struct {
    ID string
    Name string
    Address string
}

func main() {
    var personDB map[string] PersonInfo
    presonDB = make(map[string] PersonInfo)

    // 插入数据
    personDB["1"] = PersonInfo{"123", "Tom", "Room 203,..."}
    personDB["a"] = PersonInfo{"abc", "Mon", "Team 302,..."}

    person, ok := personDB["1"]
    if ok {
        fmt.println("Found person", person.Name, person.ID, person.Address)
    } else {
        fmt.println("Not Found It")
    }
}
