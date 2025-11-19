#!/usr/bin/env python
import os
import sys

env = SConscript("thirdparty/godot-cpp/SConstruct")

env.Append(
    CPPDEFINES=[
        "LASSO_BUILD",
    ]
)

env.Prepend(CPPPATH=["thirdparty", "include"])
env.Append(CPPPATH=["src/"])

sources = [
    Glob("src/*.cpp"),
]

# Generate documentation from XML files (for editor and template builds)
if env["target"] in ["editor", "template_debug", "template_release"]:
    doc_data = env.GodotCPPDocData("src/gen/doc_data.gen.cpp", source=Glob("doc_classes/*.xml"))
    sources.append(doc_data)

# Disable 32 bit narrowing error.
if env["platform"] != "windows":
    env.Append(CCFLAGS=["-Wno-c++11-narrowing"])

if env["platform"] == "macos":
	library = env.SharedLibrary(
		"bin/addons/godot_lasso/bin/libgodot_lasso{}.framework/libgodot_lasso{}".format(
			env["suffix"], env["suffix"]
		),
		source=sources,
	)
elif env["platform"] == "ios":
	library = env.SharedLibrary(
		"bin/addons/godot_lasso/bin/libgodot_lasso{}.framework/libgodot_lasso{}".format(
			env["suffix"], env["suffix"]
		),
		source=sources,
	)
else:
	library = env.SharedLibrary(
		"bin/addons/godot_lasso/bin/libgodot_lasso{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
		source=sources,
	)
Default(library)

