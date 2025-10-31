#include "cli/CLIController.h"
#include "model/PPModel.h"
#include "viewer/cli/CLIViewer.h"
#include "cli/utils/registerCommands.h"

#include <iostream>
using namespace ppt;

int main()
{
	viewer::cli::CLIViewer viewer(std::cin, std::cout);
	cli::CLIController controller(viewer);
	cli::registerCommands(viewer, controller);

	controller.run();

	return 0;
}

// create-presentation -> creates new presentation
//   [-n]   : string -> presentation name

// edit-presentation -> edits existing presentation
//   [-n] : string -> presentation name

// add-slide -> creates new slide
//   [-at] : pos integer -> insert index, by default appends from back
//   [-bg] : color       -> background color, by default is white

// edit-slide -> edits existing slide
//   [-at] : pos integer -> existing slide index, by default selected
//   [-bg] : color       -> new color

// move-slide -> moves existing slide to new position
//   [-at]  : pos integer -> existing slide index, by default selected slide
//   [-to] : pos integer -> new position

// remove-slide -> removes existing slide
//   [-at] : pos integer -> remove index, by default deletes selected

// add-shape -> add new shape in the slide
//   [-at]  : pos integer -> slide number, by default last slide
//   [-type]: shape       -> shape type (rectangle, circle, triangle), by default rectangle
//   [-c]   : coord       -> top left corner of bounding box, by default [0,0]
//   [-w]   : pos integer -> shape width, by default 100
//   [-h]   : pos integer -> shape height, by default 100
//   [-bg]  : color       -> background color of shape, by default is white
//   [-oc]  : color       -> outline color of shape, by default is black
//   [-ot]  : pos integer -> outline thickness of shape, be default is 1
//   [-t]   : string      -> text inside shape
//   [-tc]  : color       -> inline text color
//   [-tf]  : string      -> inline text font
//   [-ts]  : string      -> inline text style
//   [-tl]  : string      -> inline text link

// remove-shape -> remove shape from the slide
//   [-at] : pos integer -> shape number, by default last shape in slide

// edit-shape -> edit existing shape
//   -id    : pos integer -> shape if
//   [-type]: shape       -> shape type (rectangle, circle, line, arrow)
//   [-c]   : coord       -> top left corner of bounding box
//   [-w]   : pos integer -> shape width
//   [-h]   : pos integer -> shape height
//   [-pos] : pos integer -> position in the slide
//   [-bg]  : color       -> background color of shape, by default is white
//   [-oc]  : color       -> outline color of shape, by default is black
//   [-ot]  : pos integer -> outline thickness of shape, be default is 1
//   [-t]   : string      -> text inside shape
//   [-tc]  : color       -> inline text color
//   [-tf]  : string      -> inline text font
//   [-ts]  : string      -> inline text style
//   [-tl]  : string      -> inline text link

// help -> print manual

// close -> closes current project
//   [-f] : null -> force close

// exit -> closes the program
//   [-f] : null -> force exit

// save -> saves the current project as JSON file
//   [-path] : string -> save path

// export -> exports the current project to images
//   [-path] : string -> export path

// open -> opens the project
//   -path : string -> path to the JSON file

// show -> shows the presentation
//   [-at] : pos int -> shows the slide

// next-slide -> next slide

// prev-slide -> prev slide

// goto-slide -> specified slide
//   -at : pos int -> position
