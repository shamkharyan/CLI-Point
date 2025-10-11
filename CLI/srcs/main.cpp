#include "Tokenizer.h"
#include "AllCommands.h"

#include <iostream>
#include <optional>

int main()
{
    while (true)
    {
        std::optional<Command> cmd = Parser::parse(std::cin);
        cmd.execute();
    }


    //while (true)
    //{
    //    std::string command;

    //    std::cout << programName << "/> ";
    //    std::getline(std::cin, command);

    //    // std::vector<std::string> tokens = Tokenizer::tokenize(command);
    //    // std::optional<Command> cmd = Parser::parse(tokens);
    //    // if (cmd.has_value() && Analyzer::checkCmd(cmd.value()))
    //    //   cmd.value().execute();
    //    // else
    //    //   std::cout << "Wrong command\n";
    //}
    return 0;
}

