#include "cli/CLIController.h"
#include "model/PPModel.h"
#include "viewer/cli/CLIViewer.h"
#include "cli/utils/registerCommands.h"

#include "CLIApplication.h"

#include <iostream>

int main(int argc, char *argv[])
{
	std::ignore = argc;
	std::ignore = argv;

	auto& app = ppt::CLIApplication::instance();

	return app.execute();
}

// add-slide -> creates new slide
//   [-a | --at]    : unsigned -> insert index, by default appends from back
//   [-c | --color] : color    -> background color, by default white
//   [-g | --goto]  : bool     -> on active goes to the added slide

// clear-slide -> clears the slide
//   [-a | --at] : unsigned -> slide index to clear

// duplicate-slide -> duplicates the existing slide
//   [-a | --at]   : unsigned -> which slide to duplicate, by default active slide
//   [-t | --to]   : unsigned -> where to duplicate slide, by default after active slide
//   [-g | --goto] : bool     -> on active goes to the added slide

// goto-slide -> changes the active slide
//   <-a | --at> : unsigned -> slide to position to make active

// duplicate-slide -> moves the existing slide to new position
//   [-a | --at]   : unsigned -> which slide to move, by default active slide
//   <-t | --to>   : unsigned -> where to move slide

// next-slide -> makes active next slide

// prev-slide -> makes active previous slide

// remove-slide -> removes existing slide
//   [-a | --at]   : unsigned -> which slide to remove, by default active slide

// set-slide-color -> change slide color
//   [-a | --at]    : unsigned -> which slide to recolor, by default active slide
//   <-c | --color> : color    -> new color

// add-shape -> creates new shape
//   [-t | --type]         : shapeType -> shape type, by default rectangle
//   [-p | --position]     : coord     -> left-up corner coords of shape, by default 0,0
//   [-s | --size]         : coord     -> width and height of shape, by default 0,0
//   [-a | --at]           : unsigned  -> where to create, by default active slide
//   [-c | --color]        : color     -> color of the shape, by default black
//   [--outline-color]     : color     -> outline color, by default red
//   [--outline-thickness] : unsigned  -> outline thickness, by default 1
//   [--text]              : string    -> text inside shape

// move-shape -> moves existing shape to the new position
//   <-i | --id>       : unsigned -> id of the shape
//   [-a | --at]       : unsigned -> index of the slide, by default active slide
//   <-p | --position> : coord    -> new position of the shape

// remove-shape -> removes existing shape
//   <-i | --id> : unsigned -> id of the shape
//   [-a | --at]       : unsigned -> index of the slide, by default active slide

// replace-shape -> changes existing shape type
//   <-i | --id>   : unsigned  -> id of the shape
//   [-a | --at]   : unsigned  -> index of the slide, by default active slide
//   <-t | --type> : shapeType -> new shape type

// resize-shape -> resizes existing shape
//   <-i | --id>       : unsigned -> id of the shape
//   [-a | --at]       : unsigned -> index of the slide, by default active slide
//   <-p | --position> : coord    -> new size of the shape

// exit -> closes the program
//   [-f | --force] : bool -> force exit

// list -> lists presentation (in development, but works)

// undo/redo

// help -> print manual (not done)

// A lot of command will be done in the future
