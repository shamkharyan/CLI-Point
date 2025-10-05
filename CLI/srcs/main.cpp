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

// create -> creates new project
//   [-name] : string -> project name

// add-slide -> creates new slide
//   [-at]      : pos integer -> insert index, by default appends from back
//   [-bgcolor] : color       -> background color, by default is white

// add-shape -> add new shape in the slide
//   -type       : shape       -> shape type (rectangle, circle, line, arrow)
//   -start      : coord       -> start coord for shape (top left corner for rect, center for circle)
//   -end        : coord       -> end coord for shape (optional for rect, wrong for circle)
//   -w          : pos integer -> shape width (wrong for circle and rect with -end option)
//   -h          : pos integer -> shape height (only for rect without -end option)
//   -r          : pos integer -> radius of the circle (only for circle)
//   [-bgcolor]  : color       -> background color of shape, by default is white
//   [-olcolor]  : color       -> outline color of shape, by default is black

// add-text -> add new text in the slide
//   -t       : string      -> text 
//   -start   : coord       -> start coord of the text
//   -size    : pos integer -> font size of the text
//   [-color] : color       -> color of the text
//   [-font]  : string      -> font of the text
//   [-style] : string      -> style of the text (bold, italic, underline, none)
//   [-link]  : string      -> link inside the text

// help -> print manual

// close -> closes current project

// quit -> closes the program

// move -> move the object
//   -id    : pos integer -> id of the movable object
//   -start : coord       -> new coord of the object
//   [-abs] : null        -> move by absolute coord system

// save -> saves the current project

// open -> opens the project
//   -name : string -> name of the project

// goto -> goes to the selected slide
//   -at : pos integer -> index of the slide

// delete -> deletes the selected object
//   -id : pos integer -> id of the deletable