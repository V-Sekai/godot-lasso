#!/bin/bash
scons target=template_release generate_bindings=no arch=universal precision=single
rm -rf samples/godot_lasso/addons/godot_lasso/bin

