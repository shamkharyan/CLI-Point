# CLI-Point

A command-line interface (CLI) tool for creating, editing, and managing PowerPoint-like presentations directly from the terminal.

> ⚠️ **Note:** This project is under active development. Features may change, and some functionality is still being implemented.

---

## Table of Contents

* [Features](#features)
* [Installation](#installation)
* [Usage](#usage)
* [Commands](#commands)
* [Contributing](#contributing)
* [License](#license)

---

## Features

* Create new presentations and slides
* Add, remove, duplicate, and move slides
* Add, move, resize, and style shapes
* Manage shape properties: color, rotation, size, position, and text
* Undo and redo actions
* Export presentations (planned feature)

---

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/shamkharyan/cli-point.git
   ```
2. Open the solution file `PowerPoint.sln` in Visual Studio
3. Build the project (select **Debug** or **Release** configuration)
4. Run the executable from Visual Studio or from the build folder:

---

## Usage

Start the CLI and type commands:

```bash
# Create a new presentation
create-presentation -n MyPresentation

# Add slides
add-slide --color red
add-slide -c 200, 200, 200

# Add shapes
add-shape -t rectangle -p 100, 100 -s 200,100 --color 255 0 0
add-shape -t ellipse -p 50, 50 -s 100,100 --color 0 255 0

# Move and resize shapes
move-shape --id 0 --at 0 -p 150, 150
resize-shape --id 1 -a 0 --size 250, 150

# List slides
list
```

---

## Commands

### Presentation Commands

* `create-presentation [-n | --name] <string>`
  Creates a new presentation. Default name: `"Untitled"`

* `rename-presentation [-n | --name] <string>`
  Renames the current presentation

* `exit [-f | --force]`
  Closes the program, optionally forcing exit

* `undo`
  Undo the last action

* `redo`
  Redo the last undone action

* `list`
  Lists slides (in development, but works)

---

### Slide Commands

* `add-slide [-a | --at] <unsigned> [-c | --color] <color> [-g | --goto]`
  Creates a new slide. Optional insertion index, color (default white), and whether to go to the added slide

* `clear-slide [-a | --at] <unsigned>`
  Clears a slide

* `duplicate-slide [-a | --at] <unsigned> [-t | --to] <unsigned> [-g | --goto]`
  Duplicates a slide. Default: duplicate active slide to next position

* `move-slide [-a | --at] <unsigned> [-t | --to] <unsigned>`
  Moves an existing slide to a new position

* `remove-slide [-a | --at] <unsigned>`
  Removes an existing slide. Default: active slide

* `set-slide-color [-a | --at] <unsigned> [-c | --color] <color>`
  Sets background color of a slide. Default: active slide

* `goto-slide [-a | --at] <unsigned>`
  Changes the active slide

* `next-slide`
  Makes the next slide active

* `prev-slide`
  Makes the previous slide active

---

### Shape Commands

* `add-shape [-t | --type] <shapeType> [-p | --position] <coord> [-s | --size] <coord> [-a | --at] <unsigned> [-c | --color] <color> [--outline-color <color>] [--outline-thickness <unsigned>] [--text <string>]`
  Adds a shape to a slide. Defaults: rectangle, position `(0,0)`, size `(0,0)`, color black, outline red thickness 1

* `move-shape [-i | --id] <unsigned> [-a | --at] <unsigned> [-p | --position] <coord>`
  Moves an existing shape to a new position. Default slide: active

* `remove-shape [-i | --id] <unsigned> [-a | --at] <unsigned>`
  Removes an existing shape. Default slide: active

* `replace-shape [-i | --id] <unsigned> [-a | --at] <unsigned> [-t | --type] <shapeType>`
  Changes the type of an existing shape. Default slide: active

* `resize-shape [-i | --id] <unsigned> [-a | --at] <unsigned> [-s | --size] <coord>`
  Resizes an existing shape. Default slide: active

---

### Notes

* All shape IDs are unique **per slide**
* Many commands are still in active development; new features will be added regularly

---

## Contributing

1. Fork the repository
2. Create a branch: `git checkout -b feature-name`
3. Make your changes and commit: `git commit -m 'Add feature'`
4. Push to the branch: `git push origin feature-name`
5. Create a Pull Request

---

## License

MIT License – see [LICENSE](LICENSE) for details.

---

**Reminder:** This CLI tool is under active development. Expect new features, improvements, and changes in upcoming releases.
