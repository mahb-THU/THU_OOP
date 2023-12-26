#pragma once

#include <vector>
#include <string>
#include <list>

class TextEditor {
private:
    using Position = std::pair<int, int>;
    Position cursorPos;
    Position choicePos_1;
    Position choicePos_2;
    bool choice;
    std::vector<std::string> data; // 数据区，亦可采用其他数据结构
    std::vector<std::string> clipboard; // 剪贴板，亦可采用其他数据结构
public:
    TextEditor();
    void moveCursor(Position dest);
    void select(Position beg, Position end);
    void write(const std::string& str);
    void newline();
    void del();
    void copy();
    void paste();
    void screenShot();
    void deleteSelection();
};