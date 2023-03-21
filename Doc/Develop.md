# Develop

注意：不要向String::Write函数添加可变参数重载，因为其会与String::Write(const std::string& s, color r, color g, color b)发生冲突。

问题：暂时不知是否以及如何用宏实现C++的raw string。