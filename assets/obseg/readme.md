# obseg Asset Readme

These assets consist of model and level information, and all text in the game.

There are eight categories (subfolders) of obseg assets included in source code. Visit each subfolder for a more detailed readme.

obseg asset categories are:

* `bg`
* `brief`
* `chr`
* `gun`
* `prop`
* `setup`
* `stan`
* `text`

## `bg` Assets
Level background geometry display lists and portal info.

## `brief` Assets
Contains mission briefing text.

## `chr` Assets
Character models display lists.

## `gun` Assets
On screen gun models display lists.

## `prop` Assets
Prop and item models display lists.

## `setup` Assets
Setups contain the mission scripting logic, AI Scripting, object information, Pad and Portal placement, guard paths and nav mesh. (see below for descriptions)

## `stan` Assets
Stand Tiles. Refereed to by Rare Staff as "stans" in GE or simply "Tiles" in PD. (see below for descriptions)

## `text` Assets
All other game text.

## Misc Assets
In the root of this folder is a file listing all of the assets included in the build, with path and filename info. This is used as runtime to resolve the list of available assets.

-----

# Concepts

# Room
A level is divided into rooms.

# Portal
A portal defines navigation from one room to another. Bond must travel through a portal for the objects in the room to be loaded (this isn't entirely correct, but travelling out of bonds is generally not useful for this reason).

# Pad
A room contains one or more pads.

# Path
Guard pathing information between pads.

# Nav mesh
Colleciton of paths.

# Set
Collection of pads, to aid in the algorithm to find the shortest path to Bond.

# Stan or Tiles
Defines floor clipping information.
