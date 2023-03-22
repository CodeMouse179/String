# Develop

## 注意

1. 不要向String::Write函数添加可变参数重载，因为其会与String::Write(const std::string& s, color r, color g, color b)发生冲突。

## 问题

1. 暂时不知是否以及如何用宏实现C++的raw string。

1. 在String类内部，由于模板T参数的存在，T宏处于失效状态。