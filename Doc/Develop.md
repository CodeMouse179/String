# Develop

## 注意

1. 不要向String::Write函数添加可变参数重载，因为其会与String::Write(const std::string& s, color r, color g, color b)发生冲突。

## TODO

1. 全面代码检查String.hpp

1. 对比C#的System.String的操作体验与C++的System.String的操作体验

1. 实现C语言中常用并且有价值的字符串处理函数

1. 研究Python与Lua的字符串操作函数，汲取灵感

1. 暂时不知是否以及如何用宏实现C++的raw string

1. 在String类内部，由于模板T参数的存在，T宏处于失效状态

1. GetTypeCode是类方法而不是普通方法(跟.Net的实现不一样)