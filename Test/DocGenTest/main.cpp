#define SYSTEM_STRING_CONSOLE
#include "String.hpp"
using namespace System;

#include <fstream>      //std::ifstream, std::ofstream
#include <vector>       //std::vector
#include <map>          //std::map
#include <algorithm>    //std::find

#ifndef INPUT_SINGLE_HEADER_FILE_PATH
#define INPUT_SINGLE_HEADER_FILE_PATH "../../String.hpp"
#endif

#ifndef OUTPUT_README_DOC_PATH
#define OUTPUT_README_DOC_PATH "../../Doc/README_AUTO.md"
#endif

#ifndef OUTPUT_NEW_LINE
#define OUTPUT_NEW_LINE "\n"
#endif

#ifndef MACRO_DEFINE
#define MACRO_DEFINE "#define"
#endif

void add_item(std::vector<std::string>& output_lines, const std::string& line, int level)
{
    std::string indent;
    for (int i = 0; i < level * 4; i++)
    {
        indent += " ";
    }
    output_lines.push_back(std::string(OUTPUT_NEW_LINE) + indent + std::string("1. ") + line);
}

bool handle(const std::vector<std::string>& input_lines, std::vector<std::string>& output_lines)
{
    std::vector<std::string> macro_names;
    for (int i = 0; i < input_lines.size(); i++)
    {
        std::string input_line = input_lines[i];
        input_line = StringA::Trim(input_line);
        if (StringA::StartsWith(input_line, MACRO_DEFINE))
        {
            //remove #define:
            std::string line = StringA::Substring(input_line, StringA::Length(MACRO_DEFINE));
            //trim:
            line = StringA::Trim(line);
            //remove comment:
            int commentIndex = StringA::IndexOf(line, "//");
            if (commentIndex != -1)
            {
                line = StringA::Substring(line, 0, commentIndex);
                line = StringA::Trim(line);
            }
            auto line_items = StringA::Split(line, " ");
            std::string macro_name = line_items[0];
            //Don't add duplicated macro_name:
            if (!std::count(macro_names.begin(), macro_names.end(), macro_name))
            {
                //Don't add empty:
                if (macro_name.empty()) continue;
                //Don't add macro_name starts with _:
                if (macro_name[0] == '_') continue;
                //Don't add UNICODE macro:
                if (macro_name == "UNICODE") continue;
                macro_names.push_back(macro_name);
            }
        }
    }
    //title:
    std::string title = StringA::Format("# {0} {1}.{2}.{3} Documentation - AutoGen", "String",
        SYSTEM_STRING_VERSION_MAJOR, SYSTEM_STRING_VERSION_MINOR, SYSTEM_STRING_VERSION_PATCH);
    output_lines.push_back(title);
    //main item:
    add_item(output_lines, "String.hpp", 0);
    //macro_names:
    for (int i = 0; i < macro_names.size(); i++)
    {
        add_item(output_lines, macro_names[i], 1);
    }
    return true;
}

int main()
{
    std::vector<std::string> input_lines;
    std::vector<std::string> output_lines;

    //open input:
    std::ifstream input_single_header_file;
    input_single_header_file.open(INPUT_SINGLE_HEADER_FILE_PATH);
    if (!input_single_header_file.is_open())
    {
        Console::WriteLine(U8("Can't open INPUT_SINGLE_HEADER_FILE_PATH."));
        return -1;
    }
    //readlines:
    std::string line;
    while (std::getline(input_single_header_file, line))
    {
        input_lines.push_back(line);
    }
    //close input:
    input_single_header_file.close();

    //handle:
    bool handle_success = handle(input_lines, output_lines);
    if (!handle_success)
    {
        Console::WriteLine(U8("Handle failed."));
        return -1;
    }

    //open output:
    std::ofstream output_readme_doc;
    output_readme_doc.open(OUTPUT_README_DOC_PATH);
    if (!output_readme_doc.is_open())
    {
        Console::WriteLine(U8("Can't create OUTPUT_README_DOC_PATH"));
        return -1;
    }
    //writelines:
    for (int i = 0; i < output_lines.size(); i++)
    {
        output_readme_doc << output_lines[i] << OUTPUT_NEW_LINE;
    }
    //close output:
    output_readme_doc.close();

    Console::WriteLine(U8("success"));
    return 0;
}