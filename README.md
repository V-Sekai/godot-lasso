# Godot Lasso

A GDExtension for Godot Engine providing lasso/selection tool functionality.

## Features

- Lasso tool for selecting and manipulating points using Voronoi-based selection
- Delaunay triangle refinement for precise object selection in VR
- Cross-platform support (Windows, macOS, Linux, iOS, Android, Web)
- Single and double precision float support
- Full documentation integrated into Godot editor

## Requirements

- SConstruct (if you want to build locally)
- Godot Engine 4.1 or later

## How to Build

```bash
scons target=template_release generate_bindings=no arch=universal precision=single
```

## Installation

1. Download the latest release from GitHub
2. Copy the `addons/godot_lasso` folder to your Godot project
3. Restart the Godot editor

## Usage

Add a `LassoTool` node to your scene and use it to collect points for lasso selection.

```gdscript
var lasso = LassoTool.new()
lasso.add_point(Vector2(100, 100))
lasso.set_active(true)
var points = lasso.get_points()
```

## CI/CD

This project includes GitHub Actions workflows for:
- Automated building across all platforms
- Linting and code formatting
- Automatic release creation

## License

See LICENSE file for details.

