# Kingdom Hearts 2: Final Mix Decomp

![SLPM_666.75's progress](https://img.shields.io/endpoint?url=https://govanify.github.io/kh2/badges/main-elf.json)

This repo contains a (WIP) decompilation of Kingdom Hearts 2 Final Mix's main
ELF, nicknamed "dasein".

It builds the current executable: 

* SLPM\_666.75: sha256sum: `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`

## Setup

In order to work on this project, you will need to put SLPM\_666.75 at the root
of this repo. It can be found readily available in the ISO of the game as a
regular file.

You will also need some dependencies although not many, namely: python3, docker
and git lfs. This repository was also made in mind with a UNIX shell and has
been tested and known to work on Linux and macOS. Hopefully, it should work on
WSL (Windows) with minimal tinkering.

You need to run `git lfs pull` in order to retrieve the compiler's archive from
the repo before running `make`.

## Workflow

When you decompile a new function, add a reference to the function and any
symbols it uses in `functions.tsv`. 
You can then implement the function in any file present in the `src/` folder and
it will be picked up automatically.


Once your function(s) are drafted, run `make`. This will generate the required
files to use [objdiff](https://github.com/encounter/objdiff), an automated
diffing tool.

Open your project repository in it and, on the left sidebar, filter by
incomplete to show objects which are not fully matching yet. You can then edit
your source files and objdiff will automatically rebuild and show you the
updated percentage as you do.

You can also, optionally, upload an online scratch to decomp.me from the tool,
to work collaboratively on a function.


## Symbols and file layout

Symbols and file layout have been mostly recovered from the E3 kiosk demo PS3 port
of KH2. While there is obvious drift in the overall logic, this should be a good
resource in order to try to name functions yet unknown in this repository. I
_highly_ encourage you to inspire yourself from those debug symbols XREFs,
function layouts, vtables etc in order to try to recover as much of the original
layout as possible.

I already recovered class definitions and file layout from said ELF. 

There are two exceptions to that

* `src/anon` is not an original folder and is used as a
placeholder until the original symbol for the function is written down. A lot of
those functions were automatically generated through symbolic CFG traversal
analysis of gcc and as such may not be very idiomatic C++, but they should be all 
matching.

* `nonmatchings`: This folder is not rigged up at all in the build system and is
  mostly used as a dump of functions that aren't yet matching.
